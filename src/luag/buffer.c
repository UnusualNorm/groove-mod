#include "../game.h"
#include "luag.h"
#include <string.h>

typedef struct luaG_Buffer {
  char *data;
  size_t size;
  size_t pos;
} luaG_Buffer;

const char *luaG_bufferreader(lua_State *L, void *ud, size_t *sz) {
  luaG_Buffer *buf = ud;
  if (buf->pos >= buf->size) {
    *sz = 0;
    return NULL;
  }

  *sz = buf->size - buf->pos;
  char *data = buf->data + buf->pos;
  buf->pos += *sz;
  return data;
}

int luaG_bufferwriter(lua_State *L, const void *p, size_t sz, void *ud) {
  luaG_Buffer *buf = ud;
  char *new_data = realloc(buf->data, buf->size + sz);
  if (!new_data)
    return 1;

  buf->data = new_data;
  memcpy(buf->data + buf->size, p, sz);
  buf->size += sz;
  return 0;
}

int luaG_loadbuffer(lua_State *L, const char *s, size_t sz, const char *n) {
  return lua_load(L, luaG_bufferreader,
                  &(luaG_Buffer){.data = (char *)s, .size = sz, .pos = 0}, n,
                  NULL);
}

int luaG_loadstring(lua_State *L, const char *s) {
  return luaG_loadbuffer(L, s, strlen(s), "string");
}

int luaG_copyfunction(lua_State *src, lua_State *dst, int index) {
  index = lua_absindex(src, index);
  if (!lua_isfunction(src, index))
    return LUA_ERRRUN;

  lua_pushvalue(src, index);
  luaG_Buffer buf = {0};
  if (lua_dump(src, luaG_bufferwriter, &buf, 0) != 0) {
    lua_pop(src, 1);
    free(buf.data);
    return LUA_ERRRUN;
  }

  lua_pop(src, 1);
  int status = luaG_loadbuffer(dst, buf.data, buf.size, "copied_function");
  free(buf.data);
  return status;
}
