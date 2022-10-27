#include "Uniform_Cost_Search.h"


UniformCost::UniformCost(){
    visited.clear();
};

bool UniformCost::isVisited(Puzzle* newPuzzle){
    for(int i=0; i < visited.size(); i++){
        if(newPuzzle->Board == visited[i]->puzzle->Board){
            return true;
        }
    }
    return false;
};

void UniformCost::push(Puzzle* puzzle, int deep){
    node* temp = new node(puzzle, deep);
    queue.push(temp);
    visited.push_back(temp);
};

void UniformCost::expand(node* curNode){
    int index = curNode->puzzle->zeroIndex;
    int deep = curNode->depth + 1;

    if(curNode->puzzle->zeroIndex >= curNode->puzzle->nSize && !this->isVisited(curNode->puzzle->moveUp())){
        //std::cout << "move up\n";
        this->push(curNode->puzzle->moveUp(), deep);
    }

    if(curNode->puzzle->zeroIndex < (curNode->puzzle->bSize - curNode->puzzle->nSize) && !this->isVisited(curNode->puzzle->moveDown())){
        //std::cout << "move down\n";
        push(curNode->puzzle->moveDown(), deep);
    }
    
    if((curNode->puzzle->zeroIndex % curNode->puzzle->nSize) != 0 && !this->isVisited(curNode->puzzle->moveLeft())){
        //std::cout << "move left\n";
        push(curNode->puzzle->moveLeft(), deep);
    }

    if((curNode->puzzle->zeroIndex % curNode->puzzle->nSize) != (curNode->puzzle->nSize -1) && !this->isVisited(curNode->puzzle->moveRight())){
        //std::cout << "move right\n";
        push(curNode->puzzle->moveRight(), deep);
    }
}