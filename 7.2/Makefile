all: driver test
	rm *.o

driver: driver.o stack.o
	g++ driver.o stack.o -o driver

test: test.o stack.o
	g++ test.o stack.o -o test

driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o

test.o: test.cpp
	g++ -c test.cpp -o test.o

stack.o: stack.cpp stack.h
	g++ -c stack.cpp -o stack.o

clean:
	rm driver test *.o
