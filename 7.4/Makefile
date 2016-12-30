all: driver test
	touch my_file
	rm *.o

driver: driver.o locker.o
	g++ driver.o locker.o -o driver

test: test.o locker.o
	g++ test.o locker.o -o test

driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o

test.o: test.cpp
	g++ -c test.cpp -o test.o

locker.o: locker.cpp locker.h
	g++ -c locker.cpp -o locker.o

clean:
	rm my_file driver test
