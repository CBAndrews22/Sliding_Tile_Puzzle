#ifndef __Misplaced_Tile__
#define __Misplaced_Tile__

#include <vector>
#include "Node.h"

class MisplacedTile{
    public:
        std::vector<node*> heap; 
        std::vector<Puzzle*> visited;

        MisplacedTile();
        MisplacedTile(node* newNode);
        bool isVisited(node* curNode);
        void expand(node* curNode);
        void push(node* newNode);
        void swap(int index1, int index2);
        node* pop();
};

#endif