include ../.Makefile.inc

SKULL_LIBS = \
	     -lfhash \
	     -lpcap

# output
STATIC_LIB = libfpcap_conv.a
DYNAMIC_LIB = libfpcap_conv.so

# Objs
OBJS = \
       fpcap_convert.o

# target rules
all: $(STATIC_LIB) $(DYNAMIC_LIB)

$(DYNAMIC_LIB): $(OBJS)
	$(SKULL_LD) -o $@ $^ $(SKULL_LIBS)

$(STATIC_LIB): $(OBJS)
	ar -rcs $@ $^

%.o: %.c
	$(SKULL_CC) -c $< -o $@

install:
	test -d $(prefix)/lib || mkdir -p $(prefix)/lib
	test -d $(prefix)/include/flibs || mkdir -p $(prefix)/include/flibs
	test -f $(STATIC_LIB) && cp $(STATIC_LIB) $(prefix)/lib
	test -f $(DYNAMIC_LIB) && cp $(DYNAMIC_LIB) $(prefix)/lib
	test -f fpcap_convert.h && cp fpcap_convert.h $(prefix)/include/skull

clean:
	rm -f $(STATIC_LIB) $(DYNAMIC_LIB) $(OBJS)

.PHONY: all clean install
