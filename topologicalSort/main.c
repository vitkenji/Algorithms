#include "topologicalSort.h"

int main()
{
    LGraph* G = createLGraph(7);
    InsertEdgeListDirectional( G, 0, 1);
    InsertEdgeListDirectional( G, 1, 2);
    InsertEdgeListDirectional( G, 2, 3);
    InsertEdgeListDirectional( G, 0, 4);
    InsertEdgeListDirectional(G, 4, 5);
    InsertEdgeListDirectional(G, 5, 6);
    correctAdj(G);
    printLGraph(G, 7);
    topologicalSort(G);

    return 0;
}