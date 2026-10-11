#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <hk/diag/diag.h>
#include <hk/hook/InstrUtil.h>
#include <hk/hook/Trampoline.h>
#include <hk/util/Algorithm.h>
#include <nn/fs.h>

extern "C" {
extern void CSOUND_Initializer();
extern void CSOUND_LoadWavMark(int, const char *);
extern std::uint32_t CSOUND_PathFormatCall1;
extern std::uint32_t CSOUND_PathFormatCall2;
extern char *CSOUND_PathSanitizer(char *, const char *, int);
extern void *CSOUND_Registry;
}

static constexpr std::size_t templateId = 93;
static constexpr std::size_t entrySize = 16;
static constexpr std::size_t originalCount = 2209;
static constexpr std::size_t customCount = originalCount * 2;
static char customRegistry[customCount * entrySize]{};

static int formatPath(char *destination, std::size_t capacity,
                      const char *format, const char *directory,
                      const char *entryPath) {
  if (std::strncmp(entryPath, "sd:/", 4) == 0)
    return std::snprintf(destination, capacity, "%s", entryPath);
  return std::snprintf(destination, capacity, format, directory, entryPath);
}

static char *getFullPath(const char *dir, const char *file) {
  char *path = (char *)malloc(strlen(dir) + strlen(file) + 1);
  std::sprintf(path, "%s%s", dir, file);
  return path;
}

static void registerSounds() {
  nn::fs::DirectoryHandle dir;
  const char *dirPath = "sd:/groove/sound/";
  if (nn::fs::OpenDirectory(&dir, dirPath, nn::fs::OpenDirectoryMode_File)
          .IsFailure()) {
    hk::diag::logLine("Failed to open sound directory...");
    return;
  }

  nn::fs::DirectoryEntry dirEntries[16];
  s64 dirEntryCount = 0;
  while (nn::fs::ReadDirectory(&dirEntryCount, dirEntries, dir,
                               hk::util::arraySize(dirEntries))
             .IsSuccess() &&
         dirEntryCount != 0) {
    for (s64 i = 0; i < dirEntryCount; ++i) {
      char *end;
      unsigned long id = strtoul(dirEntries[i].mName, &end, 10);
      if (strcmp(end, ".cwv") != 0 || id >= customCount) {
        hk::diag::logLine("Failed to register sound %s...",
                          dirEntries[i].mName);
        continue;
      }

      char *path = getFullPath(dirPath, dirEntries[i].mName);
      void *entry = (void *)((char *)customRegistry + id * entrySize);
      std::memcpy(entry, (char *)customRegistry + templateId * entrySize,
                  entrySize);
      *((const char **)entry) = path;
      hk::diag::logLine("Registered sound %lu! (%s)", id, path);
    }
  }
  nn::fs::CloseDirectory(dir);
}

static void registerWavmarks() {
  nn::fs::DirectoryHandle dir;
  const char *dirPath = "sd:/groove/wavmark/";
  if (nn::fs::OpenDirectory(&dir, dirPath, nn::fs::OpenDirectoryMode_File)
          .IsFailure()) {
    hk::diag::logLine("Failed to open wavmark directory...");
    return;
  }

  nn::fs::DirectoryEntry dirEntries[16];
  s64 dirEntryCount = 0;
  while (nn::fs::ReadDirectory(&dirEntryCount, dirEntries, dir,
                               hk::util::arraySize(dirEntries))
             .IsSuccess() &&
         dirEntryCount != 0) {
    for (s64 i = 0; i < dirEntryCount; ++i) {
      char *end;
      unsigned long id = strtoul(dirEntries[i].mName, &end, 10);
      if (strcmp(end, ".wmb") != 0 || id >= customCount) {
        hk::diag::logLine("Failed to register wavmark %s...",
                          dirEntries[i].mName);
        continue;
      }

      char *path = getFullPath(dirPath, dirEntries[i].mName);
      CSOUND_LoadWavMark(id, path);
      hk::diag::logLine("Registered wavmark %lu! (%s)", id, path);
      free(path);
    }
  }
  nn::fs::CloseDirectory(dir);
}

static HkTrampoline initialize = [](TrampolineStatic()) -> void {
  orig();
  std::memset(customRegistry, 0, sizeof(customRegistry));
  std::memcpy(customRegistry, CSOUND_Registry, originalCount * entrySize);
  CSOUND_Registry = customRegistry;
  registerSounds();
  registerWavmarks();
};

static HkTrampoline sanitizePath = [](TrampolineStatic(), char *destination,
                                      const char *source,
                                      int partition) -> char * {
  if (strncmp(source, "sd:/", 4) == 0)
    return strncpy(destination, source, 260);
  else
    return orig(destination, source, partition);
};

extern "C" bool CSOUND_Install() {
  return sanitizePath.installAtPtr(CSOUND_PathSanitizer).succeeded() &&
         initialize.installAtPtr(CSOUND_Initializer).succeeded() &&
         hk::hook::writeBranchLinkAtPtr(ptr(&CSOUND_PathFormatCall1),
                                        &formatPath)
             .succeeded() &&
         hk::hook::writeBranchLinkAtPtr(ptr(&CSOUND_PathFormatCall2),
                                        &formatPath)
             .succeeded();
}
