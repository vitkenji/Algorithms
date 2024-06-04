#include "priorityQueue.h"

int heapMinimum(Heap* h)
{
    return h->vertices[0];
}

int heapExtractMin(Heap* h)
{
    if(h->size < 1)
    {
        printf("heap underflow");
        exit(1);
    }
    int min = heapMinimum(h);
    h->vertices[0] = h->vertices[h->size - 1];
    h->key[0] = h->key[h->size - 1];
    h->size--;
    minHeapify(h, 0);
    return min;

}

void heapDecreaseKey(Heap* h, int index, int d)
{
  if(d > h->key[index])
    {
        printf("new key is higher than actual key");
        exit(1);
    }
    h->key[index] = d;
    while(index > 0 && h->key[parent(index)] > h->key[index])
    {
        swap(h, index, parent(index));
        index = parent(index);
    }
}

void minHeapInsert(Heap* h, int v, int d)
{
    h->size++;
    h->vertices[h->size - 1] = v;
    h->key[h->size - 1] = d;
    h->position[v] = h->size - 1;
    heapDecreaseKey(h, v, d);
    
}

int isInHeap(Heap* h, int v)
{
    if(h->position[v] != -1){ return 1; }
    return 0;
}