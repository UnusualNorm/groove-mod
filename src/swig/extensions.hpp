#include "../game.h"
#include "./utils.hpp"

using namespace game;
using namespace swig;
Thread *game_Thread_newLua(Runner *runner, int index, const char *name,
                           LuaValue argument, Thread *parent);
Ratings *game_Ratings_newLua(LuaValue argument);
void game_Ratings_deleteLua(lua_State *L, Ratings *ratings);
