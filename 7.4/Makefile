all: driver test rpn
	touch my_file
	rm *.o

rpn: rpn.o locker.o
	g++ rpn.o locker.o -o rpn

driver: driver.o locker.o
	g++ driver.o locker.o -o driver

test: test.o locker.o
	g++ test.o locker.o -o test

rpn.o: rpn.cpp pvector.h
	g++ -c rpn.cpp -o rpn.o

driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o

test.o: test.cpp
	g++ -c test.cpp -o test.o

locker.o: locker.cpp locker.h
	g++ -c locker.cpp -o locker.o

clean:
	rm my_file driver test rpn
