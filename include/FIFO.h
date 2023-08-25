#pragma once

#include "SubsPolicy.h"
#include <list>

using std::list;

class FIFO : public SubsPolicy
{
private:
    list<int> queue;
public:
    FIFO(int assoc);
    FIFO(const FIFO &other);
    ~FIFO();

    void registerAccess(int via);
    int getViaToReplace();
    SubsPolicy *clone();
};