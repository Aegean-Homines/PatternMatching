GCC=g++
PRG=gcc.exe
GCCFLAGS=-Wall -Wextra -ansi -Wold-style-cast -Woverloaded-virtual -Wsign-promo  -Wctor-dtor-privacy -Wnon-virtual-dtor -Wreorder -pedantic -std=c++11
GCCOPTIMIZE=-O3
DRMEM_GCCFLAGS=-m32 -g -fno-inline -fno-omit-frame-pointer


MSC=cl
MSCFLAGS=                 /EHa      /MDd /W4 /Za /Zc:forScope /nologo /D_CRT_SECURE_NO_DEPRECATE
MSCFLAGSOPTIMIZED=/O2 /GL /EHsc /Za /MD  /W4 /Za /Zc:forScope /nologo /D_CRT_SECURE_NO_DEPRECATE /D"_SECURE_SCL 0"

VALGRIND_OPTIONS=-q --leak-check=full
DIFF_OPTIONS=-y --strip-trailing-cr --suppress-common-lines

OBJECTS0= # everything is templatized
DRIVER0=driver.cpp
MSCDEFINE=
DEFINE=

OSTYPE := $(shell uname)
ifeq ($(OSTYPE),$(filter $(OSTYPE),Linux Darwin))
CYGWIN=
else
CYGWIN=-Wl,--enable-auto-import
endif

gcc0:
	$(GCC) -o $(PRG) $(CYGWIN) $(DRIVER0) $(OBJECTS0) $(GCCFLAGS) $(GCCOPTIMIZE) $(DEFINE)
msc0:
	$(MSC) /Fe$@.exe $(DRIVER0) $(OBJECTS0) $(MSCFLAGS) $(MSCDEFINE)
#testing memory
drmem:
	$(GCC) -o $@.exe $(DRIVER0) $(OBJECTS0) $(DRMEM_GCCFLAGS)
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16:
	echo "running test$@"
	./$(PRG) $@ >studentout$@
	diff out$@ studentout$@ $(DIFF_OPTIONS) > difference$@
mem0 mem1 mem2 mem3 mem4 mem5 mem6 mem7 mem8 mem9 mem10 mem11 mem12 mem13 mem14 mem15 mem16:
	echo "running memory test $@"
	valgrind $(VALGRIND_OPTIONS) ./$(PRG) $(subst mem,,$@) 1>/dev/null 2>difference$@
clean:
	rm -f *.exe *.o *.obj *.tds *.exe.manifest
