Solution: Project_1.o Manhattan_Dist.o Misplaced_Tile.o Uniform_Cost_Search.o Puzzle_Game.o Node.o 
	g++ Project_1.o Manhattan_Dist.o Misplaced_Tile.o Uniform_Cost_Search.o Queueing.o Puzzle_Game.o Node.o -o Solution

Debug: 
	g++ Project_1.cpp Manhattan_Dist.cpp Misplaced_Tile.cpp Uniform_Cost_Search.cpp Queueing.cpp Puzzle_Game.cpp Node.cpp -g -o debug

Project_1.o: Project_1.cpp
	g++ -c Project_1.cpp

Manhattan_Dist.o: Manhattan_Dist.cpp Manhattan_Dist.h
	g++ -c Manhattan_Dist.cpp

Misplaced_Tile.o: Misplaced_Tile.cpp Misplaced_Tile.h
	g++ -c Misplaced_Tile.cpp

Uniform_Cost_Search.o: Uniform_Cost_Search.cpp Uniform_Cost_Search.h
	g++ -c Uniform_Cost_Search.cpp

Queueing.o: Queueing.cpp Queueing.h
	g++ -c Queueing.cpp

Puzzle_Game.o: Puzzle_Game.cpp Puzzle_Game.h
	g++ -c Puzzle_Game.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

clean:
	rm *.o Solution debug