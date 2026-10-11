#include "../../game.h"
#include "../../utils.h"
#include "../luag.h"

extern unsigned int Thread_GetStopRequested(void *);
extern void Thread_New(void *, void *, int, void (*)(void *, void *), void *,
                       void *);
extern void Thread_Wait(void *, int);

typedef struct {
  lua_State *state;
  int ref;
} LuaSeqThreadArgs;

static void luaSeqThread(void *thread, void *argument) {
  lua_State *L = argument;

  lua_pushlightuserdata(L, thread);
  lua_setglobal(L, "thread");
  if (lua_pcall(L, 0, LUA_MULTRET, 0) != LUA_OK) {
    luaG_logstring(L, -1);
    lua_pop(L, 1);
  }

  lua_close(L);
}


luaG_bool_caller(thread_get_stop_requested, Thread_GetStopRequested(lua_touserdata(L, 1)));


luaG_custom_caller(thread_new, 1, {
  void *runner = lua_touserdata(L, 1);
  int index = lua_tointeger(L, 2);
  const char *name = lua_tostring(L, 3);
  void *parent = lua_touserdata(L, 5);

  char path[256];
  snprintf(path, sizeof(path), "sd:/groove/thread/%s.lua", name);

  long size;
  char *data = readFile(path, &size);
  if (!data) {
    lua_pushnil(L);
    return 1;
  }

  lua_State *L2 = luaG_newstate();
  luaG_copyvalue(L, L2, 4);
  lua_setglobal(L2, "argument");
  if (luaL_loadbuffer(L2, data, size, name) != LUA_OK) {
    luaG_logstring(L2, -1);
    lua_pop(L2, 1);
    lua_close(L2);

    free(data);
    lua_pushnil(L);
    return 1;
  } else
    free(data);

  void *thread = _Znwm(0x280);
  Thread_New(thread, runner, index, &luaSeqThread, L2, parent);
  lua_pushlightuserdata(L, thread);
});


luaG_nil_caller(thread_wait, Thread_Wait(lua_touserdata(L, 1), lua_tointeger(L, 2)));

void luaG_open_game_thread(lua_State *L) {
#define REGISTER(name) luaG_register(L, "Thread", #name, thread_##name)
  REGISTER(get_stop_requested);
  REGISTER(new);
  REGISTER(wait);
#undef REGISTER
}
