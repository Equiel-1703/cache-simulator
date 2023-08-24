#include "RANDOM.h"

#include <cstdlib>

RANDOM::RANDOM(int assoc) : SubsPolicy(assoc) {}

void RANDOM::registerAccess(int via, int tag)
{
    // Do nothing
}

int RANDOM::getViaToReplace()
{
    return rand() % assoc;
}