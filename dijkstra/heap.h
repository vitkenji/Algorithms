#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct 
{
    int* vertices;
    int* distance;

}Heap;

Heap* createHeap(int size);
int parent(int i);
int left(int i);
int right(int i);
void minHeapify(Heap* h, int size, int index);
void buildMinHeap(Heap* h, int size);

void swap(Heap* h, int pos1, int pos2);
void printArray(int* array, int size);

void swapHeap(int* xp, int* yp);

int findIndex(Heap* h, int size, int v);