#include "heap.h"

//min heap
int heapMinimum(Heap* h);
int heapExtractMin(Heap* h, int* size);
void heapDecreaseKey(Heap* h, int index, int v, int d);
void minHeapInsert(Heap* h, int* size, int v, int d);

