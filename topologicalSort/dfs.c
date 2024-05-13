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
    int i = 0;
    for(int u = 0; u < G->V; u++)
    {
        if(G->adj[u]->color == WHITE)
        {

            DFSVisit(G, u, &i);
        }
    }
}

void DFSVisit(LGraph* G, int v, int* i)
{
    G->adj[v]->color = GRAY;
    G->adj[v] ->first = (*i);
    (*i)++;

    Node* aux = G->adj[v];
    while(aux != NULL && aux->id != INT_MAX)
    {
        if(G->adj[aux->id]->color == WHITE)
        {
            DFSVisit(G, aux->id, i);
        }
        aux = aux->next;
    }
    G->adj[v]->color = BLACK;
    G->adj[v]->second = (*i);
    (*i)++;
    printf("%d(%d/%d) ", v, G->adj[v]->first, G->adj[v]->second);

}