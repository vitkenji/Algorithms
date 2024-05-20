#include "topologicalSort.h"

void topologicalSort(LGraph* G)
{
    List* l = create();
    DFS(G, &l);
    printf("\n horizontal print ");
    
    printList(l);
}