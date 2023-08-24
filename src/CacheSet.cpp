#include "CacheSet.h"
#include <iostream>

int CacheSet::setCount = 0;

CacheSet::CacheSet()
{
    setNumber = setCount++;
    valid = false;
    tag = 0;
}

void CacheSet::print()
{
    printf("\nsetNumber: %d\n", setNumber);
    printf("valid: %d\n", valid);
    printf("tag: %d\n", tag);
}