#pragma once
#include "incomplete.hpp"
namespace game {
class Runner {
public:
  virtual ~Runner();
  void appendThread(Thread *thread);
  Thread *threads;
  char unknown[0x60];
};
static_assert(sizeof(Runner) == 0x70);
} // namespace game
