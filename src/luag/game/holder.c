// clang-format off
#include "../../game.h"
#include "../luag.h"

typedef struct {
  void (*destroy)(void *);
  void (*delete)(void *);
  void (*release)(void *);
  void *(*get)(void *);
} VTable;

luaG_nil_caller(holder_delete, (*(VTable **)lua_touserdata(L, 1))->delete(lua_touserdata(L, 1)));
luaG_nil_caller(holder_destroy, (*(VTable **)lua_touserdata(L, 1))->destroy(lua_touserdata(L, 1)));
luaG_ptr_caller(holder_get, (*(VTable **)lua_touserdata(L, 1))->get(lua_touserdata(L, 1)));
luaG_nil_caller(holder_release, (*(VTable **)lua_touserdata(L, 1))->release(lua_touserdata(L, 1)));

void luaG_open_game_holder(lua_State *L) {
#define REGISTER(name) luaG_register(L, "Holder", #name, holder_##name)
  REGISTER(delete);
  REGISTER(destroy);
  REGISTER(get);
  REGISTER(release);
#undef REGISTER
}
