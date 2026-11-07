#include "dir_iterator.hpp"
#include <hk/diag/diag.h>

using namespace hk::diag;
using namespace nn::fs;
using namespace utils;

// DirIterator

DirIterator::DirIterator(const char *path) {
  opened_ = OpenDirectory(&handle_, path, OpenDirectoryMode_All).IsSuccess();
  if (!opened_)
    logLine("Failed to open directory: %s", path);
}

DirIterator::~DirIterator() {
  if (opened_)
    CloseDirectory(handle_);
}

void DirIterator::next() {
  if (!opened_)
    return;

  int64_t count = 0;
  auto result = ReadDirectory(&count, &entry_, handle_, 1);

  if (result.IsFailure() || count == 0) {
    CloseDirectory(handle_);
    opened_ = false;
  }
}

DirIterator::Iterator DirIterator::begin() {
  next();
  return Iterator(opened_ ? this : nullptr);
}

DirIterator::Iterator DirIterator::end() { return Iterator(nullptr); }

// DirIterator::Iterator

DirIterator::Iterator::Iterator(DirIterator *dir) : dir_(dir) {}

DirectoryEntry *DirIterator::Iterator::operator*() const {
  return &dir_->entry_;
}

DirIterator::Iterator &DirIterator::Iterator::operator++() {
  dir_->next();
  if (!dir_->opened_)
    dir_ = nullptr;
  return *this;
}

bool DirIterator::Iterator::operator!=(const Iterator &other) const {
  return dir_ != other.dir_;
}
