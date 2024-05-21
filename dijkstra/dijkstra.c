#include "dijkstra.h"

void initializeSingleSource(LGraph** G, int* queue, int* queueSize, int* visited)
{
    for(int v = 0; v < (*G)->V; v++)
    {
        (*G)->adj[v]->distance = INT_MAX;
        (*G)->adj[v]->parent = -1;
        visited[v] = 0;
        minHeapInsert(queue, queueSize, v);
    }
    (*G)->adj[0]->distance = 0;
    buildMinHeap(queue, *queueSize);
}

void dijkstra(LGraph* G, int s)
{
    int weight; int smallest, smallestId;
    int* visited = (int*) malloc(sizeof(int)*G->V);
    int* queue = (int*) malloc(sizeof(int)*G->V);
    int queueSize= 0; int i = 0;

    initializeSingleSource(&G, queue, &queueSize, visited);

    while(queueSize > 0)
    {
        int u = heapExtractMin(queue, &queueSize); // 0
        visited[u] = 1;
        Node* aux = G->adj[u];
        smallest = aux->weight; smallestId = u;
        while(aux != NULL && aux->id != INT_MAX)
        {
            int v = aux->id;
            weight = aux->weight;
            if(weight < smallest)
            {
                smallest = weight;
                smallestId = v;
            }
            if(G->adj[v]->distance > G->adj[u]->distance + weight)
            {
                G->adj[v]->distance = G->adj[u]->distance + weight; 
                G->adj[v]->parent = u;
            }
            aux = aux->next;   
        };
        
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