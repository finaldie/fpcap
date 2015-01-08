debug ?= false
prefix ?= /usr/local

# compiling flags
STD = -std=c99
WARN = -Wall
EXTRA = -pedantic -Wpadded -Werror -Wextra -Wno-unused-parameter
EXTRA += -Wno-unused-function -Wfloat-equal -Winline -Wdisabled-optimization
#EXTRA += -Wconversion
OTHER = -pipe -g -ggdb3 -fPIC
SHARED = -shared
LDFLAGS += -Wl,-E
MACRO = -D_POSIX_C_SOURCE=200809L -D_BSD_SOURCE
INC = -I../deps/final_libs

ifeq ($(debug), false)
OPT = -O2
EXTRA += -fstack-protector
else
EXTRA += -fstack-protector-all
MACRO += -DSK_DEBUG -O0 -finstrument-functions
endif

# linking flags
DEPS_LDFLAGS = -L../deps/final_libs/final_libraries/lib -Wl,-rpath,$(prefix)/lib
SKULL_CFLAGS = $(CFLAGS) $(STD) $(WARN) $(EXTRA) $(MACRO) $(OPT) $(OTHER) $(INC)
SKULL_LDFLAGS = $(LDFLAGS) $(OPT) $(SHARED) $(OTHER) $(DEPS_LDFLAGS)

# CC and LD
SKULL_CC = $(CC) $(SKULL_CFLAGS)
SKULL_LD = $(CC) $(SKULL_LDFLAGS)
