#include "../luag/luag.h"
#include "../swig/game.hpp"
#include "../utils.h"
#include "lauxlib.h"
#include "lua.h"
#include "lualib.h"
#include <stdio.h>

extern "C" lua_State *luaG_newstate(void) {
  lua_State *L = lua_newstate(luaG_alloc, NULL, 0);
  if (!L)
    return L;
  luaG_openlib(L, LUA_GNAME, luaopen_base);
  luaG_openlib(L, LUA_TABLIBNAME, luaopen_table);
  luaopen_game(L);
  luaG_open_hk(L);
  return L;
}

extern "C" void luaG_pushpointer(lua_State *L, void *pointer,
                                 const char *name) {
  swig_type_info *type = SWIG_TypeQuery(name);
  if (!type) {
    luaL_error(L, "Invalid SWIG Type: %s", name);
    return;
  }

  SWIG_NewPointerObj(L, pointer, type, 0);
}

extern "C" void *luaG_topointer(lua_State *L, int index, const char *name) {
  void *pointer = nullptr;
  auto *type = SWIG_TypeQuery(name);
  if (!type || !SWIG_IsOK(SWIG_ConvertPtr(L, index, &pointer, type, 0)))
    luaL_error(L, "Expected SWIG Type: %s", name);
  return pointer;
}

extern "C" int luaG_copyuserdata(lua_State *src, lua_State *dst, int index) {
  index = lua_absindex(src, index);
  if (lua_type(src, index) != LUA_TUSERDATA ||
      lua_rawlen(src, index) != sizeof(swig_lua_userdata))
    return 0;

  auto *userdata = static_cast<swig_lua_userdata *>(lua_touserdata(src, index));
  bool known = false;
  for (auto **type = swig_types; *type; ++type)
    if (*type == userdata->type) {
      known = true;
      break;
    }
  if (!known)
    return 0;

  auto *type = SWIG_TypeQueryModule(SWIG_GetModule(dst), SWIG_GetModule(dst),
                                    userdata->type->name);
  if (!type)
    return 0;

  SWIG_NewPointerObj(dst, userdata->ptr, type, 0);
  return 1;
}

extern "C" void luaG_clearpointer(lua_State *L, int index) {
  if (lua_type(L, index) != LUA_TUSERDATA ||
      lua_rawlen(L, index) != sizeof(swig_lua_userdata))
    return;

  auto *userdata = static_cast<swig_lua_userdata *>(lua_touserdata(L, index));
  userdata->own = 0;
  userdata->ptr = nullptr;
}
