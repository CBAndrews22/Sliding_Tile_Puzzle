# Sliding_Tile_Puzzle
This repo is a solver for the classic sliding tile puzzle.
This project is to create a solver for the classic sliding tile puzzle.
Sliding Puzzle:
A sliding tile puzzle is a square board. By default our puzzle is 3x3 but if the user would like to enter a different size, 4x4 or 5x5, they can do so. The puzzle has one missing tile allowing the user to move tiles around.  The goal is to arrange the tiles numerically from the top left to the bottom right.

Solver:
This project solves the puzzle in three different ways, each using a different search algorithm.
    - Uniform Cost Search - This is a brute-force way to solve the puzzle. Starting from the
        starting position it calculates all possible moves until a goal state is found. This 
        is accomplished using a queue.
    - A* (Missing Tile heuristic)  - This method takes the sum of misplaced tiles, g(n), the 
        number of moves it has taken to get the resulting puzzle, h(n), and the sum of g(n) 
        and h(n) to get f(n).  Each puzzle is then added to a minheap prioritized by f(n).
    -A* (Manhatten Distance) - 
