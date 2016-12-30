all: test
	rm *.o

test: test.o rangeiterator.o
	g++ test.o rangeiterator.o -o test

test.o: test.cpp rangeiterator.h
	g++ -c test.cpp -o test.o

rangeiterator.o: rangeiterator.cpp rangeiterator.h
	g++ -c rangeiterator.cpp -o rangeiterator.o

clean:
	rm test *.o
