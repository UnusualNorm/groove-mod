#include "luag.h"

int luaG_ref(lua_State *L, int t) {
  if (lua_isnil(L, -1)) {
    lua_pop(L, 1);
    return LUA_REFNIL;
  }

  lua_rawgeti(L, t, 0);
  int ref = (int)lua_tointeger(L, -1);
  lua_pop(L, 1);

  if (ref != 0) {
    lua_rawgeti(L, t, ref);
    lua_rawseti(L, t, 0);
  } else
    ref = (int)lua_rawlen(L, t) + 1;

  lua_rawseti(L, t, ref);
  return ref;
}

void luaG_unref(lua_State *L, int t, int ref) {
  if (ref < 0)
    return;

  lua_rawgeti(L, t, 0);
  lua_rawseti(L, t, ref);
  lua_pushinteger(L, ref);
  lua_rawseti(L, t, 0);
}
