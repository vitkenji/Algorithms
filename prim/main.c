#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include "prim.h"
#define V 5
 
int main()
{
   MGraph* G = createMGraph(3);
   insertWeightEdgeMatrix(G, 0,1,2);
   insertWeightEdgeMatrix(G, 0,2,9);
   insertWeightEdgeMatrix(G,1,2,10);
   printMGraph(G,3);

   prim(G, 3);
    return 0;
}