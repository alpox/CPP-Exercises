all: play

play: play.o connect4.o player_comp.o player_human.o playfield_impl.o
	g++ -std=c++11 play.o connect4.o player_comp.o player_human.o playfield_impl.o -o play

play.o: main.cpp
	g++ -c -std=c++11 main.cpp -o play.o

connect4.o: connect4.cpp connect4.h
	g++ -c -std=c++11 connect4.cpp -o connect4.o

player_comp.o: player_comp.cpp player.h player_comp.h
	g++ -c -std=c++11 player_comp.cpp -o player_comp.o

player_human.o: player_human.cpp player_human.h player.h
	g++ -c -std=c++11 player_human.cpp -o player_human.o

playfield_impl.o: playfield_impl.cpp playfield.h playfield_impl.h
	g++ -c -std=c++11 playfield_impl.cpp -o playfield_impl.o

clean:
	rm play *.o
