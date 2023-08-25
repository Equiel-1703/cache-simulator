#pragma once

#include "SubsPolicy.h"
#include <set>
#include <list>

using std::list;
using std::set;

class LRU : public SubsPolicy
{
private:
    set<int> elements;
    list<int> order;

public:
    LRU(int assoc);
    LRU(const LRU &other);
    ~LRU();

    void registerAccess(int via);
    int getViaToReplace();
    void printElements();
    SubsPolicy *clone();
};