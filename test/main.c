#include "priorityQueue.h"

int main()
{
    Heap* h = createHeap(10);
    for(int i = 0 ; i < 10; i++)
    {
        h->vertices[i] = i;
        h->distance[i] = 10 - i;
        h->visited[i] = 0;
    }
    h->distance[0] = 0;
    h->visited[0] = 1;
    int size = 10;
    buildMinHeap(h, 10);
    printf("\n");
    printArray(h->vertices, 10);
    printArray(h->distance, 10);

    minHeapInsert(h, &size, 11, 1);

    printArray(h->vertices, size);
    printArray(h->distance, size);

    return 0;
}