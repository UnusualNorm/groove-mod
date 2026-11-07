#pragma once
#include "incomplete.hpp"
namespace game {
class Audio {
public:
  void fade(float volume, int ticks);
  char unknown[0x1b0];
};
static_assert(sizeof(Audio) == 0x1b0);
} // namespace game
