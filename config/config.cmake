set(LINKFLAGS -nodefaultlibs)
set(LLDFLAGS --no-demangle --gc-sections)

set(OPTIMIZE_OPTIONS_DEBUG -O2 -gdwarf-4)
set(OPTIMIZE_OPTIONS_RELEASE -O3 -ffast-math -flto)
set(WARN_OPTIONS -Werror=return-type -Wno-invalid-offsetof -Wno-unqualified-std-cast-call)

set(INCLUDES include)

set(ASM_OPTIONS "")
set(C_OPTIONS -ffunction-sections -fdata-sections)
set(CXX_OPTIONS "")
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(IS_32_BIT FALSE)
set(HAKKUN_TARGET MODULE)

set(MODULE_NAME GrooveMod)
set(TITLE_ID 0x0100d9f01d474000)
set(MODULE_BINARY subsdk4)

set(TARGET_IS_STATIC FALSE)
set(SDK_PAST_1900 TRUE)

set(USE_ADVANCED_RESULT FALSE)
set(USE_SAIL TRUE)
set(BAKE_SYMBOLS FALSE)
set(TRAMPOLINE_LEVEL 1)

set(HAKKUN_ADDONS )
