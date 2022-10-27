#include "Puzzle_Game.h"


Puzzle::Puzzle(std::vector<int> board){
    Board = board;
    bSize = board.size();
    nSize = sqrt(bSize);
    findZeroIndex();
    setGoal();
};

void Puzzle::printBoard(){
    for(int i=0; i < bSize; i++){
        std::cout << this->Board[i];
        if(i != 0 && (i+1) % nSize == 0){std::cout << '\n'; }
    }
};

void Puzzle::findZeroIndex(){
    for(int i=0; i < bSize; i++){
        if(Board[i] == 0){ zeroIndex = i; }
    }
};

void Puzzle::setGoal(){
    for(int i = 0; i < bSize; i++){
        Goal.push_back(i+1);
    }
    Goal[bSize-1] = 0;
}

Puzzle* Puzzle::moveUp(){
    //First checks if blank is in the top row(Illegal move)
    if(zeroIndex < 3){ 
        std::cout << "Can not move up.\n" ;
        return NULL;
        
    }
    //Swaps zero with tile above.
    else{
        Puzzle* temp = new Puzzle(this->Board);
        temp->Board[zeroIndex] = temp->Board[zeroIndex - nSize];
        temp->Board[zeroIndex - nSize] = 0;
        temp->zeroIndex -= nSize;
        return temp;
    }
};

Puzzle* Puzzle::moveDown(){
    //First checks if zero is in the bottom row(Illegal move)
    if(zeroIndex > 5){ 
        std::cout << "Can not move down.\n"; 
        return NULL;
        }
    //Swap Down
    else{
        Puzzle* temp = new Puzzle(this->Board);
        temp->Board[zeroIndex] = temp->Board[zeroIndex + nSize];
        temp->Board[zeroIndex + nSize] = 0;
        temp->zeroIndex += nSize;
        return temp;
    }
};

Puzzle* Puzzle::moveLeft(){
    //Checks if zero is in left column(Illegal move)
    if(zeroIndex % nSize == 0){
        std::cout << "Can not move left.\n";
        return NULL;
    }
    //Swap left tile
    else{
        Puzzle* temp = new Puzzle(this->Board);
        temp->Board[zeroIndex] = temp->Board[zeroIndex -1];
        temp->Board[zeroIndex -1] = 0;
        temp->zeroIndex -= 1; 
        return temp;
    }
}
Puzzle* Puzzle::moveRight(){
    //Checks if tile is in right column(Illegal move)
    if(zeroIndex % nSize == nSize - 1){
        std::cout << "Can not move right.\n";
        return NULL;
    }
    //Swap right
    else{
        Puzzle* temp = new Puzzle(this->Board);
        temp->Board[zeroIndex] = temp->Board[zeroIndex +1];
        temp->Board[zeroIndex +1] = 0;
        temp->zeroIndex += 1;
        return temp;
    }
};