#ifndef Uniform_Cost_Search
#define Uniform_Cost_Search

#include "Node.h"
#include "Queueing.h"

class UniformCost: public Queueing
{
    public:
        UniformCost();
        UniformCost(node* newNode);
 
        void expand(node* curNode);         //applies operators to current node
};

#endif