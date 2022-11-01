#include "Queueing.h"





bool Queueing::isVisited(node* curNode){
    for(int i=0; i < visited.size(); i++){
        if(curNode->puzzle->Board == visited[i]->puzzle->Board && 
           curNode->depth >= visited[i]->depth){ return true; }
    }
    return false;

};

void Queueing::swap(int index1, int index2){
    node* temp = heap[index2];
    heap[index2] = heap[index1];
    heap[index1] = temp;
}


void Queueing::push(node* newNode){
    if(!isVisited(newNode)){
        visited.push_back(newNode);
        int index = heap.size(); // The index of the node being added to the heap
        //std::cout << index << '\n';
        int parentIndex;
        // Parent index is calculated different for even and odd index's
        if(index %2 == 0){  parentIndex = (index/2) -1;  }
        else{   parentIndex = (index - 1)/2;    }
        //std::cout << parentIndex << '\n';
        heap.push_back(newNode);
        heapSize++;
        if(heapSize > maxHeapSize){ maxHeapSize = heapSize; }

        while(index > 0 && heap[index]->priority < heap[parentIndex]->priority){ //while index is not the rood & The new node value < Parent node value
            swap(index, parentIndex);
            //update index's
            index = parentIndex;
            if(index %2 == 0){  parentIndex = (index/2) -1;  }
            else{   parentIndex = (index - 1)/2;    }
        }
    }
}

node* Queueing::pop(){
    node* temp = heap[0]; //node to be returned
    int curIndex = 0;
    int compareIndex;
    int child1, child2;

    //Move the last node in the heap to the root
    heap[0] = heap[heap.size() -1]; 
    heap.pop_back();
    heapSize--;

    while(!heap.empty()){
        //If curIndex has no children return
        if(heap.size() <= (curIndex*2)){ return temp;}

        //If curIndex has two children
        //Find child node with the least value
        else if(heap.size() >= (curIndex*2 + 2)){
            child1 = (curIndex*2 +1);
            child2 = (curIndex*2 +2);

            if(heap[child1]->priority < heap[child2]->priority){ 
                compareIndex = child1;
            }
            else{ compareIndex = child2; }
        }

        //If curIndex has one child
        else{
            compareIndex = (curIndex*2 +1);
        }

        //Compare values
        //swap or return temp
        if(heap[curIndex]->priority > heap[compareIndex]->priority){ 
            swap(curIndex, compareIndex);
            curIndex = compareIndex;
        }
        else{ return temp; }
    }
    //returns the original root node
    return temp;
}

void Queueing::getSolutionPath(node* goalState)
{
    node* curNode = goalState;
    while(curNode->parent != NULL){
        solutionPath.push(curNode);
        curNode = curNode->parent;
    }
    solutionPath.push(curNode);
}

void Queueing::printFinish()
{
    std::cout << "Start State\n";
    solutionPath.head->puzzle->printBoard();
    std::cout << "\nGoal State\n";
    solutionPath.tail->puzzle->printBoard();
    std::cout << "Nodes Expanded : " << nodesExpanded
              << "\nSolution Depth: " << solutionDepth 
              << "\nRun Time: " << runTime
              << "\nMax queue size: " << maxHeapSize << "\n\n"; 
}

void Queueing::traceBack()
{
    solutionPath.printList();
    std::cout << "Nodes Expanded : " << nodesExpanded
              << "\nSolution Depth: " << solutionDepth 
              << "\nRun Time: " << runTime
              << "\nMax queue size: " << maxHeapSize << "\n\n";
}



