#include "RANDOM.h"

#include <cstdlib>

RANDOM::RANDOM(int assoc) : SubsPolicy(assoc) {}

void RANDOM::registerAccess(int via)
{
    // Do nothing
}

int RANDOM::getViaToReplace()
{
    return rand() % assoc;
}

SubsPolicy *RANDOM::clone()
{
    return new RANDOM(*this);
}