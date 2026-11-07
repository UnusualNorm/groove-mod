#pragma once
#include "incomplete.hpp"
namespace game {
class IStage {
public:
  virtual void unknown00();
  virtual ~IStage();
  virtual void unknown18();
  virtual void unknown20();
  virtual void unknown28();
  virtual void unknown30();
  virtual void unknown38();
  virtual void unknown40();
  virtual void unknown48();
  virtual void unknown50();
  virtual void unknown58();
  virtual void unknown60();
  virtual void unknown68();
  virtual void unknown70();
  virtual void unknown78();
  virtual void unknown80();
  virtual void unknown88();
  char unknown[0x2970];
};
static_assert(sizeof(IStage) == 0x2978);
} // namespace game
