#include "lua.hpp"

StageLua::StageLua(game::Sequence *a, int b, int c, int d, int e, int f,
                   char *buff, long size, const char *name)
    : StageRemix(a, b, c, d, e, f), L(luaG_newstate()) {
  luaG_pushpointer(L, this, "game::StageRemix *");
  lua_setglobal(L, "stage");
  luaG_check(L, luaG_dobuffer(L, buff, size, name));
}

StageLua::~StageLua() {
  lua_getglobal(L, "Destroy");
  luaG_check(L, lua_pcall(L, 0, 0, 0));
  lua_close(L);
}

game::Holder *StageLua::getScene(int index, unsigned int argument) {
  lua_getglobal(L, "GetScene");
  lua_pushinteger(L, index);
  lua_pushinteger(L, argument);
  if (!luaG_check(L, lua_pcall(L, 2, 1, 0)))
    return nullptr;

  auto *holder =
      static_cast<game::Holder *>(luaG_topointer(L, -1, "game::Holder *"));
  lua_pop(L, 1);
  return holder;
}

int StageLua::getSceneCount() {
  lua_getglobal(L, "GetSceneCount");
  if (!luaG_check(L, lua_pcall(L, 0, 1, 0)))
    return 0;

  int count = lua_tointeger(L, -1);
  lua_pop(L, 1);
  return count;
}
