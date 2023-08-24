#pragma once

class CacheSet
{
private:
    static int setCount;
    int setNumber;
    bool valid;
    int tag;
public:
    CacheSet();
    void print();
};