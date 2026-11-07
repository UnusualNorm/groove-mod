#pragma once
#include "incomplete.hpp"
#include "stage.hpp"
namespace game {
class UnknownSceneBase1 {
public:
  virtual ~UnknownSceneBase1();
  virtual void unknown10();
  virtual void unknown18();
  char unknown[0x30];
};
static_assert(sizeof(UnknownSceneBase1) == 0x38);

class UnknownSceneBase2 {
public:
  virtual ~UnknownSceneBase2();
  Runner *runner;
  int sequenceInfoId;
  char unknown[4];
};
static_assert(sizeof(UnknownSceneBase2) == 0x18);

class UnknownSceneBase3 {
public:
  virtual ~UnknownSceneBase3();
  Runner *runner;
  Scene *owner;
  int threadIndex;
  char unknown[4];
};
static_assert(sizeof(UnknownSceneBase3) == 0x20);

class UnknownSceneBase4 {
public:
  virtual ~UnknownSceneBase4();
  char unknown[0x20];
};
static_assert(sizeof(UnknownSceneBase4) == 0x28);

class UnknownSceneBase5 {
public:
  virtual void unknown();
};
static_assert(sizeof(UnknownSceneBase5) == 8);

class UnknownSceneBase6 {
public:
  virtual ~UnknownSceneBase6();
  char unknown[8];
};
static_assert(sizeof(UnknownSceneBase6) == 0x10);

class Scene : public IStage,
              public UnknownSceneBase1,
              public UnknownSceneBase2,
              public UnknownSceneBase3,
              public UnknownSceneBase4,
              public UnknownSceneBase5,
              public UnknownSceneBase6 {
public:
  ~Scene() override;
  void unknown00() override;
  void unknown28() override;
  void unknown30() override;
  void unknown40() override;
  void unknown48() override;
  void unknown58() override;
  void unknown60() override;
  void unknown68() override;
  void unknown70() override;
  virtual void unknown90();
  virtual void unknown98();
  virtual void unknownA0();
  virtual void unknownA8();
  virtual void unknownB0();
  virtual void unknownB8();
  virtual void unknownC0();
  virtual void unknownC8();
  virtual void unknownD0();
  virtual void unknownD8();
  virtual void unknownE0();
  virtual void unknownE8();
  virtual void unknownF0();
  virtual void unknownF8();
  virtual void unknown100();
  virtual void unknown108();
  virtual void unknown110();
  virtual void unknown118();
  virtual void unknown120();
  virtual void unknown128();
  virtual void unknown130();
  virtual void unknown138();
  char unknown1[8];
  Stage *stage;
  char unknown2[0xe48];
  void attachChild(Scene *child);
  void setActive(unsigned int active);
  void setInputEnabled(unsigned char enabled);
};
static_assert(sizeof(Scene) == 0x3880);
} // namespace game
