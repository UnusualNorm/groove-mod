#if defined(__cplusplus)
extern "C" {
#endif

#include <lauxlib.h>
#include <lua.h>
#include <lualib.h>

#define LUA_NOREF (-2)
#define LUA_REFNIL (-1)

extern void *luaG_alloc(void *ud, void *ptr, size_t osize, size_t nsize);
extern lua_State *luaG_newstate(void);
extern void luaG_register(lua_State *L, const char *cn, const char *fn,
                          lua_CFunction f);
extern void luaG_logstring(lua_State *L, int idx);
extern const char *luaG_leakstring(lua_State *L, int idx);
extern void luaG_pushpointer(lua_State *, void *, const char *);
extern void *luaG_topointer(lua_State *, int, const char *);
extern void luaG_clearpointer(lua_State *, int);
extern int luaG_copyuserdata(lua_State *, lua_State *, int);
extern void luaG_copytable(lua_State *src, lua_State *dst, int index);
extern void luaG_copyvalue(lua_State *src, lua_State *dst, int index);
extern unsigned int luaG_check(lua_State *L, int status);
extern void luaG_openlib(lua_State *L, const char *name, lua_CFunction func);

extern void luaG_open_hk(lua_State *L);
extern void luaG_open_hk_diag(lua_State *L);

#define luaG_dobuffer(L, s, sz, n)                                             \
  (luaL_loadbuffer(L, s, sz, n) || lua_pcall(L, 0, LUA_MULTRET, 0))

#if defined(__cplusplus)
}
#endif
