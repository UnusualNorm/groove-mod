#include <hk/diag/diag.h>
#include <nn/fs/fs_Mount.h>

extern "C" bool CSOUND_Install();
extern "C" bool CSTAGE_Install();
extern "C" void hkMain() {
  if (nn::fs::MountSdCard("sd").IsFailure())
    hk::diag::logLine("Failed to mount SD card...");
  else if (!CSOUND_Install())
    hk::diag::logLine("Failed to install custom sound...");
  else if (!CSTAGE_Install())
    hk::diag::logLine("Failed to install custom stage...");
  return;
}
