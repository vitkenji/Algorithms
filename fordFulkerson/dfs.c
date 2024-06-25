#include "dfs.h"
#define WHITE 0
#define GRAY 1
#define BLACK 2

void DFS(LGraph* G)
{
    printf("Vertices visited:\n");
    for(int v = 0; v < G->V; v++)
    {
        G->adj[v]->color = WHITE;
    }

    for(int u = 0; u < G->V; u++)
    {
        if(G->adj[u]->color == WHITE)
        {
            DFSVisit(G, u);
        }
    }
}

void DFSVisit(LGraph* G, int v)
{
    G->adj[v]->color = GRAY;

    Node* aux = G->adj[v];
    while(aux != NULL && aux->id != INT_MAX)
    {
        if(G->adj[aux->id]->color == WHITE)
        {
            DFSVisit(G, aux->id);
        }
        aux = aux->next;
    }
    G->adj[v]->color = BLACK;
    printf("%d ", v);

}