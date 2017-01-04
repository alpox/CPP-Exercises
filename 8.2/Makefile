all: sc
	rm *.o

sc: sc.o
	g++ -std=c++11 sc.o -o sc

sc.o: main.cpp
	g++ -std=c++11 -c main.cpp -o sc.o

clean:
	rm sc *.o