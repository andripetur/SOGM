CC = g++
CFLAGS = -Wall
OBJ= song.o playablesong.o notatedsong.o songmain.o

all: song

song: $(OBJ)
	$(CC) -o $@ $(CFLAGS) $(OBJ)

.cpp.o: 
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f `find . -perm +111 -type f`
