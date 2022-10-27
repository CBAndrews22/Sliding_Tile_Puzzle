#ifndef __Manhattan_Distance__
#define __Manhattan_Distance__

#include "Node.h"

class ManhattenDist{
    public:
        std::vector<node*> heap;
        std::vector<Puzzle*> visited;

        ManhattenDist();
        ManhattenDist(node* newNode);

        bool isVisited(node* curNode);
        void expand(node* curNode);
        void push(node* newNode);
        node* pop();
        void swap(int index1, int index2);
};
#endif