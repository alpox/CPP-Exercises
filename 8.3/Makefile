all: play test
	rm *.o

play: play.o connect4.o player.o playfield.o player_factory.o
	g++ -std=c++11 play.o connect4.o player.o playfield.o player_factory.o -o play

test: test.o connect4.o player.o playfield.o player_factory.o
	g++ -std=c++11 test.o connect4.o player.o playfield.o player_factory.o -o test

play.o: main.cpp
	g++ -c -std=c++11 main.cpp -o play.o

test.o: test.cpp
	g++ -c -std=c++11 test.cpp -o test.o

connect4.o: connect4.cpp connect4.h
	g++ -c -std=c++11 connect4.cpp -o connect4.o

player.o: player.cpp player.h
	g++ -c -std=c++11 player.cpp -o player.o

playfield.o: playfield.cpp playfield.h
	g++ -c -std=c++11 playfield.cpp -o playfield.o

player_factory.o: player_factory.cpp player_factory.h
	g++ -c -std=c++11 player_factory.cpp -o player_factory.o

clean:
	rm play test *.o