#include "bellmanFord.h"

void initializeSingleSource(LGraph** G)
{
    for(int i = 0; i < (*G)->V; i++)
    {
        (*G)->adj[i]->distance = 100;
    }
    (*G)->adj[0]->distance = 0;
}

bool bellmanFord(LGraph* G)
{
    initializeSingleSource(&G);
    for(int i = 0; i < G->V - 1; i++)
    {
        int u = 0;
        while(u < G->V)
        {
            Node* aux = G->adj[u];
            while(aux != NULL && aux->id != INT_MAX)
            {
                int v = aux->id;
                relax(&G, v, u, aux->weight);
                aux = aux->next;
            }
            u++;
        }
    }
    printBellmanFord(G);
    int u = 0;
    while(u < G->V)
    {
        Node* aux = G->adj[u];
        while(aux != NULL && aux->id != INT_MAX)
        {
            printf("%d %d \n", u, aux->id);
            int v = aux->id;
            //printf("%d > %d + %d \n", G->adj[v]->distance, aux->id);
            if(G->adj[v]->distance > G->adj[u]->distance + aux->weight)
            {
                return false;
            }
            aux = aux->next;
        }
        u++;
    }

    return true;
}

void relax(LGraph** G, int v, int u, int w)
{
    if((*G)->adj[v]->distance > (*G)->adj[u]->distance + w)
    {
        (*G)->adj[v]->distance = (*G)->adj[u]->distance + w;
    }
}

void printBellmanFord(LGraph* G)
{
    printf("Bellman-Ford: \n");
    for(int v = 0; v < G->V; v++)
    {
        printf("0 -> %d =  %d\n", v, G->adj[v]->distance);
    }
}