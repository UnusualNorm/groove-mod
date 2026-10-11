#include "luag.h"

void luaG_copytable(lua_State *src, lua_State *dst, int index) {
  index = lua_absindex(src, index);
  lua_newtable(dst);
  lua_pushnil(src);
  while (lua_next(src, index) != 0) {
    luaG_copyvalue(src, dst, -2);
    luaG_copyvalue(src, dst, -1);
    lua_settable(dst, -3);
    lua_pop(src, 1);
  }
}

void luaG_copyvalue(lua_State *src, lua_State *dst, int index) {
  switch (lua_type(src, index)) {
  case LUA_TNIL:
    lua_pushnil(dst);
    break;
  case LUA_TBOOLEAN:
    lua_pushboolean(dst, lua_toboolean(src, index));
    break;
  case LUA_TNUMBER:
    if (lua_isinteger(src, index))
      lua_pushinteger(dst, lua_tointeger(src, index));
    else
      lua_pushnumber(dst, lua_tonumber(src, index));
    break;
  case LUA_TSTRING: {
    size_t len;
    const char *s = lua_tolstring(src, index, &len);
    lua_pushlstring(dst, s, len);
    break;
  }
  case LUA_TTABLE:
    luaG_copytable(src, dst, index);
    break;
  case LUA_TLIGHTUSERDATA:
    lua_pushlightuserdata(dst, lua_touserdata(src, index));
    break;
  default:
    lua_pushnil(dst);
    break;
  }
}
