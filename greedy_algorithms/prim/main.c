#include "prim.h"

int main()
{ 
    /*
    LGraph* G = createLGraph(7);
    InsertWeightEdgeList( G, 0, 1, 2);
    InsertWeightEdgeList( G, 0, 2, 3);
    InsertWeightEdgeList( G, 0, 3, 3);
    InsertWeightEdgeList( G, 1, 2, 4);
    InsertWeightEdgeList( G, 1, 4, 3);
    InsertWeightEdgeList( G, 2, 3, 5);
    InsertWeightEdgeList( G, 2, 4, 1);
    InsertWeightEdgeList( G, 2, 5, 6);
    InsertWeightEdgeList( G, 3, 5, 7);
    InsertWeightEdgeList( G, 4, 5, 8);
    InsertWeightEdgeList( G, 5, 6, 9);
    correctAdj(G);
    printLGraphWeight(G, 7);
    *//*
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
    printLGraphWeight(G, 5);*/

    LGraph* G = createLGraph(6);
    InsertWeightEdgeList( G, 0, 1, 4);
    InsertWeightEdgeList( G, 0, 2, 4);
    InsertWeightEdgeList( G, 1, 2, 2);
    InsertWeightEdgeList( G, 2, 3, 3);
    InsertWeightEdgeList( G, 2, 4, 2);
    InsertWeightEdgeList( G, 2, 5, 4);
    InsertWeightEdgeList( G, 3, 5, 3);
    InsertWeightEdgeList( G, 4, 5, 3);

    prim(G);
    

    return 0;
}