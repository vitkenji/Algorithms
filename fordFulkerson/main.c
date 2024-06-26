#include "fordFulkerson.h"

int main()
{
    LGraph* G = createLGraph(4);
    InsertWeightEdgeListDirectional(G, 0, 1, 3);
    InsertWeightEdgeListDirectional(G, 0, 2, 2);
    InsertWeightEdgeListDirectional(G, 1, 3, 2);
    InsertWeightEdgeListDirectional(G, 2, 3, 3);
    InsertWeightEdgeListDirectional(G, 1, 2, 5);
    correctAdj(G);
    printLGraph(G, 4);

    printf("%d ", fordFulkerson(G, 0, 3));
    return 0;
}