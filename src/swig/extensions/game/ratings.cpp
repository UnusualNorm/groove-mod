#include "../../../luag/luag.h"
#include "../../extensions.hpp"
#include <cstring>

using namespace game;

static const char *get_string(lua_State *L, int index, const char *key,
                              size_t *len) {
  lua_getfield(L, index, key);
  const char *value = lua_tolstring(L, -1, len);
  lua_pop(L, 1);
  return value;
}

static int get_bool(lua_State *L, int index, const char *key) {
  lua_getfield(L, index, key);
  int value = lua_toboolean(L, -1);
  lua_pop(L, 1);
  return value;
}

static int get_int(lua_State *L, int index, const char *key) {
  lua_getfield(L, index, key);
  int value = lua_tointeger(L, -1);
  lua_pop(L, 1);
  return value;
}

Ratings *game_Ratings_newLua(LuaValue argument) {
  lua_State *L = argument.state;
  int index = lua_absindex(L, argument.index);
  luaL_checktype(L, index, LUA_TTABLE);

  size_t count = lua_rawlen(L, index);
  size_t names_size = 0;

  for (size_t i = 1; i <= count; ++i) {
    lua_rawgeti(L, index, i);
    luaL_checktype(L, -1, LUA_TTABLE);
    lua_getfield(L, -1, "name");

    size_t len;
    luaL_checklstring(L, -1, &len);
    names_size += len + 1;
    lua_pop(L, 2);
  }

  size_t ratings_size = (count + 1) * sizeof(Ratings);
  char *buffer = (char *)calloc(1, ratings_size + names_size);
  Ratings *ratings = (Ratings *)buffer;
  char *names = buffer + ratings_size;

  for (size_t i = 1; i <= count; ++i) {
    lua_rawgeti(L, index, i);
    int entry = lua_gettop(L);

    size_t len;
    const char *name = get_string(L, entry, "name", &len);
    memcpy(names, name, len);
    names[len] = '\0';

    Ratings *rating = &ratings[i - 1];
    rating->name = names;
    rating->usePercentageThresholds =
        get_bool(L, entry, "usePercentageThresholds");
    rating->deferPositiveComment = get_bool(L, entry, "deferPositiveComment");
    rating->countSlipsAsMisses = get_bool(L, entry, "countSlipsAsMisses");
    rating->suppressNonnegativeComment =
        get_bool(L, entry, "suppressNonnegativeComment");
    rating->suppressNonpositiveComment =
        get_bool(L, entry, "suppressNonpositiveComment");
    rating->positiveThreshold = get_int(L, entry, "positiveThreshold");
    rating->negativeThreshold = get_int(L, entry, "negativeThreshold");

    names += len + 1;
    lua_pop(L, 1);
  }

  return ratings;
}

void game_Ratings_deleteLua(lua_State *L, Ratings *ratings) {
  free(ratings);
  luaG_clearpointer(L, 1);
}
