#include "prim.h"

void prim(LGraph* G)
{
    
    Heap* h = createHeap(G->V);
    for(int v = 0; v < G->V; v++)
    {
        G->adj[v]->key = 100;
        G->adj[v]->parent = -1;
        h->vertices[v] = v;
        h->position[v] = v;
        h->key[v] = 100;
    }  
    h->key[0] = 0;

    while(h->size > 1)
    {
        //printArray(h->vertices, h->size);
        //printArray(h->key, h->size);
        
        int u = heapExtractMin(h);
        //printf("%d", h->size);
        //printf("\n%d:", u);
        Node* aux = G->adj[u];
        while(aux != NULL && aux->id != INT_MAX)
        {
            int v = aux->id;
            //printf("\n%d < %d", aux->weight, G->adj[v]->key);
            if(isInHeap(h, v) && aux->weight < G->adj[v]->key)
            {
                //printf("\nentered for v=%d: %d < %d",v, aux->weight, G->adj[v]->key);
                G->adj[v]->key = aux->weight;
                G->adj[v]->parent = u;
                heapDecreaseKey(h, h->position[v], aux->weight);
            }
            aux = aux->next;
        }

    }
    printPrim(G);
}

void printPrim(LGraph* G)
{
    printf("\nPrim:\n");
    printf("Edge: Weight:\n");

    for(int i = 1; i < G->V; i++)
    {
     printf("%d -> %d == %d\n", G->adj[i]->parent, i, G->adj[i]->key);   
    }

}