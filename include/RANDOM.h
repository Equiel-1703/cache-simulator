#pragma once

#include "SubsPolicy.h"

class RANDOM : public SubsPolicy
{
public:
    RANDOM(int assoc);

    void registerAccess(int via);
    int getViaToReplace();
    SubsPolicy *clone();
};
