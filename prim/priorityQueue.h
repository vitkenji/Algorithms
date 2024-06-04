#include "heap.h"

int heapMinimum(Heap* h);
int heapExtractMin(Heap* h);
void heapDecreaseKey(Heap* h, int index, int d);
void minHeapInsert(Heap* h, int v, int d);
int isInHeap(Heap* h, int v);
