#include "dijkstra.h"

int main()
{
    LGraph* G = createLGraph(7);
    InsertWeightEdgeList(G, 0, 1, 2);
    InsertWeightEdgeList(G, 0, 2, 6);
    InsertWeightEdgeList(G, 1, 3, 5);
    InsertWeightEdgeList(G, 2, 3, 8);
    InsertWeightEdgeList(G, 3, 4, 10);
    InsertWeightEdgeList(G, 3, 5, 15);
    InsertWeightEdgeList(G, 5, 6, 6);
    InsertWeightEdgeList(G, 4, 6, 2);
    correctAdj(G);
    printLGraphWeight(G, 7);

    dijkstra(G, 0);
    
    return 0;
}