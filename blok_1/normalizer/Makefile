all: normalizer
LIB = -lsndfile
CFLAGS = -Wall

normalizer:
	g++ -c $@.cpp ${CFLAGS}
	g++ -o $@ $@.o ${CFLAGS} ${LIB}

clean:
	rm *.o normalizer
