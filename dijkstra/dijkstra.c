#include "dijkstra.h"

void initializeSingleSource(LGraph** G, Heap* h)
{
    for(int i = 0; i < (*G)->V; i++)
    {
        h->vertices[i] = i;
        h->position[h->vertices[i]] = i;
        h->distance[i] = 100;
        (*G)->adj[i]->distance = 100;
    }
    h->distance[0] = 0;
    (*G)->adj[0]->distance = 0;
}

void dijkstra(LGraph* G, int s)
{
    Heap* h = createHeap(G->V);
    initializeSingleSource(&G, h);

    while(h->size > 0)
    {
        int u = heapExtractMin(h);
        
        Node* aux = G->adj[u];
        while(aux != NULL && aux->id != INT_MAX)
        {
            int v = aux->id;
   
            if(G->adj[v]->distance > G->adj[u]->distance + aux->weight)
            {
                G->adj[v]->distance = G->adj[u]->distance + aux->weight;
                heapDecreaseKey(h, h->position[v], G->adj[u]->distance + aux->weight); 
            }
            aux = aux->next;
        }
    }
    printDijkstra(G);
}


void printDijkstra(LGraph* G)
{
    printf("Dijkstra: \n");
    for(int v = 0; v < G->V; v++)
    {
        printf("0 -> %d =  %d\n", v, G->adj[v]->distance);
    }
}