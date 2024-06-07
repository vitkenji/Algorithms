#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "heap.h"

//min heap
int heapMinimum(Heap* h);
int heapExtractMin(Heap* h);
void heapDecreaseKey(Heap* h, int index, int key);
void minHeapInsert(Heap* h, int freq, char letter);
