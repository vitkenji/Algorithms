#include "floydWarshall.h"

int main()
{
    /*
    MGraph* G = createMGraph(5);
    insertWeightEdgeMatrixDirectional( G, 0, 1, 4);
    insertWeightEdgeMatrixDirectional( G, 0, 2, 2);
    insertWeightEdgeMatrixDirectional( G, 1, 2, 3);
    insertWeightEdgeMatrixDirectional( G, 1, 3, 2);
    insertWeightEdgeMatrixDirectional( G, 1, 4, 3);
    insertWeightEdgeMatrixDirectional( G, 2, 3, 4);
    insertWeightEdgeMatrixDirectional( G, 2, 4, 5);
    insertWeightEdgeMatrixDirectional( G, 2, 1, 1);
    insertWeightEdgeMatrixDirectional( G, 4, 3, 1);
    printMGraph(G, 5);*/
    MGraph* G = createMGraph(5);
    insertWeightEdgeMatrixDirectional( G, 0, 1, 4);
    insertWeightEdgeMatrixDirectional( G, 0, 3, 5);
    insertWeightEdgeMatrixDirectional( G, 1, 4, 6);
    insertWeightEdgeMatrixDirectional( G, 1, 2, 1);
    insertWeightEdgeMatrixDirectional( G, 2, 0, 2);
    insertWeightEdgeMatrixDirectional( G, 2, 3, 3);
    insertWeightEdgeMatrixDirectional( G, 3, 2, 1);
    insertWeightEdgeMatrixDirectional( G, 3, 4, 2);
    insertWeightEdgeMatrixDirectional( G, 4, 3, 4);
    insertWeightEdgeMatrixDirectional( G, 4, 0, 1);
    printMGraph(G, 5);
    printf("\n");

    int** D = floydWarshall(G);
    
    return 0;
}
