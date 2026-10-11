// clang-format off
#include "../luag.h"

extern void *Anim_FindChild(void *, const char *, unsigned char);
extern unsigned char Anim_PlayAction(void *, const char *);

luaG_ptr_caller(anim_find_child, Anim_FindChild(lua_touserdata(L, 1), luaL_checkstring(L, 2), lua_toboolean(L, 3)));
luaG_bool_caller(anim_play_action, Anim_PlayAction(lua_touserdata(L, 1), luaL_checkstring(L, 2)));

void luaG_open_game_anim(lua_State *L) {
#define REGISTER(name) luaG_register(L, "Anim", #name, anim_##name)
  REGISTER(find_child);
  REGISTER(play_action);
#undef REGISTER
}
