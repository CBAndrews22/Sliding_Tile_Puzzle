#include <iostream>
#include <cmath>
#include <ctime>
#include <string>
#include "Puzzle_Game.h"
#include "Node.h"
#include "Uniform_Cost_Search.h"
#include "Misplaced_Tile.h"
#include "Manhattan_Dist.h"

//g++ -o Solution Project_1.cpp Manhattan_Dist.cpp Misplaced_Tile.cpp Uniform_Cost_Search.cpp Puzzle_Game.cpp Node.cpp
//g++ -g -o debug Project_1.cpp Manhattan_Dist.cpp Misplaced_Tile.cpp Uniform_Cost_Search.cpp Puzzle_Game.cpp Node.cpp
Puzzle* generalSearch(Puzzle*, UniformCost);
Puzzle* generalSearch(Puzzle*, MisplacedTile);
Puzzle* generalSearch(Puzzle*, ManhattenDist);

int main(){

    std::cout << "Welcome to The Eight-Puzzle Solver.\nChoose an option.\n\t(1) Use Default Puzzle\n\t(2) Enter custom puzzle\n\t(3) Quit\n";
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

    std::cout << "Starting Puzzle\n";
    StartState->printBoard();

    //Uniform Cost Search
    if(userOption == 1){
        UniformCost UC;
        answer = generalSearch(StartState, UC);
    }
    else if(userOption == 2){
        MisplacedTile MT;
        answer = generalSearch(StartState, MT);
    }
    else{
        ManhattenDist MD;
        answer = generalSearch(StartState, MD);
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


Puzzle* generalSearch(Puzzle* startState, UniformCost UC){
        clock_t t = clock();
        UC.push(startState, 0);        //Adds startState to queue
        node* currNode;
        int nodesTested = 0;                 
        while(UC.queue.head != NULL){               //while queue is not empty
            currNode = UC.queue.pop();              //remove front node from queue
            nodesTested++;
            //std::cout << "Current Node\n";      
            //currNode->puzzle->printBoard();
            //std::cout << "depth: " << currNode->depth << '\n';
            if(currNode->puzzle->Board == currNode->puzzle->Goal){ // Checking for goal state
                t = clock() - t;
                std::cout << "Uniform Cost Search Done\n";
                currNode->puzzle->printBoard();
                std::cout << "Nodes tested: " << nodesTested 
                          << "\nSolution Depth: " << currNode->depth 
                          << "\nRun Time: " << t << "\n\n";
                return currNode->puzzle; }                      // Return solved puzzle
            UC.expand(currNode);                //Adds the Current node's children to the back of the queue
        }
        
        return  NULL;
    };

Puzzle* generalSearch(Puzzle* startState, MisplacedTile MT){
    clock_t t = clock();
    MT.push(new node(startState));
    node* curNode;
    int nodesTested = 0;
    while(!MT.heap.empty()){
        curNode = MT.pop();
        nodesTested++;
        // std::cout << "\nCurrent Node\n";
        // curNode->puzzle->printBoard();
        // std::cout << "Misplaced Tiles: " << curNode->misplacedVal 
        //           << "\ndepth: " << curNode->depth << '\n';
        if(curNode->puzzle->Board == curNode->puzzle->Goal){
            t = clock() - t;
            std::cout << "Misplaced Tiles Done\n";
            curNode->puzzle->printBoard();
            std::cout << "Nodes Tested: " << nodesTested 
                      << "\nSolution Depth: " << curNode->depth 
                      << "\nRun Time: " << t << "\n\n";
            return curNode->puzzle;
        }
        MT.expand(curNode);
    }
    
    return NULL;
}

Puzzle* generalSearch(Puzzle* startState, ManhattenDist MD){
    clock_t t = clock();
    MD.push(new node(startState));
    node* curNode;
    int nodesTested = 0;
    while(!MD.heap.empty()){
        curNode = MD.pop();
        nodesTested++;
        // std::cout << "\nCurrent Node\n";
        // curNode->puzzle->printBoard();
        // std::cout << "Manhatten Dist: " << curNode->manhattenDist
        //           << "\ndepth: " << curNode->depth << '\n';
        if(curNode->puzzle->Board == curNode->puzzle->Goal){
            t = clock() - t;
            std::cout << "Manhatten Distance Done\n";
            curNode->puzzle->printBoard();
            std::cout << "Nodes Tested: " << nodesTested 
                      << "\nSolution Depth: " << curNode->depth 
                      << "\nRun Time: " << t << "\n\n";
            return curNode->puzzle;
        }
        MD.expand(curNode);
    }
    return NULL;
}