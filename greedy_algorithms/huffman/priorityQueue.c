#include "priorityQueue.h"

int heapMinimum(Heap* h)
{
    return h->f[0];
}

int heapExtractMin(Heap* h)
{
    if(h->size < 1)
    {
        printf("heap underflow");
        exit(1);
    }
    int min = h->f[0];
    h->f[0] = h->f[h->size - 1];
    h->c[0] = h->c[h->size - 1];
    h->size--;
    minHeapify(h, 0);
    return min;

}

void heapDecreaseKey(Heap* h, int index, int key)
{
    if(key > h->f[index])
    {
        printf("new key is higher than actual key");
        exit(1);
    }
    h->f[index] = key;
    while(index > 0 && h->f[parent(index)] > h->f[index])
    {
        swap(h, index, parent(index));
        index = parent(index);
    }

}

void minHeapInsert(Heap* h, int freq, char letter)
{
    h->size++;
    h->c[h->size - 1] = letter;
    h->f[h->size - 1] = INT_MAX;
    heapDecreaseKey(h, h->size - 1, freq);
}