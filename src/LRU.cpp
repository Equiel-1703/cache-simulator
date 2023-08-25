#include "LRU.h"

LRU::LRU(int assoc) : SubsPolicy(assoc) {}

LRU::LRU(const LRU &other) : SubsPolicy(other.assoc)
{
    elements = other.elements;
    order = other.order;
}

LRU::~LRU()
{
    elements.clear();
    order.clear();
}

void LRU::registerAccess(int via)
{
    auto ret = elements.insert(via);
    if (!ret.second)
    {
        // element already there, remove it first
        order.remove(via);
    }
    // The most recent accessed element is always at the end
    order.push_back(via);
}

int LRU::getViaToReplace()
{
    int ret = order.front();

    order.pop_front();
    order.push_back(ret);

    return ret;
}

SubsPolicy *LRU::clone()
{
    return new LRU(*this);
}

void LRU::printElements()
{
    for (auto it = order.begin(); it != order.end(); ++it)
        printf("%d ", *it);
    printf("\n");
}