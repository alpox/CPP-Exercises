all: rpn_complex
	rm *.o

rpn_complex: rpn_complex.o pvector.o
	g++ -std=c++11 rpn_complex.o pvector.o -o rpn_complex

rpn_complex.o: rpn_complex.cpp
	g++ -std=c++11 -c rpn_complex.cpp -o rpn_complex.o

pvector.o: pvector.h
	g++ -std=c++11 -c pvector.h -o pvector.o

clean:
	rm rpn_complex *.o testOutput.txt