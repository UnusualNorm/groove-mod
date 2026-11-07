#include "../../../luag/luag.h"
#include "../../../utils.h"
#include "../../extensions.hpp"

using namespace game;
using namespace swig;
namespace {
struct LuaThreadState {
  lua_State *L;
  ~LuaThreadState() {
    if (L)
      lua_close(L);
  }
};

static void runLua(Thread *thread, void *argument) {
  auto *state = static_cast<LuaThreadState *>(argument);
  auto *L = state->L;
  luaG_pushpointer(L, thread, "game::Thread *");
  lua_setglobal(L, "thread");
  luaG_check(L, lua_pcall(L, 0, LUA_MULTRET, 0));
  lua_close(L);
  state->L = nullptr;
}

class LuaThread : public LuaThreadState, public Thread {
public:
  LuaThread(Runner *runner, int index, lua_State *L, Thread *parent)
      : LuaThreadState{L}, Thread(runner, index, runLua,
                                  static_cast<LuaThreadState *>(this), parent) {
  }
};
} // namespace

Thread *game_Thread_newLua(Runner *runner, int index, const char *name,
                           swig::LuaValue argument, Thread *parent) {
  char path[256];
  snprintf(path, sizeof(path), "sd:/groove/thread/%s.lua", name);

  long size;
  char *data = readFile(path, &size);
  if (!data)
    return nullptr;

  lua_State *L = luaG_newstate();
  if (!L) {
    free(data);
    return nullptr;
  }

  luaG_copyvalue(argument.state, L, argument.index);
  lua_setglobal(L, "argument");
  bool loaded = luaG_check(L, luaL_loadbuffer(L, data, size, name));
  free(data);

  if (!loaded) {
    lua_close(L);
    return nullptr;
  }

  return new LuaThread(runner, index, L, parent);
}
