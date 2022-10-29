#ifndef Uniform_Cost_Search
#define Uniform_Cost_Search

#include <vector>
#include "Puzzle_Game.h"
#include "Node.h"

class UniformCost{
    public:
        LinkedList queue;
        std::vector<node*> visited;

        UniformCost();
        bool isVisited(Puzzle* newPuzzle);  //checks if a puzzle arrangement has been visited previously 
        void expand(node* curNode);         //applies operators to current node
        void push(Puzzle* puzzle, int depth);
};

#endif