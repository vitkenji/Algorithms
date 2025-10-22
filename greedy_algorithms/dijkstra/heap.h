#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct 
{
    int* vertices;
    int* distance;
    int* position;
    int size;
}Heap;

Heap* createHeap(int size);
int parent(int i);
int left(int i);
int right(int i);
void minHeapify(Heap* h, int index);
void buildMinHeap(Heap* h);

void swap(Heap* h, int pos1, int pos2);
void printArray(int* array, int size);

void swapHeap(int* xp, int* yp);

int findIndex(Heap* h, int size, int v);