#include <iostream>
#include <cmath>
#include <ctime>
#include <string>
#include "Puzzle_Game.h"
#include "Node.h"
#include "Uniform_Cost_Search.h"
#include "Misplaced_Tile.h"
#include "Manhattan_Dist.h"
#include "Queueing.h"

Puzzle* generalSearch(Puzzle*, UniformCost&);
Puzzle* generalSearch(Puzzle*, MisplacedTile&);
Puzzle* generalSearch(Puzzle*, ManhattanDist&);

int main(){

    std::cout << "Welcome to The Eight-Puzzle Solver.\n"
              << "Choose an option.\n"
              << "\t(1) Use Default Puzzle\n"
              << "\t(2) Enter custom puzzle\n"
              << "\t(3) Quit\n";
    int userOption;
    std::cin >> userOption;
    std::vector<int> initPuzzle;
    
    if(userOption == 1){//Default puzzle
        initPuzzle = {1,3,6,5,0,7,4,8,2};
    }
    else if(userOption == 2){//Custom puzzle 
        std::cout << "Enter custom eight-puzzle where 0 represents the blank tile:\nexample: 123406478\n";
        std::string userPuzzle;
        std::cin >> userPuzzle;
        for(int i=0; i < userPuzzle.size(); i++){
            initPuzzle.push_back(userPuzzle[i]-48);
        }
    }
    else{ return 0;}
    Puzzle* StartState = new Puzzle(initPuzzle);
    Puzzle* answer;
    std::cout << "Choose an algorithm to solve the puzzle\n" <<
                 "(1) Uniform Cost Search\n" <<
                 "(2) Misplaced Tile\n" <<
                 "(3) Manhattan Distance\n";
    std::cin >> userOption;

    int traceBack;
    std::cout << "Do you want the solution traceback?\n"
              << "(1) Yes\n"
              << "(2) No\n" ;
    std::cin >> traceBack;

    

    //Uniform Cost Search
    if(userOption == 1){
        UniformCost UC;
        answer = generalSearch(StartState, UC);
        if(traceBack == 1)
        {
            UC.solutionPath.printList();
        }
        else
        {
            UC.printFinish();
        }
    }

    else if(userOption == 2)
    {
        MisplacedTile MT;
        answer = generalSearch(StartState, MT);
        if(traceBack == 1)
        {
            MT.solutionPath.printList();
        }
        else
        {
            MT.printFinish();
        }
    }

    else if(userOption == 3)
    {
        ManhattanDist MD;
        answer = generalSearch(StartState, MD);
        if(traceBack == 1)
        {
            MD.solutionPath.printList();
        }
        else
        {
            MD.printFinish();
        }

    }
    
    // std::vector<std::vector<int>> depth;
    // depth.push_back({1,2,3,4,5,6,7,8,0}); // depth 0
    // depth.push_back({1,2,3,4,5,6,0,7,8}); // depth 2
    // depth.push_back({1,2,3,5,0,6,4,7,8}); // depth 4
    // depth.push_back({1,3,6,5,0,2,4,7,8}); // depth 8
    // depth.push_back({1,3,6,5,0,7,4,8,2}); // depth 12
    // depth.push_back({1,6,7,5,0,3,4,8,2}); // depth 16
    
    return 0;
}


Puzzle* generalSearch(Puzzle* startState, UniformCost& UC){
        UC.runTime = clock();
        UC.nodesExpanded = 0; 
        UC.push(new node(startState)); //pushes start state to queue
        node* curNode;
        while(!UC.heap.empty())     //while queue is not empty
        {               
            curNode = UC.pop();              //remove front node from queue
            if(curNode->puzzle->Board == curNode->puzzle->Goal){ // Checking for goal state
                UC.runTime = clock() - UC.runTime;
                UC.solutionDepth = curNode->depth;
                UC.getSolutionPath(curNode);
                return curNode->puzzle; }    // Return solved puzzle
            UC.expand(curNode);     //Adds the Current node's children to the back of the queue
            UC.nodesExpanded++;
        }
        return  NULL;
    };

Puzzle* generalSearch(Puzzle* startState, MisplacedTile& MT){
    MT.runTime = clock();
    MT.nodesExpanded = 0;
    MT.push(new node(startState));
    MT.heap[0]->calculateMisplaced();
    node* curNode;
    while(!MT.heap.empty()){
        curNode = MT.pop();
        if(curNode->puzzle->Board == curNode->puzzle->Goal){
            MT.runTime = clock() - MT.runTime;
            MT.solutionDepth = curNode->depth;
            MT.getSolutionPath(curNode);
            return curNode->puzzle;
        }
        MT.expand(curNode);
        MT.nodesExpanded++;
    }
    
    return NULL;
}

Puzzle* generalSearch(Puzzle* startState, ManhattanDist& MD){
    MD.runTime = clock();
    MD.nodesExpanded = 0;
    MD.push(new node(startState));
    MD.heap[0]->calculateManhattan();
    node* curNode;
    while(!MD.heap.empty()){
        curNode = MD.pop();
        if(curNode->puzzle->Board == curNode->puzzle->Goal){
            MD.runTime = clock() - MD.runTime;
            MD.solutionDepth = curNode->depth;
            MD.getSolutionPath(curNode);
            return curNode->puzzle;
        }
        MD.expand(curNode);
        MD.nodesExpanded++;
    }
    return NULL;
}