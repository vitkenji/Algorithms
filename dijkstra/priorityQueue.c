#include "priorityQueue.h"

int heapMinimum(Heap* h)
{
    return h->vertices[0];
}

int heapExtractMin(Heap* h, int* size)
{
    if(*size < 1)
    {
        printf("heap underflow");
        exit(1);
    }
    int min = h->vertices[0];
    h->vertices[0] = h->vertices[*size - 1];
    h->distance[0] = h->distance[*size - 1];
    (*size)--;
    minHeapify(h, *size, 0);
    return min;

}

void heapDecreaseKey(Heap* h, int index, int v, int d)
{
  if(d > h->distance[index])
    {
        printf("new key is higher than actual key");
        exit(1);
    }
    h->distance[index] = d;
    h->vertices[index] = v;
    while(index > 0 && h->distance[parent(index)] > h->distance[index])
    {
        swap(h, index, parent(index));
        index = parent(index);
    }
}

void minHeapInsert(Heap* h, int* size, int v, int d)
{
    (*size)++;
    h->vertices[(*size)-1 ] = abs(INT_MAX);
    h->distance[(*size) - 1] = abs(INT_MAX);

    heapDecreaseKey(h, *size - 1, v, d);
    
}