all: rpn_complex
	rm *.o

rpn_complex: rpn_complex.o 
	g++ -std=c++11 rpn_complex.o -o rpn_complex

rpn_complex.o: rpn_complex.cpp pvector.h
	g++ -std=c++11 -c rpn_complex.cpp -o rpn_complex.o

clean:
	rm rpn_complex *.o testOutput.txt