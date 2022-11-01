#include "Node.h"


node::node(node* parentNode, Puzzle* newPuzzle, int deep){
    puzzle = newPuzzle;
    depth = deep;
    parent = parentNode;

};

node::node(Puzzle* newPuzzle){
    puzzle = newPuzzle;
    depth = 0;
    parent = NULL;
}

void node::calculateMisplaced(){
    int tempVal = 0;
    for(int i =0; i < puzzle->bSize; i++){
        if(puzzle->Board[i] != puzzle->Goal[i]){
            tempVal +=1;
        }
    }
    if(puzzle->Board[puzzle->zeroIndex] != puzzle->Goal[puzzle->zeroIndex]){
        tempVal -=1;
    }
    misplacedVal = tempVal;
    priority = misplacedVal + depth;
}

void node::calculateManhattan(){
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
    manhattanDist = tempDist;
    priority = manhattanDist + depth;
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
        newNode->next = NULL;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
}

void LinkedList::printList()
{
    node* temp = head;
    std::cout << "Starting State: ";
    while(temp != NULL)
    {
        if(temp == tail){ std::cout << "Goal State: "; }
        else if(temp != head){ std::cout << "Next State: ";}
        std::cout << "g(n) = " << temp->depth
                  << " and h(n) = " << temp->priority - temp->depth << "\n";
        temp->puzzle->printBoard();
        std::cout << std::endl;
        temp = temp->next;
    }
}

