#pragma once

#include "SubsPolicy.h"

class CacheSet
{
private:
    static int setCount;
    int setNumber;
    int assoc;
    SubsPolicy& subsPolicy;

    class Via
    {
    public:
        bool valid;
        int tag;

        // Via constructor
        Via()
        {
            valid = false;
            tag = 0;
        }
    };

    Via *vias;

public:
    enum AccessResult
    {
        HIT = 0,
        COMPULSORY_MISS,
        OTHER_MISS
    };

    // Constructor and destructor
    CacheSet(int assoc, SubsPolicy& s);
    ~CacheSet();
    // Deep copy constructor
    CacheSet(const CacheSet& other);
    // Copy assignment operator
    CacheSet& operator=(const CacheSet& other);

    // Public methods
    void print();
    AccessResult access(int tag, int& occupiedVias);
};