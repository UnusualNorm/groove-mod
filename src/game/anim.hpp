#pragma once
#include "incomplete.hpp"
namespace game {
class Anim {
public:
  Anim *findChild(const char *name, unsigned char recursive);
  bool playAction(const char *name);
};
} // namespace game
