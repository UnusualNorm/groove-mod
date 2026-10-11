#include <stdbool.h>

#if defined(__cplusplus)
extern "C" {
#endif

extern void __attribute__((weak)) hkLogSink(const char *msg, unsigned long len);
extern char *readFile(const char *path, long *size);
extern bool fileExists(const char *path);

#if defined(__cplusplus)
}
#endif
