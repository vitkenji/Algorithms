#include "graph.h"
#include "priorityQueue.h"

void initializeSingleSource(LGraph** G, Heap* h);
void dijkstra(LGraph* G, int s);
void relax();

void printDijkstra(LGraph* G);