all: test driver
	rm *.o

driver: driver.o formatstream.o
	g++ driver.o formatstream.o -o driver

test: test.o formatstream.o
	g++ test.o formatstream.o -o test

driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o

test.o: test.cpp
	g++ -c test.cpp -o test.o

formatstream.o: formatstream.cpp formatstream.h
	g++ -c formatstream.cpp -o formatstream.o

clean:
	rm test driver
