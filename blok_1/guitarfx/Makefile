CPP = g++
CC = gcc

CFLAGS = -Wall
OBJ = amplifier.o tremolo.o distortion.o guitarfxmain.o audio_io.o
LIB = -lportaudio

all: guitarfx

guitarfx: $(OBJ)
	$(CPP) -o $@ $(CFLAGS) $(OBJ) $(LIB) -lpthread

.cpp.o:
	$(CPP) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f `find . -perm +111 -type f`

