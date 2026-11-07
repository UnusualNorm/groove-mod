#pragma once

#if defined(__cplusplus)
#include "game/anim.hpp"
#include "game/audio.hpp"
#include "game/changer.hpp"
#include "game/global.hpp"
#include "game/holder.hpp"
#include "game/holder_custom.hpp"
#include "game/incomplete.hpp"
#include "game/istage.hpp"
#include "game/ratings.hpp"
#include "game/runner.hpp"
#include "game/scene.hpp"
#include "game/scene_basic.hpp"
#include "game/scene_flydisc.hpp"
#include "game/scene_hungry.hpp"
#include "game/scene_parasol.hpp"
#include "game/scene_ring.hpp"
#include "game/scene_rope.hpp"
#include "game/sequence.hpp"
#include "game/stage.hpp"
#include "game/stage_basic.hpp"
#include "game/stage_remix.hpp"
#include "game/thread.hpp"

extern "C" {
#endif

extern void __nnDetailNintendoSdkRuntimeObjectFile(void);
extern void __nnDetailNintendoSdkRuntimeObjectFileRefer(void);
extern void _fini(void);
extern int _init(void *ctx);
extern void *aligned_alloc(unsigned long, unsigned long);
extern void *calloc(unsigned long, unsigned long);
extern void *end;
extern void free(void *);
extern void *malloc(unsigned long);
extern void *nndetailRoGetRoDataEnd(void);
extern char *nndetailRoGetRoDataStart(void);
extern void nninitStartup(void);
extern void nnMain(void);
extern void _ZdlPv(void *);
extern void _ZdlPvm(void *, unsigned long);
extern void _ZdaPv(void *);
extern void _ZdaPvm(void *, unsigned long);
extern void *_Znwm(unsigned long);
extern void *_Znam(unsigned long);
extern void *realloc(void *, unsigned long);

#if defined(__cplusplus)
}
#endif
