#include "dijkstra.h"

int main()
{
    /*
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
    */
   
   LGraph* G = createLGraph(5);
    InsertWeightEdgeListDirectional( G, 0, 1, 10);
    InsertWeightEdgeListDirectional( G, 0, 2, 3);
    InsertWeightEdgeListDirectional( G, 1, 2, 1);
    InsertWeightEdgeListDirectional( G, 1, 3, 2);
    InsertWeightEdgeListDirectional( G, 2, 1, 4);
    InsertWeightEdgeListDirectional( G, 2, 3, 8);
    InsertWeightEdgeListDirectional( G, 2, 4, 2);
    InsertWeightEdgeListDirectional( G, 3, 4, 7);
    InsertWeightEdgeListDirectional( G, 4, 3, 9);
    correctAdj(G);
    printLGraphWeight(G, 5);
    
   /*LGraph* G = createLGraph(4);
    InsertWeightEdgeList( G, 0, 1, 4);
    InsertWeightEdgeList( G, 0, 2, 2);
    InsertWeightEdgeList( G, 1, 3, 7);
    InsertWeightEdgeList( G, 2, 3, 1);
    correctAdj(G);
    printLGraphWeight(G, 4);*/

    dijkstra(G, 0);

    return 0;
}