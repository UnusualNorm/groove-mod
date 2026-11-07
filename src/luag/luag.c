#include "luag.h"
#include "../game.h"
#include "../utils.h"
#include "lauxlib.h"
#include <stdio.h>

FILE *const stdout = NULL;
FILE *const stdin = NULL;

void *luaG_alloc(void *ud, void *ptr, size_t osize, size_t nsize) {
  if (nsize == 0) {
    free(ptr);
    return NULL;
  } else
    return realloc(ptr, nsize);
}

void luaG_register(lua_State *L, const char *cn, const char *fn,
                   lua_CFunction f) {
  lua_getglobal(L, cn);
  if (lua_isnil(L, -1)) {
    lua_pop(L, 1);
    lua_newtable(L);
    lua_setglobal(L, cn);
    lua_getglobal(L, cn);
  }

  lua_pushcfunction(L, f);
  lua_setfield(L, -2, fn);
}

void luaG_logstring(lua_State *L, int idx) {
  size_t len;
  const char *msg = lua_tolstring(L, idx, &len);
  hkLogSink(msg, len);
}

const char *luaG_leakstring(lua_State *L, int idx) {
  const char *str = luaL_checkstring(L, idx);
  lua_pushvalue(L, idx);
  luaL_ref(L, LUA_REGISTRYINDEX);
  return str;
}

unsigned int luaG_check(lua_State *L, int status) {
  if (status == LUA_OK)
    return true;
  luaG_logstring(L, -1);
  lua_pop(L, 1);
  return false;
}

void luaG_openlib(lua_State *L, const char *name, lua_CFunction func) {
  luaL_requiref(L, name, func, 1);
  lua_pop(L, 1);
}
