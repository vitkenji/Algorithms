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
        //printArray(h->vertices, h->size);
        //printArray(h->distance, h->size);
        //printArray(h->position, h->size);
        
        int u = heapExtractMin(h);
        //printf("\n%d: ", u);
        Node* aux = G->adj[u];
        while(aux != NULL && aux->id != INT_MAX)
        {
            int v = aux->id;
            //printf("%d ", v);
            //printf("(%d)%d > (%d)%d + %d\n",v, G->adj[v]->distance,u, G->adj[u]->distance, aux->weight);
            if(G->adj[v]->distance > G->adj[u]->distance + aux->weight)
            {
                //printf("(%d)%d > (%d)%d + %d\n",v, G->adj[v]->distance,u, aux->distance, aux->weight);
                G->adj[v]->distance = G->adj[u]->distance + aux->weight;
                heapDecreaseKey(h, h->position[v], G->adj[u]->distance + aux->weight); 
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