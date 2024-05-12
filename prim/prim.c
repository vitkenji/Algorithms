#include "prim.h"

void prim(MGraph* G, int size)
{
    int* key = (int*) malloc(sizeof(int)*size);
    int* heap = (int*) malloc(sizeof(int)*size);
    int* parent = (int*) malloc(sizeof(int)*size);
    int heapSize = 0;

    for(int i = 0; i < size; i++)
    {
        key[i] = INT_MAX;
        parent[i] = -1;
        minHeapInsert(heap, &heapSize, i);
    } 

    key[0] = 0;

    while(heapSize != 0)
    {
        int u = heapExtractMin(heap, &heapSize);

    }
    
}