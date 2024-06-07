#include "heap.h"

int parent(int i)
{
    return((i - 1) / 2);
}

int left(int i)
{
    return(2*i + 1);
}

int right(int i)
{
    return (2*i + 2);
}

void minHeapify(Heap* h, int index)
{
    int l = left(index);
    int r = right(index);
    int smallest;

    if(l < h->size && h->f[l] < h->f[index]) // which one is smaller: left or parent
    {
        smallest = l;
    }
    else
    {
        smallest = index;
    }

    if(r < h->size && h->f[r] < h->f[smallest]) // which one is smaller: left, parent, or right
    {
        smallest = r;
    }
    if(smallest != index)
    {
        swap(h, smallest, index); // places the smallest in parent position
        minHeapify(h, smallest); 
    }
}

void buildMinHeap(Heap* h)
{
    for(int i = (h->size / 2) - 1; i >= 0; i--) // i = 4,3,2,1,0
    {
        minHeapify(h, i);
    }
}

void swap(Heap* h, int pos1, int pos2)
{
    char aux = h->c[pos1];
    h->c[pos1] = h->c[pos2];
    h->c[pos2] = aux;

    float aux2 = h->f[pos1];
    h->f[pos1] = h->f[pos2];
    h->f[pos2] = aux2;
}

void printArray(int* array, int size)
{
    printf("array: ");
    for(int i = 0; i != size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

Heap* createHeap(int size)
{
    Heap* h = (Heap*) malloc(sizeof(Heap));
    h->c = (char*) malloc(sizeof(char)*size);
    h->f = (float*) malloc(sizeof(int)*size);
    h->size = size;
    return h;
}

void printHeap(Heap* h)
{
    for(int i = 0; i < h->size; i++)
    {
        printf("  %c   |", h->c[i]);
    }
    printf("\n");
    for(int i = 0; i < h->size; i++)
    {
        printf(" %.2f |", h->f[i]);
    }
    printf("\n");
}