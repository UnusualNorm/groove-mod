#pragma once
#include "incomplete.hpp"
#include "istage.hpp"
namespace game {
class UnknownStageBase1 {
public:
  virtual ~UnknownStageBase1();
  Runner *runner;
  int sequenceId;
  char unknown[4];
};
static_assert(sizeof(UnknownStageBase1) == 0x18);

class UnknownStageBase2 {
public:
  virtual ~UnknownStageBase2();
  Runner *runner;
  Stage *owner;
  int threadIndex;
  char unknown[4];
};
static_assert(sizeof(UnknownStageBase2) == 0x20);

class UnknownStageBase3 {
public:
  virtual ~UnknownStageBase3();
  char unknown[0x20];
};
static_assert(sizeof(UnknownStageBase3) == 0x28);

class Stage : public IStage,
              public UnknownStageBase1,
              public UnknownStageBase2,
              public UnknownStageBase3 {
public:
  ~Stage() override;
  void unknown28() override;
  void unknown30() override;
  void unknown40() override;
  void unknown48() override;
  void unknown58() override;
  void unknown70() override;
  virtual void unknown90() = 0;
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
  Sequence *getSequence();
  char unknown[0x288];
  void bopAnim(Thread *thread, int ticks, unsigned int mode, int argument);
  void disablePause();
  void enablePause();
  void endGameplay();
  void fadeScreen(int ticks, float alpha);
  void finishGameplaySession();
  void initGameplay(unsigned char mode);
  void initSm(unsigned int id, unsigned int mode);
  void prepareSm(unsigned int id);
  void setComment(const char *name);
  void setEpilogueAndRatings(const char *message, const char *graph,
                             Ratings *ratings, int mask, const char *name,
                             const char *from);
  void startGameplay();
  void toResults();
  void unk7100138d20();
  int waitAudioReady(Thread *thread, int ticks, unsigned int mode);
  void waitReady(Thread *thread, unsigned int mode, int ticks);
  void playBgm(float volume, float speed, Thread *thread, unsigned int id,
               int ticks, int mode);
};
static_assert(sizeof(Stage) == 0x2c60);
} // namespace game
