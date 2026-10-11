// clang-format off
#include "../luag.h"

extern void SceneRing_Hoop(void *, void *, int);

luaG_nil_caller(scene_ring_hoop, SceneRing_Hoop(lua_touserdata(L, 1), lua_touserdata(L, 2), lua_tointeger(L, 3)));

void luaG_open_game_scene_ring(lua_State *L) {
#define REGISTER(name) luaG_register(L, "SceneRing", #name, scene_ring_##name)
  REGISTER(hoop);
#undef REGISTER
}
