// clang-format off
#include "../luag.h"

extern void Audio_Fade(float, void *, int);

luaG_nil_caller(audio_fade, Audio_Fade(lua_tonumber(L, 1), lua_touserdata(L, 2), lua_tointeger(L, 3)));

void luaG_open_game_audio(lua_State *L) {
#define REGISTER(name) luaG_register(L, "Audio", #name, audio_##name)
  REGISTER(fade);
#undef REGISTER
}
