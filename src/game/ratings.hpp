#pragma once
#include "incomplete.hpp"
namespace game {
struct Ratings {
  const char *name;
  unsigned int usePercentageThresholds : 1;
  unsigned int deferPositiveComment : 1;
  unsigned int countSlipsAsMisses : 1;
  unsigned int suppressNonnegativeComment : 1;
  unsigned int suppressNonpositiveComment : 1;
  unsigned int unknown : 27;
  int positiveThreshold, negativeThreshold;
  char unknown2[4];
};
static_assert(sizeof(Ratings) == 0x18);
} // namespace game
