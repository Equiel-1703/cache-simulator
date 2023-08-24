#include "Cache.h"

Cache::Cache(int nsets, int bsize, int assoc, char subst, int flag_saida)
{
    this->nsets = nsets;
    this->bsize = bsize;
    this->assoc = assoc;

    this->subst = subst;
    this->flag_saida = flag_saida;

    this->cacheSize = nsets * bsize * assoc;

    // Calculating cache details
    this->indexSize = log2(nsets);
    this->offsetSize = log2(bsize);
    this->tagSize = addressSize - (indexSize + offsetSize);

    // Calculating real cache size
    this->realCacheSize = (tagSize + 1 + (bsize * 8)) * nsets * assoc;

    // Creating cache sets
    sets = new CacheSet[nsets];
}

Cache::~Cache()
{
    delete[] sets;
}

void Cache::printSetsData()
{
    for (int i = 0; i < nsets; i++)
    {
        sets[i].print();
    }
}