#include "dijkstra.h"

void initializeSingleSource(LGraph** G, int* queue, int* queueSize)
{
    for(int v = 0; v < (*G)->V; v++)
    {
        (*G)->adj[v]->distance = INT_MAX;
        (*G)->adj[v]->parent = -1;
        minHeapInsert(queue, queueSize, v);
    }
    (*G)->adj[0]->distance = 0;
}

void dijkstra(LGraph* G, int s)
{
    int weight;
    int* visited = (int*) malloc(sizeof(int)*G->V);
    int* queue = (int*) malloc(sizeof(int)*G->V);
    int queueSize= 0; int i = 0;

    initializeSingleSource(&G, queue, &queueSize);

    while(queueSize > 0)
    {
        int u = heapExtractMin(queue, &queueSize); // 0
        visited[i] = u; i++;
        Node* aux = G->adj[u];
        while(aux != NULL && aux->id != INT_MAX)
        {
            //printf("%d ", aux->id);
            int v = aux->id;
            weight = aux->weight;
            printf("%d   %d   %d\n", v, u, weight);
            printf("%d > %d + %d\n", G->adj[v]->distance,  G->adj[u]->distance, weight);
            if(G->adj[v]->distance > G->adj[u]->distance + weight)
            {
                G->adj[v]->distance = G->adj[u]->distance + weight; 
                G->adj[v]->parent = u;
            }
            aux = aux->next;
            
        }
    }
    /*
    printf("Dijkstra: \n");
    for(int v = 0; v < G->V; v++)
    {
        printf("0 -> %d =  %d\n", v, G->adj[v]->distance);
    }*/
}


void printDijkstra(LGraph* G)
{
    printf("Dijkstra: \n");
    for(int v = 0; v < G->V; v++)
    {
        printf("%d %d", v, G->adj[v]->distance);
    }
}