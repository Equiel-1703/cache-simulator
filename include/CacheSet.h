#pragma once

#include "SubsPolicy.h"

class CacheSet
{
private:
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

    static int setCount;
    int setNumber;
    int assoc;
    SubsPolicy *subsPolicy;
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
    CacheSet(const CacheSet& other); // Deep copy constructor
    ~CacheSet();
    
    // Copy assignment operator
    CacheSet& operator=(const CacheSet& other);

    // Public methods
    void print();
    AccessResult access(int tag, int& occupiedVias);
};