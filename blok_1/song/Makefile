CC = g++
CFLAGS = -Wall

all: song

song: song.o songmain.o
	$(CC) -o $@ $(CFLAGS) song.o songmain.o

.cpp.o: 
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f `find . -perm +111 -type f`
