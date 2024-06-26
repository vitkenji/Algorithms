#include "graph.h"
#include "priorityQueue.h"

void initializeSingleSource(LGraph** G, Heap* h);
void dijkstra(LGraph* G, int s);
void relax(LGraph** G, Heap* h,int v, int u, int w);

void printDijkstra(LGraph* G);