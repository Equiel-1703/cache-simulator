#include <iostream>

#include "CacheSet.h"

int CacheSet::setCount = 0;

CacheSet::CacheSet(int assoc, SubsPolicy &s)
{
    this->assoc = assoc;
    setNumber = setCount++;
    subsPolicy = s.clone();

    vias = new Via[assoc];
}

CacheSet::CacheSet(const CacheSet &other)
{
    assoc = other.assoc;
    setNumber = other.setNumber;
    subsPolicy = other.subsPolicy->clone();

    vias = new Via[assoc];

    for (int i = 0; i < assoc; ++i)
    {
        vias[i].valid = other.vias[i].valid;
        vias[i].tag = other.vias[i].tag;
    }
}

CacheSet::~CacheSet()
{
    delete[] vias;
    delete subsPolicy;
}

void CacheSet::print()
{
    printf("\nsetNumber: %d\n", setNumber);

    for (int i = 0; i < assoc; i++)
    {
        printf("VIA %d:\n", i + 1);
        printf("\tvalid: %d\n", vias[i].valid);
        printf("\ttag: %d\n", vias[i].tag);
    }
}

CacheSet::AccessResult CacheSet::access(int tag, int &occupiedVias)
{
    // Search for address in cache vias
    for (int i = 0; i < assoc; ++i)
    {
        if (vias[i].valid && vias[i].tag == tag)
        {
            subsPolicy->registerAccess(i);
            return HIT;
        }
    }

    // If not found, it's a miss
    // Let's first check if there's an empty via (compulsory miss)
    for (int i = 0; i < assoc; ++i)
    {
        if (!vias[i].valid)
        {
            vias[i].valid = true;
            vias[i].tag = tag;
            subsPolicy->registerAccess(i);
            ++occupiedVias;
            return COMPULSORY_MISS;
        }
    }

    // If there's no empty via, we have to replace one of them
    // Apply replacement policy
    int viaToReplace = subsPolicy->getViaToReplace();
    vias[viaToReplace].tag = tag;
    subsPolicy->registerAccess(viaToReplace);

    // Only Cache class can tell if it was a capacity miss or a conflict miss
    return OTHER_MISS;
}

CacheSet &CacheSet::operator=(const CacheSet &other)
{
    if (this == &other)
        return *this;

    assoc = other.assoc;
    setNumber = other.setNumber;

    delete subsPolicy;
    subsPolicy = other.subsPolicy->clone();

    delete[] vias;
    vias = new Via[assoc];

    for (int i = 0; i < assoc; ++i)
    {
        vias[i].valid = other.vias[i].valid;
        vias[i].tag = other.vias[i].tag;
    }

    return *this;
}