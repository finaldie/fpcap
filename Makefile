all:
	cd src && make

dep: flibs

flibs:
	cd deps/final_libs && make SHARED=true

check: all
	cd tests && make $@

valgrind-check: all
	cd tests && make $@

install:
	cd src && make $@

clean:
	cd src && make $@

clean-dep: clean-flibs

clean-flibs:
	cd deps/final_libs && make clean

.PHONY: all check valgrind-check install clean dep flibs clean-dep clean-flibs
