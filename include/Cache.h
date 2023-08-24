#pragma once

#include <iostream>
#include <string>
#include <cmath>

#include "CacheSet.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Cache
{
private:
    const int addressSize = 32;

    int nsets;
    int bsize;
    int assoc;

    char subst;
    int flag_saida;

    int cacheSize;
    int realCacheSize;

    int indexSize;
    int offsetSize;
    int tagSize;

    CacheSet *sets;
public:
    Cache(int nsets, int bsize, int assoc, char subst, int flag_saida);
    ~Cache();

    void printSetsData();
};