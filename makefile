#user configuration
_LIBSRC = math_flp.c
_LIBOBJ = math_flp.o
_LIBHEADER = math_flp.h
_LIBNAME = libMathFlp.a
_TEST = test_sqr_root_flp.c

#file structure to follow
IDIR = include
LDIR = lib
SRCDIR = src
SRCOBJDIR = src/obj
EXMDIR = examples

#compiler options
CC = gcc
CFLAGS = -I$(IDIR)

#create file paths
LIBSRC = $(patsubst %,$(SRCDIR)/%,$(_LIBSRC))
LIBOBJ = $(patsubst %,$(SRCOBJDIR)/%,$(_LIBOBJ))
DEPS = $(patsubst %,$(IDIR)/%,$(_LIBHEADER))
TEST = $(patsubst %,$(EXMDIR)/%,$(_TEST))
LIB = $(patsubst %,$(LDIR)/%,$(_LIBNAME))

#creating executible using source code of test file
#and linking static library
output: $(TEST) $(LIB)
	$(CC) -o $@ $< $(CFLAGS) $(LIB)
	@echo $(TEST) ' compiled and ' $(LIB) ' is linked.'

#creating library using the object files
$(LIB): $(LIBOBJ)
	ar rcs $@ $^
	@echo $(LIB) ' library created.'

#compiling source code for library
$(LIBOBJ): $(LIBSRC) $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
	@echo $(LIBSRC) ' compiled.'

.PHONY: clean

clean:
	rm -f output* $(LDIR)/*.a $(SRCOBJDIR)/*.o *~ core $(INCDIR)/*~
	@echo 'Removed executible and all object and library files.'
