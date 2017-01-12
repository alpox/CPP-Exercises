all: main
	rm *.o

main: main.o
	g++ -std=c++11 main.o -o main

main.o: main.cpp
	g++ -std=c++11 -c main.cpp -o main.o

clean:
	rm *.o main