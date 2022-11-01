#ifndef __Queueing__
#define __Queueing__

#include "Node.h"

class Queueing{
    public:
        std::vector<node*> heap;
        std::vector<node*> visited;
        LinkedList solutionPath;
        int solutionDepth;
        clock_t runTime;
        int nodesExpanded;
        int heapSize;
        int maxHeapSize;

        bool isVisited(node* newPuzzle);
        virtual void expand(node* curNode) = 0;
        void push(node* newNode);
        void swap(int index1, int index2);
        node* pop();
        void getSolutionPath(node* goalState);
        void printFinish();

};


#endif