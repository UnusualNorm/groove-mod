// clang-format off
#include "../luag.h"

extern void SceneParasol_Open(void *, void *, int, int, int, int);
extern void SceneParasol_OpenAll(void *, void *, int, int);

luaG_nil_caller(scene_parasol_open, SceneParasol_Open(lua_touserdata(L, 1), lua_touserdata(L, 2), lua_tointeger(L, 3), lua_tointeger(L, 4), lua_tointeger(L, 5), lua_tointeger(L, 6)));
luaG_nil_caller(scene_parasol_open_all, SceneParasol_OpenAll(lua_touserdata(L, 1), lua_touserdata(L, 2), lua_tointeger(L, 3), lua_tointeger(L, 4)));

void luaG_open_game_scene_parasol(lua_State *L) {
  luaG_register(L, "SceneParasol", "open", scene_parasol_open);
  luaG_register(L, "SceneParasol", "open_all", scene_parasol_open_all);
}
