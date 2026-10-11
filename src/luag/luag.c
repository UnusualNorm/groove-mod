#include "luag.h"
#include "../game.h"
#include "../utils.h"
#include "lauxlib.h"
#include "lualib.h"
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

lua_State *luaG_newstate(void) {
  lua_State *L = lua_newstate(luaG_alloc, NULL, 0);
  if (!L)
    return L;
  luaopen_base(L);
  luaG_open_game_anim(L);
  luaG_open_game_audio(L);
  luaG_open_game_changer(L);
  luaG_open_game_holder(L);
  luaG_open_game_holder_custom(L);
  luaG_open_game_ratings(L);
  luaG_open_game_runner(L);
  luaG_open_game_scene(L);
  luaG_open_game_scene_parasol(L);
  luaG_open_game_scene_flydisc(L);
  luaG_open_game_scene_hungry(L);
  luaG_open_game_scene_ring(L);
  luaG_open_game_scene_rope(L);
  luaG_open_game_stage(L);
  luaG_open_game_stage_remix(L);
  luaG_open_game_thread(L);
  luaG_open_hk(L);
  return L;
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
