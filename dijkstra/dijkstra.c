#include "dijkstra.h"

void initializeSingleSource(LGraph** G, Heap* h, int* queueSize)
{
    for(int v = 0; v < (*G)->V; v++)
    {
        (*G)->adj[v]->distance = INT_MAX;
        minHeapInsert(h, queueSize, v, (*G)->adj[v]->distance);
    }
    (*G)->adj[0]->distance = 0;
    heapDecreaseKey(h, 0, 0, 0);
}

void dijkstra(LGraph* G, int s)
{
    int weight;
    Heap* h = createHeap(G->V);
    int queueSize = 0;

    initializeSingleSource(&G, h, &queueSize);

    while(queueSize > 0)
    {
        int u = heapExtractMin(h, &queueSize);

        Node* aux = G->adj[u];

        while(aux != NULL && aux->id != INT_MAX)
        {
            int v = aux->id;
            weight = aux->weight;

            if(G->adj[v]->distance > G->adj[u]->distance + weight)
            {
                G->adj[v]->distance = G->adj[u]->distance + weight;
                heapDecreaseKey(h, findIndex(h, v, queueSize), v, G->adj[v]->distance);
            }
            aux = aux->next;
        }
    }

    printf("Dijkstra: \n");
    for(int v = 0; v < G->V; v++)
    {
        printf("0 -> %d =  %d\n", v, G->adj[v]->distance);
    }
}


void printDijkstra(LGraph* G)
{
    printf("Dijkstra: \n");
    for(int v = 0; v < G->V; v++)
    {
        printf("%d %d", v, G->adj[v]->distance);
    }
}