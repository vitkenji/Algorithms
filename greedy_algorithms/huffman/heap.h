#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char* c;
    float* f;
    int size;
}Heap;

Heap* createHeap(int size);
int parent(int i);
int left(int i);
int right(int i);
void minHeapify(Heap* h, int index);
void buildMinHeap(Heap* h);

void swap(Heap* h, int pos1, int pos2);
void printHeap(Heap* h);
