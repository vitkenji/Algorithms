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
    G->adj[0]->key = 0;

    while(h->size > 1)
    {

        int u = heapExtractMin(h);

        Node* aux = G->adj[u];
        while(aux != NULL && aux->id != INT_MAX)
        {
            int v = aux->id;

            if(isInHeap(h, v) && aux->weight < G->adj[v]->key)
            {
   
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
    int sum = 0;
    printf("Prim:\n");
    printf("Edge:    Weight:\n");

    for(int i = 1; i < G->V; i++)
    {
        printf("%d -> %d ==   %d\n", G->adj[i]->parent, i, G->adj[i]->key);   
        sum += G->adj[i]->key;
    }
    printf("MST weight: %d", sum);
}