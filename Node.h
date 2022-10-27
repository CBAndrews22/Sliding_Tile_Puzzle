#ifndef Node
#define Node

#include <iostream>
#include "Puzzle_Game.h"

class node{
    public:
        Puzzle* puzzle;
        node* next;
        int depth;
        int misplacedVal;
        int manhattenDist;
        node(Puzzle* newPuzzle, int deep);
        node(Puzzle* newPuzzle);
        
        void calculateMisplaced();
        void calculateManhatten();
    private:

};

class LinkedList{
    public:
        LinkedList();
        LinkedList(node* newNode);
        node* head;
        node* tail;

        node* pop();
        void push(node* newNode);
};


#endif
