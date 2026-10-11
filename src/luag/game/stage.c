// clang-format off
#include "../luag.h"

extern void Stage_BopAnim(void *, void *, int, unsigned int, int);
extern void Stage_DisablePause(void *);
extern void Stage_EnablePause(void *);
extern void Stage_EndGameplay(void *);
extern void Stage_FadeScreen(void *, int, float);
extern void Stage_FinishGameplaySession(void *);
extern void Stage_InitGameplay(void *, unsigned char);
extern void Stage_InitSM(void *, unsigned int, unsigned int);
extern void Stage_PlayBgm(float, float, void *, void *, unsigned int, int, int);
extern void Stage_PrepareSM(void *, unsigned int);
extern void Stage_SetComment(void *, const char *);
extern void Stage_SetEpilogueAndRatings(void *, const char *, const char *, void *, int, const char *, const char *);
extern void Stage_StartGameplay(void *);
extern void Stage_ToResults(void *);
extern void Stage_Unknown138D20(void *);
extern int Stage_WaitAudioReady(void *, void *, int, unsigned int);
extern void Stage_WaitReady(void *, void *, unsigned int, int);

luaG_nil_caller(stage_bop_anim, Stage_BopAnim(lua_touserdata(L, 1), lua_touserdata(L, 2), lua_tointeger(L, 3), lua_tointeger(L, 4), lua_tointeger(L, 5)));
luaG_nil_caller(stage_disable_pause, Stage_DisablePause(lua_touserdata(L, 1)));
luaG_nil_caller(stage_enable_pause, Stage_EnablePause(lua_touserdata(L, 1)));
luaG_nil_caller(stage_end_gameplay, Stage_EndGameplay(lua_touserdata(L, 1)));
luaG_nil_caller(stage_fade_screen, Stage_FadeScreen(lua_touserdata(L, 1), lua_tointeger(L, 2), lua_tonumber(L, 3)));
luaG_nil_caller(stage_finish_gameplay_session, Stage_FinishGameplaySession(lua_touserdata(L, 1)));
luaG_getter(stage_get_render, void *, 0x34F0, lightuserdata);
luaG_getter(stage_get_runner, void *, 0x2998, lightuserdata);
luaG_getter(stage_get_thread_index, int, 0x29A8, integer);
luaG_nil_caller(stage_init_gameplay, Stage_InitGameplay(lua_touserdata(L, 1), lua_toboolean(L, 2)));
luaG_nil_caller(stage_init_sm, Stage_InitSM(lua_touserdata(L, 1), lua_tointeger(L, 2), lua_toboolean(L, 3)));
luaG_nil_caller(stage_play_bgm, Stage_PlayBgm(lua_tonumber(L, 1), lua_tonumber(L, 2), lua_touserdata(L, 3), lua_touserdata(L, 4), lua_tointeger(L, 5), lua_tointeger(L, 6), lua_tointeger(L, 7)));
luaG_nil_caller(stage_prepare_sm, Stage_PrepareSM(lua_touserdata(L, 1), lua_tointeger(L, 2)));
luaG_setter(stage_set_active_scene, void *, 0x34E8, userdata);
luaG_nil_caller(stage_set_comment, Stage_SetComment(lua_touserdata(L, 1), luaL_checkstring(L, 2)));
luaG_nil_caller(stage_set_epilogue_and_ratings, Stage_SetEpilogueAndRatings(lua_touserdata(L, 1), luaG_leakstring(L, 2), luaG_leakstring(L, 3), lua_touserdata(L, 4), lua_tointeger(L, 5), luaG_leakstring(L, 6), luaG_leakstring(L, 7)));
luaG_nil_caller(stage_start_gameplay,Stage_StartGameplay(lua_touserdata(L, 1)));
luaG_nil_caller(stage_to_results, Stage_ToResults(lua_touserdata(L, 1)));
luaG_nil_caller(stage_unk_7100138d20, Stage_Unknown138D20(lua_touserdata(L, 1)));
luaG_nil_caller(stage_wait_audio_ready, Stage_WaitAudioReady(lua_touserdata(L, 1), lua_touserdata(L, 2), lua_tointeger(L, 3), lua_tointeger(L, 4)));
luaG_nil_caller(stage_wait_ready, Stage_WaitReady(lua_touserdata(L, 1), lua_touserdata(L, 2), lua_toboolean(L, 3), lua_tointeger(L, 4)));

void luaG_open_game_stage(lua_State *L) {
#define REGISTER(name) luaG_register(L, "Stage", #name, stage_##name)
  REGISTER(bop_anim);
  REGISTER(disable_pause);
  REGISTER(enable_pause);
  REGISTER(end_gameplay);
  REGISTER(fade_screen);
  REGISTER(finish_gameplay_session);
  REGISTER(get_render);
  REGISTER(get_runner);
  REGISTER(get_thread_index);
  REGISTER(init_gameplay);
  REGISTER(init_sm);
  REGISTER(play_bgm);
  REGISTER(prepare_sm);
  REGISTER(set_active_scene);
  REGISTER(set_comment);
  REGISTER(set_epilogue_and_ratings);
  REGISTER(start_gameplay);
  REGISTER(to_results);
  REGISTER(unk_7100138d20);
  REGISTER(wait_audio_ready);
  REGISTER(wait_ready);
#undef REGISTER
}
