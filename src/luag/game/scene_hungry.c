// clang-format off
#include "../luag.h"

extern void SceneHungry_SpawnFlower(void *, void *, int);

luaG_nil_caller(scene_hungry_spawn_flower, SceneHungry_SpawnFlower(lua_touserdata(L, 1), lua_touserdata(L, 2), lua_tointeger(L, 3)));

void luaG_open_game_scene_hungry(lua_State *L) {
#define REGISTER(name) luaG_register(L, "SceneHungry", #name, scene_hungry_##name)
  REGISTER(spawn_flower);
#undef REGISTER
}
