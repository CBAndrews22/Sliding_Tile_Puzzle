#include "Manhattan_Dist.h"

ManhattenDist::ManhattenDist(){

}

ManhattenDist::ManhattenDist(node* newNode){
    newNode->calculateManhatten();
    push(newNode);
}

bool ManhattenDist::isVisited(node* curNode){
    for(int i=0; i < visited.size(); i++){
        if(curNode->puzzle->Board == visited[i]->puzzle->Board && 
           curNode->depth >= visited[i]->depth){ return true; }
    }
    return false;
}

void ManhattenDist::expand(node* curNode){
    int newDepth = curNode->depth +1;
    int curZeroInd = curNode->puzzle->zeroIndex;

    //If not in the top row move up
    if(curZeroInd >= curNode->puzzle->nSize){
        //std::cout << "move up\n";
        push(new node(curNode->puzzle->moveUp(), newDepth));
    }
    //If not in bottom row move down
    if(curZeroInd < (curNode->puzzle->bSize - curNode->puzzle->nSize)){
        //std::cout << "move down\n";
        push(new node(curNode->puzzle->moveDown(), newDepth));
    }
    //If not in left column move left
    if((curZeroInd % curNode->puzzle->nSize) != 0){
        //std::cout << "move left\n";
        push(new node(curNode->puzzle->moveLeft(), newDepth));
    }
    //If not in right column move right
    if((curZeroInd % curNode->puzzle->nSize) != (curNode->puzzle->nSize -1)){
        //std::cout << "move right\n";
        push(new node(curNode->puzzle->moveRight(), newDepth));
    }
}

void ManhattenDist::push(node* newNode){
    //First checks if the board has been visited
    if(!isVisited(newNode)){
        newNode->calculateManhatten();
        visited.push_back(newNode);
        int index = heap.size(); // The index of the node being added to the heap
        //std::cout << index << '\n';
        int parentIndex;
        // Parent index is calculated different for even and odd index's
        if(index %2 == 0){  parentIndex = (index/2) -1;  }
        else{   parentIndex = (index - 1)/2;    }
        //std::cout << parentIndex << '\n';
        heap.push_back(newNode);

        while(index > 0 && heap[index]->manhattenDist < heap[parentIndex]->manhattenDist){ //while index is not the rood & The new node value < Parent node value
            swap(index, parentIndex);
            //update index's
            index = parentIndex;
            if(index %2 == 0){  parentIndex = (index/2) -1;  }
            else{   parentIndex = (index - 1)/2;    }
        }
    }
}

node* ManhattenDist::pop(){
    node* temp = heap[0];
    int curIndex = 0;
    int compareIndex;
    int child1, child2;

    //Move the last node in the heap to the root possion
    heap[0] = heap[heap.size() -1]; 
    heap.pop_back();

    while(!heap.empty()){
        //If curIndex has no children
        if(heap.size() <= (curIndex*2)){ return temp;}

        //If curIndex has two children
        else if(heap.size() >= (curIndex*2 + 2)){
            child1 = (curIndex*2 +1);
            child2 = (curIndex*2 +2);

            //Find child node with the least value
            if(heap[child1]->manhattenDist < heap[child2]->manhattenDist){ 
                compareIndex = child1;
            }
            else{ compareIndex = child2; }
        }

        //If curIndex has one child
        else{
            compareIndex = (curIndex*2 +1);
        }

        //Compare values and swap or return temp
        if(heap[curIndex]->manhattenDist > heap[compareIndex]->manhattenDist){ 
            swap(curIndex, compareIndex);
            curIndex = compareIndex;
        }
        else{ return temp; }
    }
    //returns the original root node
    return temp;
}

void ManhattenDist::swap(int index1, int index2){
    node* temp = heap[index2];
    heap[index2] = heap[index1];
    heap[index1] = temp;
}
