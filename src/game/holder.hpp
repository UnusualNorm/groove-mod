#pragma once
#include "incomplete.hpp"
namespace game {
class Holder {
public:
  virtual ~Holder() = default;
  virtual void release() = 0;
  virtual Scene *get() = 0;
  char unknown[8];
};
static_assert(sizeof(Holder) == 0x10);
} // namespace game
