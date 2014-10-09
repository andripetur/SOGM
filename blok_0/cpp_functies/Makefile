MAIN=tweeIntOptellen printArray maxVanArray rotateArrayLeft

all: $(MAIN)

tweeIntOptellen:
	g++ -c $@.cpp
	g++ -o $@ $@.o

printArray: 
	g++ -c $@.cpp
	g++ -o $@ $@.o

maxVanArray:
	g++ -c $@.cpp
	g++ -o $@ $@.o

rotateArrayLeft:
	g++ -c $@.cpp
	g++ -o $@ $@.o

.cpp.o:
	g++ -c $<

clean: 
	rm *.o $(MAIN)


