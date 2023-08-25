#include "Cache.h"

Cache::Cache(int nsets, int bsize, int assoc, char subst, int flag_saida) : numBlocks(nsets * assoc)
{
    this->nsets = nsets;
    this->bsize = bsize;
    this->assoc = assoc;

    this->substChar = subst;
    this->flag_saida = flag_saida;

    cacheSize = nsets * bsize * assoc;

    // Calculating cache details
    indexSize = (int)log2(nsets);
    offsetSize = (int)log2(bsize);
    tagSize = addressSize - (indexSize + offsetSize);

    // Calculating real cache size (in bytes)
    realCacheSize = (double)((tagSize + 1 + (bsize * 8)) * nsets * assoc) / 8.0;

    // Creating replacement policy
    switch (substChar)
    {
    case 'l':
    case 'L':
        substPolicy = new LRU(assoc);
        break;

    case 'f':
    case 'F':
        substPolicy = new FIFO(assoc);
        break;

    default:
        substPolicy = new RANDOM(assoc);
    }

    // Creating cache sets and counters
    for (int i = 0; i < nsets; ++i)
        sets.push_back(CacheSet(assoc, *substPolicy));

    accesses = 0;
    occupiedBlocks = 0;

    // Initializing misses count
    compulsoryMisses = 0;
    capacityMisses = 0;
    conflictMisses = 0;
}

Cache::~Cache()
{
    sets.clear();
}

void Cache::printSetsData()
{
    for (int i = 0; i < nsets; i++)
    {
        sets[i].print();
    }
}

void Cache::printCacheInfo()
{
    int totalMisses = compulsoryMisses + capacityMisses + conflictMisses;

    double hitRatio = (double)(accesses - totalMisses) / (double)accesses;
    double missRatio = 1.0 - hitRatio;

    double compulsoryMissRatio = (double)compulsoryMisses / (double)totalMisses;
    double capacityMissRatio = (double)capacityMisses / (double)totalMisses;
    double conflictMissRatio = (double)conflictMisses / (double)totalMisses;

    if (flag_saida == 1)
    {
        printf("%d %.4lf %.4lf %.2lf %.2lf %.2lf\n", accesses, hitRatio, missRatio, compulsoryMissRatio, capacityMissRatio, conflictMissRatio);
    }
    else
    {
        printf("Nro de conjuntos: %d\n", nsets);
        printf("Tamanho do bloco: %d bytes\n", bsize);
        printf("Grau de associatividade: %d\n", assoc);
        printf("Politica de substituicao: %c\n", substChar);

        printf("\nflag_saida: %d\n", flag_saida);
        printf("Tamanho da cache: %d bytes\n", cacheSize);
        printf("Tamanho real da cache: %.2lf bytes\n", realCacheSize);

        printf("\nindexSize: %d\n", indexSize);
        printf("offsetSize: %d\n", offsetSize);
        printf("tagSize: %d\n", tagSize);

        printf("\nAcessos: %d\n", accesses);
        printf("Misses totais: %d\n", compulsoryMisses + capacityMisses + conflictMisses);

        printf("Tipos de Misses: \n");
        printf("\tMisses compulsorios: %d\n", compulsoryMisses);
        printf("\tMisses de capacidade: %d\n", capacityMisses);
        printf("\tMisses de conflito: %d\n", conflictMisses);

        printf("\nTaxa de miss: %.4lf\n", missRatio);
        printf("Taxa de hit: %.4lf\n", hitRatio);
        printf("Taxa de miss compulsorio: %.2lf\n", compulsoryMissRatio);
        printf("Taxa de miss de capacidade: %.2lf\n", capacityMissRatio);
        printf("Taxa de miss de conflito: %.2lf\n", conflictMissRatio);
    }
}

void Cache::accessAddress(int address)
{
    ++accesses;

    // Get address parts
    int tag = getTag(address);
    int index = getIndex(address);

    // Accessing cache set
    CacheSet::AccessResult ret = sets[index].access(tag, occupiedBlocks);

    // Checking miss type
    switch (ret)
    {
    case CacheSet::COMPULSORY_MISS:
        ++compulsoryMisses;
        break;

    case CacheSet::OTHER_MISS:
        if (occupiedBlocks == numBlocks)
            ++capacityMisses;
        else
            ++conflictMisses;
    }
}

// Get address parts
int Cache::getTag(int address)
{
    return address >> (indexSize + offsetSize);
}
int Cache::getIndex(int address)
{
    return (address >> offsetSize) & ((1 << indexSize) - 1);
}
int Cache::getOffset(int address)
{
    return address & ((1 << offsetSize) - 1);
}