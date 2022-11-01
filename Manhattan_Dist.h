#ifndef __Manhattan_Distance__
#define __Manhattan_Distance__

#include "Node.h"
#include "Queueing.h"

class ManhattanDist : public Queueing
{
    public:
        ManhattanDist();
        ManhattanDist(node* newNode);

        void expand(node* curNode);
};
#endif