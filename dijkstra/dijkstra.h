#include "graph.h"
#include "priorityQueue.h"

void initializeSingleSource(LGraph** G, Heap* h);
void dijkstra(LGraph* G, int s);
void relax(LGraph** G, int v, int u);

void printDijkstra(LGraph* G);