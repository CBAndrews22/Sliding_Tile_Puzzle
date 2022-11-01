#include "Manhattan_Dist.h"

ManhattanDist::ManhattanDist(){
    heapSize = 0;
    maxHeapSize = 0;
}

ManhattanDist::ManhattanDist(node* newNode){
    heapSize = 0;
    maxHeapSize = 0;
    newNode->calculateManhattan();
    push(newNode);
}

void ManhattanDist::expand(node* curNode){
    int newDepth = curNode->depth +1;
    int curZeroInd = curNode->puzzle->zeroIndex;
    node* newNode;

    //If not in the top row move up
    if(curZeroInd >= curNode->puzzle->nSize){
        //std::cout << "move up\n";
        newNode = new node(curNode, curNode->puzzle->moveUp(), newDepth);
        newNode->calculateManhattan();
        push(newNode);
    }
    //If not in bottom row move down
    if(curZeroInd < (curNode->puzzle->bSize - curNode->puzzle->nSize)){
        //std::cout << "move down\n";
        newNode = new node(curNode, curNode->puzzle->moveDown(), newDepth);
        newNode->calculateManhattan();
        push(newNode);
    }
    //If not in left column move left
    if((curZeroInd % curNode->puzzle->nSize) != 0){
        //std::cout << "move left\n";
        newNode = new node(curNode, curNode->puzzle->moveLeft(), newDepth);
        newNode->calculateManhattan();
        push(newNode);
    }
    //If not in right column move right
    if((curZeroInd % curNode->puzzle->nSize) != (curNode->puzzle->nSize -1)){
        //std::cout << "move right\n";
        newNode = new node(curNode, curNode->puzzle->moveRight(), newDepth);
        newNode->calculateManhattan();
        push(newNode);
    }
}