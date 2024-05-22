#include "heap.h"

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

    printArray(h->vertices, 10);
    printArray(h->distance, 10);
    printArray(h->visited, 10);
    swap(h, 0, 1);
    printf("\n");
    printArray(h->vertices, 10);
    printArray(h->distance, 10);
    printArray(h->visited, 10);
    return 0;
}