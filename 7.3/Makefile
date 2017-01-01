all: test driver
	rm *.o

driver: driver.o container_merger.o
	g++ driver.o container_merger.o -o driver

test: test.o container_merger.o
	g++ test.o container_merger.o -o test

driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o

test.o: test.cpp
	g++ -c test.cpp -o test.o

container_merger.o: container_merger.cpp container_merger.h
	g++ -c container_merger.cpp -o container_merger.o

clean:
	rm test driver *.o
