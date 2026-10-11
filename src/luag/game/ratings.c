// clang-format off
#include "../../game.h"
#include "../luag.h"
#include <string.h>

typedef struct {
  const char *name;
  int use_percentage_thresholds : 1;
  int defer_positive_comment : 1;
  int count_slips_as_misses : 1;
  int suppress_nonnegative_comment : 1;
  int suppress_nonpositive_comment : 1;
  int unused : 27;
  int positive_threshold;
  int negative_threshold;
  char padding[4];
} Rating;

static const char *get_string(lua_State *L, int index, const char *key, size_t * len) {
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

luaG_nil_caller(ratings_delete_custom, free(lua_touserdata(L, 1)));
luaG_ptr_caller(ratings_new_custom, ({
    int count = lua_gettop(L);
    size_t names_size = 0;
    for (int i = 1; i <= count; i++) {
        size_t len;
        get_string(L, i, "name", &len);
        names_size += len + 1;
    }

    size_t ratings_size = ((size_t)count + 1) * sizeof(Rating);
    size_t total_size = ratings_size + names_size;
    char *buffer = calloc(1, total_size);
    Rating *ratings = (Rating *)buffer;
    char *names = buffer + ratings_size;

    for (int i = 1; i <= count; i++) {
        size_t len;
        const char *name = get_string(L, i, "name", &len);
        memcpy(names, name, len);
        names[len] = '\0';

        Rating *rating = &ratings[i - 1];
        rating->name = names;
        rating->use_percentage_thresholds = get_bool(L, i, "use_percentage_thresholds");
        rating->defer_positive_comment = get_bool(L, i, "defer_positive_comment");
        rating->count_slips_as_misses = get_bool(L, i, "count_slips_as_misses");
        rating->suppress_nonnegative_comment = get_bool(L, i, "suppress_nonnegative_comment");
        rating->suppress_nonpositive_comment = get_bool(L, i, "suppress_nonpositive_comment");
        rating->positive_threshold = get_int(L, i, "positive_threshold");
        rating->negative_threshold = get_int(L, i, "negative_threshold");
        names += len + 1;
    }

    buffer;
}));

void luaG_open_game_ratings(lua_State *L) {
#define REGISTER(name)                                                         \
  luaG_register(L, "Ratings", #name, ratings_##name)
  REGISTER(delete_custom);
  REGISTER(new_custom);
#undef REGISTER
}
