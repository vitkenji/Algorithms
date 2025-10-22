#include "bfs.h"

int main()
{
   LGraph* G = createLGraph(7);
   InsertEdgeList( G, 0, 1);
   InsertEdgeList( G, 0, 2);
   InsertEdgeList( G, 1, 3);
   InsertEdgeList( G, 1, 4);
   InsertEdgeList(G, 2, 5);
   InsertEdgeList(G, 2, 6);
   
   printLGraph(G, 7);
   BFS(G, 0);
   
    return 0;
}