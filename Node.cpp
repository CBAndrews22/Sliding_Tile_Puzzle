#include "Node.h"


node::node(Puzzle* newPuzzle, int deep){
    puzzle = newPuzzle;
    this->depth = deep;
};

node::node(Puzzle* newPuzzle){
    puzzle = newPuzzle;
    depth = 0;
}

void node::calculateMisplaced(){
    misplacedVal = 0;
    for(int i =0; i < puzzle->bSize; i++){
        if(puzzle->Board[i] != puzzle->Goal[i]){
            misplacedVal +=1;
        }
    }
    if(puzzle->Board[puzzle->zeroIndex] != puzzle->Goal[puzzle->zeroIndex]){
        misplacedVal -=1;
    }
    misplacedVal += depth;
}

void node::calculateManhatten(){
    int curVal, goalInd,curRow, curCol, goalRow, goalCol;
    int tempDist =0;

    
    for(int i=0; i < puzzle->bSize; i++){
        curVal = puzzle->Board[i];
        for(int j=0; j < puzzle->bSize; j++){
            if(curVal == puzzle->Goal[j]){
                goalRow = j/puzzle->nSize;
                goalCol = j%puzzle->nSize;
            } 
        }
        if(curVal != 0){
            curRow = i/3;
            curCol = i%3;
            tempDist += abs(curRow - goalRow) + abs(curCol - goalCol);
        }
    }
    tempDist += depth;
    manhattenDist = tempDist;
}



//****************Linked List*****************//
//********************************************//
LinkedList::LinkedList(){
    head = NULL;
    tail = NULL;
}

LinkedList::LinkedList(node* newNode){
    head = newNode;
    tail = newNode;
};

node* LinkedList::pop(){
    //Checks for empty list
    if(head == NULL){ 
        return NULL;
    }
    //Checks for single item list
    else if(head->next == NULL){
        node* temp = head;
        head = NULL;
        tail = NULL;
        return temp;
    }
    else{
        node* temp = head;
        head = head->next;
        return temp;
    }
};

void LinkedList::push(node* newNode){
    //Checks for empty list
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}

