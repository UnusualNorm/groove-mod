// clang-format off
#include "../luag.h"

extern void Runner_AppendThread(void *, void *);

luaG_nil_caller(runner_append_thread, Runner_AppendThread(lua_touserdata(L, 1), lua_touserdata(L, 2)));

void luaG_open_game_runner(lua_State *L) {
#define REGISTER(name) luaG_register(L, "Runner", #name, runner_##name)
  REGISTER(append_thread);
#undef REGISTER
}
