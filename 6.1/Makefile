all: play
	rm *.o

play: play.o connect4.o player.o playfield.o
	g++ -std=c++11 play.o connect4.o player.o playfield.o -o play

play.o: main.cpp
	g++ -c -std=c++11 main.cpp -o play.o

connect4.o: connect4.cpp connect4.h
	g++ -c -std=c++11 connect4.cpp -o connect4.o

player.o: player.cpp player.h
	g++ -c -std=c++11 player.cpp -o player.o

playfield.o: playfield.cpp playfield.h
	g++ -c -std=c++11 playfield.cpp -o playfield.o

clean:
	rm play *.o