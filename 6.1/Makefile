all: play

play: play.o connect4.o player_comp.o playfield_impl.o
	g++ play.o connect4.o player_comp.o playfield_impl.o -o play

play.o: main.cpp
	g++ -c main.cpp -o play.o

connect4.o: connect4.cpp connect4.h
	g++ -c connect4.cpp -o connect4.o

player_comp.o: player_comp.cpp player.h player_comp.h
	g++ -c player_comp.cpp -o player_comp.o

playfield_impl.o: playfield_impl.cpp playfield.h playfield_impl.h
	g++ -c playfield_impl.cpp -o playfield_impl.o

clean:
	rm play *.o
