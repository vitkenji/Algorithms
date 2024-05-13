#include "dfs.h"

int main()
{
    LGraph* G = createLGraph(8);
    InsertEdgeList( G, 0, 1);
    InsertEdgeList( G, 1, 2);
    InsertEdgeList( G, 2, 3);
    InsertEdgeList( G, 0, 4);
    InsertEdgeList(G, 4, 5);
    InsertEdgeList(G, 5, 6);
    correctAdj(G);
    printLGraph(G, 8);
    //printf("%d",G->adj[0]->id);
    DFS(G);

    return 0;
}