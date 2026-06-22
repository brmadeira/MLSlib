ROOT = ../
LIBDIR = $(ROOT)/lib 
INCLUDE = $(ROOT)/include
LIBX11 = /usr/X11R6/lib

OUT = mlstest
LIBS =  -lmlssurf -lgsl -lgslcblas -lm
CC = g++
CFLAGS = -I$(INCLUDE) -L$(LIBDIR) -L$(LIBX11) -o $(OUT) $(LIBS) 

install:
	$(CC) main.cpp $(CFLAGS)

clean:
	rm -f *~ *% core $(OUT)





