#include "game.h"
#include "luag/luag.h"
#include "stages/lua.hpp"
#include "utils.h"
#include <cstdio>
#include <hk/hook/Trampoline.h>

extern "C" {
void *CSTAGE_SequenceCreator(void *, int, void *, unsigned int, int);
void *CSTAGE_SequenceStarter(void *, int, void *);
void *CSTAGE_StageCreator(unsigned int, void *, int, int, int, int, int);
}

using namespace game;

static HkTrampoline createStage = [](TrampolineStatic(), unsigned int id,
                                     Sequence *a, int b, int c, int d, int e,
                                     int f) -> void * {
  char name[32], path[256];
  snprintf(name, sizeof(name), "%u", id);
  snprintf(path, sizeof(path), "sd:/groove/stage/%u.lua", id);

  long size;
  char *data = readFile(path, &size);
  if (!data)
    return orig(id, a, b, c, d, e, f);

  defer { free(data); };
  return new StageLua(a, b, c, d, e, f, data, size, name);
};

static HkTrampoline startSequence = [](TrampolineStatic(), void *main, int id,
                                       void *context) -> void * {
  char path[256];
  snprintf(path, sizeof(path), "sd:/groove/stage/%u.lua",
           static_cast<unsigned int>(id));

  if (!fileExists(path))
    return orig(main, id, context);
  return CSTAGE_SequenceCreator(main, id, context, id, 0);
};

extern "C" bool CSTAGE_Install() {
  return !createStage.installAtPtr(CSTAGE_StageCreator).failed() &&
         !startSequence.installAtPtr(CSTAGE_SequenceStarter).failed();
}
