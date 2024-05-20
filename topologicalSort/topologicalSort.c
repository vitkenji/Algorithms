#include "topologicalSort.h"

void topologicalSort(LGraph* G)
{
    List* l = create();
    DFS(G, &l); 
    printList(l);
}