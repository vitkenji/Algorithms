#include "fordFulkerson.h"

int fordFulkerson(LGraph* G, int s, int t)
{
    LGraph* Gr = createLGraph(G->V);
    for(int i = 0; i < G->V; i++)
    {
        Node* aux = G->adj[i];
        while(aux != NULL && aux->id != INT_MAX)
        {
            aux->flow = 0;
        }
    }

    int f = 0;
    return f;
}