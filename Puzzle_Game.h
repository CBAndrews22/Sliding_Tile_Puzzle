#ifndef Puzzle_Game
#define Puzzle_Game

//This class represents the sliding puzzle game.

#include <iostream>
#include <cmath>
#include <vector>

class Puzzle{
    public:
        int bSize;      //The total number of squares on the board
        int nSize;      //The n x n size of the board
        int zeroIndex;  //Index of the blank spot on the board(0)
        std::vector<int> Board; 
        std::vector<int> Goal;

        Puzzle(std::vector<int> board);
        void printBoard();
        void findZeroIndex();
        void setGoal();
        // Opperators 
        Puzzle* moveUp();
        Puzzle* moveDown();
        Puzzle* moveLeft();
        Puzzle* moveRight();
        
    private:
        
};


#endif