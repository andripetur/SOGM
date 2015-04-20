CC = g++
CFLAGS = -Wall

all: event

event: main.o scheduler.o event.o
	$(CC) -o $@ $(CFLAGS) main.o event.o

.cpp.o: 
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f `find . -perm +111 -type f`

