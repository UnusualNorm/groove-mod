#include <nn/fs.h>

using namespace nn::fs;
namespace utils {
class DirIterator {
  DirectoryHandle handle_;
  DirectoryEntry entry_;
  bool opened_;
  void next();

public:
  explicit DirIterator(const char *path);
  ~DirIterator();

  DirIterator(const DirIterator &) = delete;
  DirIterator &operator=(const DirIterator &) = delete;

  class Iterator {
    DirIterator *dir_;

  public:
    explicit Iterator(DirIterator *dir);
    DirectoryEntry *operator*() const;
    Iterator &operator++();
    bool operator!=(const Iterator &other) const;
  };

  Iterator begin();
  Iterator end();
};
} // namespace utils
