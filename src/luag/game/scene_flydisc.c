// clang-format off
#include "../luag.h"

extern void SceneFlydisc_ChangeBackground(void *, const char *);
extern void SceneFlydisc_SetBackground(void *, const char *);
extern void SceneFlydisc_SetCountState(void *, unsigned char, unsigned char);
extern void SceneFlydisc_ThrowDisc(void *, void *, int, int, int, unsigned char);

luaG_nil_caller(scene_flydisc_change_background, SceneFlydisc_ChangeBackground(lua_touserdata(L, 1), luaL_checkstring(L, 2)));
luaG_ptr_caller(scene_flydisc_get_anim, *(void **)((char *)lua_touserdata(L, 1) + 0x40b8));
luaG_ptr_caller(scene_flydisc_get_audio, (char *)lua_touserdata(L, 1) + 0x4128);
luaG_nil_caller(scene_flydisc_set_background, SceneFlydisc_SetBackground(lua_touserdata(L, 1), luaL_checkstring(L, 2)));
luaG_nil_caller(scene_flydisc_set_count_state, SceneFlydisc_SetCountState(lua_touserdata(L, 1), lua_toboolean(L, 2), lua_toboolean(L, 3)));
luaG_nil_caller(scene_flydisc_throw_disc, SceneFlydisc_ThrowDisc(lua_touserdata(L, 1), lua_touserdata(L, 2), lua_tointeger(L, 3), lua_tointeger(L, 4), lua_tointeger(L, 5), lua_toboolean(L, 6)));

void luaG_open_game_scene_flydisc(lua_State *L) {
#define REGISTER(name) luaG_register(L, "SceneFlydisc", #name, scene_flydisc_##name)
  REGISTER(change_background);
  REGISTER(get_anim);
  REGISTER(get_audio);
  REGISTER(set_background);
  REGISTER(set_count_state);
  REGISTER(throw_disc);
#undef REGISTER
}
