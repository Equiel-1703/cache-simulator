#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

#include "CacheSet.h"
#include "SubsPolicy.h"
#include "LRU.h"
#include "FIFO.h"
#include "RANDOM.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Cache
{
private:
    const int addressSize = 32;

    int nsets;
    int bsize;
    int assoc;

    char substChar;
    int flag_saida;

    int cacheSize;
    double realCacheSize;

    int indexSize;
    int offsetSize;
    int tagSize;

    vector<CacheSet> sets;
    
    int accesses;
    int occupiedBlocks;
    const int numBlocks;

    SubsPolicy *substPolicy;

    // Misses count
    int compulsoryMisses;
    int capacityMisses;
    int conflictMisses;

public:
    // Constructor and destructor
    Cache(int nsets, int bsize, int assoc, char subst, int flag_saida);
    ~Cache();

    // Print data
    void printSetsData();
    void printCacheInfo();

    // Retrieve address in cache
    void accessAddress(int address);

private:
    // Get address parts
    int getTag(int address);
    int getIndex(int address);
    int getOffset(int address);
};