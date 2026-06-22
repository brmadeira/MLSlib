ROOT = ../
LIBDIR = $(ROOT)/lib
INCLUDE =$(ROOT)/include

CC = g++
CFLAGS = -g -I$(INCLUDE) -Wno-deprecated

HEADERS = extremal_surface.h es_optimize_context.h mls_surface.h Vector3.h defs.h
OBJECTS = extremal_surface.o es_optimize_context.o mls_surface.o
LIBNAME = libmlssurf.a


$(LIBNAME): $(HEADERS) $(OBJECTS)
	ar ruv $(LIBNAME) $(OBJECTS)
	ranlib $(LIBNAME)

install: $(LIBNAME)
	mv $(LIBNAME) $(LIBDIR)
	cp $(HEADERS) $(INCLUDE)

clean:
	rm -f *.o *~ $(LIBNAME)

