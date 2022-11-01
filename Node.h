#ifndef Node
#define Node

#include <iostream>
#include "Puzzle_Game.h"

class node{
    public:
        Puzzle* puzzle;
        node* next;
        node* parent;
        int depth;
        int misplacedVal;
        int manhattanDist;
        int priority;
        node(node* parentNode, Puzzle* newPuzzle, int deep);
        node(Puzzle* newPuzzle);
        
        void calculateMisplaced();
        void calculateManhattan();
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
        void printList();
};


#endif
