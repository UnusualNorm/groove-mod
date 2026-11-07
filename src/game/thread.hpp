#pragma once
#include "incomplete.hpp"
namespace game {
class UnknownThreadBase1 {
public:
  virtual ~UnknownThreadBase1();
  virtual void unknown10();
  virtual void unknown18();
  Thread *next;
  char unknown[8];
};

class UnknownThreadBase2 {
public:
  virtual ~UnknownThreadBase2();
};

class Thread : public UnknownThreadBase1, public UnknownThreadBase2 {
public:
  Thread(Runner *, int, void (*)(Thread *, void *), void *, Thread *);
  ~Thread() override;
  void unknown10() override;
  void unknown18() override;
  char unknown[0x234];
  int index;
  char unknown2[0x28];
  bool getStopRequested();
  void wait(int ticks);
};
static_assert(sizeof(Thread) == 0x280);
} // namespace game
