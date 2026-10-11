#include "game.h"
#include "luag/luag.h"
#include "utils.h"
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <hk/diag/diag.h>
#include <hk/hook/Trampoline.h>
#include <hk/util/Algorithm.h>

extern "C" {
void *CSTAGE_SequenceCreator(void *, int, void *, unsigned int, int);
void *CSTAGE_SequenceStarter(void *, int, void *);
void CSTAGE_StageConstructor(void *, void *, int, int, int, int, int);
void *CSTAGE_StageCreator(unsigned int, void *, int, int, int, int, int);
void CSTAGE_StageDestructor(void *);
extern std::uintptr_t *CSTAGE_StageVTable;
}

#define PTR_AT(a, b) (void *)((char *)a + (b))
#define STAGE_STATE_PTR(a) (lua_State **)PTR_AT(a, originalSize)
#define STAGE_STATE(a) *STAGE_STATE_PTR(a)

static constexpr std::size_t originalSize = 0x3550;
static constexpr std::size_t customSize = originalSize + sizeof(lua_State *);
static std::uintptr_t customVtable[49];

static void destroyRemix(void *stage) {
  lua_State *L = STAGE_STATE(stage);
  lua_getglobal(L, "Destroy");
  if (lua_pcall(L, 0, 0, 0) != LUA_OK) {
    luaG_logstring(L, -1);
    lua_pop(L, 1);
  }
  lua_close(L);

  CSTAGE_StageDestructor(stage);
  _ZdlPvm(stage, customSize);
}

static void *getScene(void *stage, int idx, unsigned int unk) {
  lua_State *L = STAGE_STATE(stage);
  lua_getglobal(L, "GetScene");
  lua_pushinteger(L, idx);
  lua_pushinteger(L, unk);
  if (lua_pcall(L, 2, 1, 0) != LUA_OK) {
    luaG_logstring(L, -1);
    lua_pop(L, 1);
    return nullptr;
  }

  void *holder = lua_touserdata(L, -1);
  lua_pop(L, 1);
  return holder;
}

static int getSceneCount(void *stage) {
  lua_State *L = STAGE_STATE(stage);
  lua_getglobal(L, "GetSceneCount");
  if (lua_pcall(L, 0, 1, 0) != LUA_OK) {
    luaG_logstring(L, -1);
    lua_pop(L, 1);
    return 0;
  }

  int count = lua_tointeger(L, -1);
  lua_pop(L, 1);
  return count;
}

static constexpr std::size_t sequenceInfoOffset = 0x2978;
static void destroyFromSequenceInfo(void *subobject) {
  destroyRemix(PTR_AT(subobject, -sequenceInfoOffset));
}

static constexpr std::size_t sequenceCallbackOffset = 0x2990;
static void destroyFromSequenceCallback(void *subobject) {
  destroyRemix(PTR_AT(subobject, -sequenceCallbackOffset));
}

static constexpr std::size_t stageCallbackOffset = 0x29B0;
static void destroyFromStageCallback(void *subobject) {
  destroyRemix(PTR_AT(subobject, -stageCallbackOffset));
}

static HkTrampoline createStage =
    [](TrampolineStatic(), unsigned int stageId, void *sequence, int arg3,
       int arg4, int arg5, int width, int height) -> void * {
  char name[32];
  snprintf(name, sizeof(name), "%u", stageId);
  char path[256];
  snprintf(path, sizeof(path), "sd:/groove/stage/%u.lua", stageId);

  long size;
  char *data = readFile(path, &size);
  if (!data)
    return orig(stageId, sequence, arg3, arg4, arg5, width, height);

  void *stage = _Znwm(customSize);
  CSTAGE_StageConstructor(stage, sequence, arg3, arg4, arg5, width, height);
  *(void **)PTR_AT(stage, 0) = PTR_AT(customVtable, 0x10);
  *(void **)PTR_AT(stage, sequenceInfoOffset) = PTR_AT(customVtable, 0x138);
  *(void **)PTR_AT(stage, sequenceCallbackOffset) = PTR_AT(customVtable, 0x158);
  *(void **)PTR_AT(stage, stageCallbackOffset) = PTR_AT(customVtable, 0x178);

  lua_State *L = luaG_newstate();
  lua_pushlightuserdata(L, stage);
  lua_setglobal(L, "stage");
  if (luaG_dobuffer(L, data, size, name) != LUA_OK) {
    luaG_logstring(L, -1);
    lua_pop(L, 1);
  }
  *STAGE_STATE_PTR(stage) = L;
  return stage;
};

static HkTrampoline startSequence = [](TrampolineStatic(), void *sequenceMain,
                                       int sequenceId,
                                       void *context) -> void * {
  char path[256];
  snprintf(path, sizeof(path), "sd:/groove/stage/%u.lua", sequenceId);
  if (!fileExists(path))
    return orig(sequenceMain, sequenceId, context);
  return CSTAGE_SequenceCreator(sequenceMain, sequenceId, context, sequenceId,
                                0);
};

extern "C" bool CSTAGE_Install() {
  for (std::size_t i = 0; i < hk::util::arraySize(customVtable); ++i)
    customVtable[i] = CSTAGE_StageVTable[i];
  customVtable[4] = (std::uintptr_t)&destroyRemix;
  customVtable[32] = (std::uintptr_t)&getScene;
  customVtable[33] = (std::uintptr_t)&getSceneCount;
  customVtable[40] = (std::uintptr_t)&destroyFromSequenceInfo;
  customVtable[44] = (std::uintptr_t)&destroyFromSequenceCallback;
  customVtable[48] = (std::uintptr_t)&destroyFromStageCallback;
  if (createStage.installAtPtr(CSTAGE_StageCreator).failed())
    return false;
  return !startSequence.installAtPtr(CSTAGE_SequenceStarter).failed();
}
