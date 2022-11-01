#ifndef __Misplaced_Tile__
#define __Misplaced_Tile__

#include "Node.h"
#include "Queueing.h"

class MisplacedTile: public Queueing
{
    public:
        MisplacedTile();
        MisplacedTile(node* newNode);

        void expand(node* curNode);
};

#endif