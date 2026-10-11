#if defined(__cplusplus)
extern "C" {
#endif

#include <lauxlib.h>
#include <lua.h>
#include <lualib.h>

#define LUA_NOREF (-2)
#define LUA_REFNIL (-1)

extern void *luaG_alloc(void *ud, void *ptr, size_t osize, size_t nsize);
// extern int luaG_loadbuffer(lua_State *L, const char *s, size_t sz,
//                            const char *n);
// extern int luaG_loadstring(lua_State *L, const char *s);
extern lua_State *luaG_newstate(void);
// extern int luaG_ref(lua_State *L, int t);
// extern void luaG_unref(lua_State *L, int t, int ref);
extern void luaG_register(lua_State *L, const char *cn, const char *fn,
                          lua_CFunction f);
extern void luaG_logstring(lua_State *L, int idx);
extern const char *luaG_leakstring(lua_State *L, int idx);
extern int luaG_copyfunction(lua_State *src, lua_State *dst, int index);
extern void luaG_copytable(lua_State *src, lua_State *dst, int index);
extern void luaG_copyvalue(lua_State *src, lua_State *dst, int index);

extern void luaG_open_game_changer(lua_State *L);
extern void luaG_open_game_anim(lua_State *L);
extern void luaG_open_game_audio(lua_State *L);
extern void luaG_open_game_holder(lua_State *L);
extern void luaG_open_game_holder_custom(lua_State *L);
extern void luaG_open_game_ratings(lua_State *L);
extern void luaG_open_game_runner(lua_State *L);
extern void luaG_open_game_scene(lua_State *L);
extern void luaG_open_game_scene_parasol(lua_State *L);
extern void luaG_open_game_scene_flydisc(lua_State *L);
extern void luaG_open_game_scene_hungry(lua_State *L);
extern void luaG_open_game_scene_ring(lua_State *L);
extern void luaG_open_game_scene_rope(lua_State *L);
extern void luaG_open_game_stage(lua_State *L);
extern void luaG_open_game_stage_remix(lua_State *L);
extern void luaG_open_game_thread(lua_State *L);
extern void luaG_open_hk(lua_State *L);
extern void luaG_open_hk_diag(lua_State *L);

#define luaG_getter(name, ctype, offset, ltype)                                \
  static int name(lua_State *L) {                                              \
    lua_push##ltype(L, *(ctype *)((char *)lua_touserdata(L, 1) + offset));     \
    return 1;                                                                  \
  }
#define luaG_setter(name, ctype, offset, ltype)                                \
  static int name(lua_State *L) {                                              \
    *(ctype *)((char *)lua_touserdata(L, 1) + offset) =                        \
        (ctype)lua_to##ltype(L, 2);                                            \
    return 0;                                                                  \
  }
#define luaG_caller(name, ret, ...)                                            \
  static int name(lua_State *L) {                                              \
    __VA_ARGS__;                                                               \
    return ret;                                                                \
  }
#define luaG_custom_caller(name, ret, ...) luaG_caller(name, ret, __VA_ARGS__)
#define luaG_nil_caller(name, ...) luaG_caller(name, 0, __VA_ARGS__;)
#define luaG_ptr_caller(name, ...)                                             \
  luaG_caller(name, 1, {                                                       \
    void *ptr = __VA_ARGS__;                                                   \
    if (ptr)                                                                   \
      lua_pushlightuserdata(L, ptr);                                           \
    else                                                                       \
      lua_pushnil(L);                                                          \
  })
#define luaG_int_caller(name, ...)                                             \
  luaG_caller(name, 1, lua_pushinteger(L, __VA_ARGS__);)
#define luaG_num_caller(name, ...)                                             \
  luaG_caller(name, 1, lua_pushnumber(L, __VA_ARGS__);)
#define luaG_bool_caller(name, ...)                                            \
  luaG_caller(name, 1, lua_pushboolean(L, __VA_ARGS__);)

#define luaG_dobuffer(L, s, sz, n)                                             \
  (luaL_loadbuffer(L, s, sz, n) || lua_pcall(L, 0, LUA_MULTRET, 0))

#if defined(__cplusplus)
}
#endif
