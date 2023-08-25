#include "FIFO.h"

FIFO::FIFO(int assoc) : SubsPolicy(assoc) {}

FIFO::FIFO(const FIFO &other) : SubsPolicy(other.assoc)
{
    queue = other.queue;
}

FIFO::~FIFO()
{
    queue.clear();
}

void FIFO::registerAccess(int via)
{
    if (queue.size() < assoc)
    {
        queue.push_back(via);
    }
}

int FIFO::getViaToReplace()
{
    int via = queue.front();
    queue.pop_front();
    return via;
}

SubsPolicy *FIFO::clone()
{
    return new FIFO(*this);
}
