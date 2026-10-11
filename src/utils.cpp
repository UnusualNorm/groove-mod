#include "utils.h"
#include "game.h"
#include <cstring>
#include <nn/fs/fs_Files.h>

extern "C" char *readFile(const char *path, long *size) {
  nn::fs::FileHandle file{};
  if (nn::fs::OpenFile(&file, path, nn::fs::OpenMode_Read).IsFailure())
    return nullptr;

  long file_size = 0;
  if (nn::fs::GetFileSize(&file_size, file).IsFailure()) {
    nn::fs::CloseFile(file);
    return nullptr;
  }

  char *data = (char *)malloc(file_size + 1);
  memset(data, 0, file_size + 1);
  if (nn::fs::ReadFile(file, 0, data, file_size).IsFailure()) {
    free(data);
    nn::fs::CloseFile(file);
    return nullptr;
  }

  if (size)
    *size = file_size;
  nn::fs::CloseFile(file);
  return data;
}

extern "C" bool fileExists(const char *path) {
  nn::fs::FileHandle file{};
  if (nn::fs::OpenFile(&file, path, nn::fs::OpenMode_Read).IsFailure())
    return false;
  nn::fs::CloseFile(file);
  return true;
}
