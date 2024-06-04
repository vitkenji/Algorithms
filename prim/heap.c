#include "heap.h"

Heap* createHeap(int size)
{
    Heap* h = (Heap*) malloc(sizeof(Heap));
    h->vertices = (int*) malloc(sizeof(int)*size);
    h->key = (int*) malloc(sizeof(int)*size);
    h->position = (int*) malloc(sizeof(int)*size);
    h->size = size;
}

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

    if(l < h->size && h->key[l] < h->key[index]) // which one is smaller: left or parent
    {
        smallest = l;
    }
    else
    {
        smallest = index;
    }

    if(r < h->size && h->key[r] < h->key[smallest]) // which one is smaller: left, parent, or right
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
    h->position[h->vertices[pos1]] = pos2;
    h->position[h->vertices[pos2]] = pos1;

    int aux = h->key[pos1];
    h->key[pos1] = h->key[pos2];
    h->key[pos2] = aux;

    aux = h->vertices[pos1];
    h->vertices[pos1] = h->vertices[pos2];
    h->vertices[pos2] = aux;

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

void swapHeap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int findIndex(Heap* h, int size, int v)
{
    for(int i = 0; i < size; i++)
    {
        if(h->vertices[i] == v)
        {
            return i;
        }
    }
    return -1;
}