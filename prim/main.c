#include "prim.h"

int main()
{
    LGraph* G = createLGraph(5);
    InsertWeightEdgeListDirectional( G, 0, 1, 4);
    InsertWeightEdgeListDirectional( G, 0, 2, 2);
    InsertWeightEdgeListDirectional( G, 1, 2, 3);
    InsertWeightEdgeListDirectional( G, 1, 3, 2);
    InsertWeightEdgeListDirectional( G, 1, 4, 3);
    InsertWeightEdgeListDirectional( G, 2, 3, 4);
    InsertWeightEdgeListDirectional( G, 2, 4, 5);
    InsertWeightEdgeListDirectional( G, 2, 1, 1);
    InsertWeightEdgeListDirectional( G, 4, 3, 1);
    correctAdj(G);
    printLGraphWeight(G, 5);

    prim(G);


    return 0;
}