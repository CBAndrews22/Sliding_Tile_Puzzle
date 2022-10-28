#include <iostream>
#include <cmath>
#include <ctime>
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
    // std::cout << "Initial Board \n" ;
    std::vector<std::vector<int>> depth;
    depth.push_back({1,2,3,4,5,6,7,8,0}); // depth 0
    depth.push_back({1,2,3,4,5,6,0,7,8}); // depth 2
    depth.push_back({1,2,3,5,0,6,4,7,8}); // depth 4
    depth.push_back({1,3,6,5,0,2,4,7,8}); // depth 8
    depth.push_back({1,3,6,5,0,7,4,8,2}); // depth 12
    depth.push_back({1,6,7,5,0,3,4,8,2}); // depth 16
    std::cout << "Let the games begin!!\nWhat would you like to do?\n";

    Puzzle* UCSanswer; 
    Puzzle* MTanswer;
    Puzzle* MDanswer;
    UniformCost UCS;
    MisplacedTile MT; 
    ManhattenDist MD;


    for(int i=0; i < depth.size(); i++){
        Puzzle* StartState = new Puzzle(depth[i]);
        UCSanswer = generalSearch(StartState, UCS);
        MTanswer = generalSearch(StartState, MT);
        MDanswer = generalSearch(StartState, MD);
    }
    
    return 0;
}


Puzzle* generalSearch(Puzzle* startState, UniformCost UC){
        clock_t t = clock();
        UC.push(startState, 0);        //Addes startState to queue
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
                std::cout << "Uniform Cost Search Done\nNodes tested: " << nodesTested 
                          << "\nDepth: " << currNode->depth << "\nRun Time: " << t << "\n\n";
                return currNode->puzzle; }                      // Return solved puzzle
            UC.expand(currNode);                //Addes the Current node's children to the back of the queue
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
            std::cout << "Misplaced Tiles Done\nNodes Tested: " << nodesTested 
                      << "\nDepth: " << curNode->depth << "\nRun Time: " << t << "\n\n";
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
            std::cout << "Manhatten Distance Done\nNodes Tested: " << nodesTested 
                      << "\nDepth: " << curNode->depth << "\nRun Time: " << t << "\n\n";
            return curNode->puzzle;
        }
        MD.expand(curNode);
    }
    return NULL;
}