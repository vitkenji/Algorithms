#include "graph.h"
#include "priorityQueue.h"

void initializeSingleSource(LGraph** G, Heap* h, int* queueSize);
void dijkstra(LGraph* G, int s);
void relax();

void printDijkstra(LGraph* G);