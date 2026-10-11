// clang-format off
#include "../luag.h"

extern void SceneRope_DoubleUnder(void *, void *, int, unsigned int, unsigned int);
extern void SceneRope_Jump(void *, void *, int, unsigned int);

luaG_nil_caller(scene_rope_double_under, SceneRope_DoubleUnder(lua_touserdata(L, 1), lua_touserdata(L, 2), lua_tointeger(L, 3), lua_toboolean(L, 4), lua_toboolean(L, 5)));
luaG_nil_caller(scene_rope_jump, SceneRope_Jump(lua_touserdata(L, 1), lua_touserdata(L, 2), lua_tointeger(L, 3), lua_toboolean(L, 4)));

void luaG_open_game_scene_rope(lua_State *L) {
#define REGISTER(name) luaG_register(L, "SceneRope", #name, scene_rope_##name)
  REGISTER(double_under);
  REGISTER(jump);
#undef REGISTER
}
