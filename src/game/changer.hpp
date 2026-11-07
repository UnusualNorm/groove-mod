#pragma once
#include "incomplete.hpp"
namespace game {
class Changer {
public:
  Changer(Stage *, Scene *);
  ~Changer();
  void changeInstant(Thread *, int);
  char unknown[0x3a68];
};
static_assert(sizeof(Changer) == 0x3a68);
} // namespace game
