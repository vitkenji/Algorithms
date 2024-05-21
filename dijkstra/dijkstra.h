#include "graph.h"
#include "priorityQueue.h"

void initializeSingleSource(LGraph** G, int* queue, int* queueSize, int* visited);
void dijkstra(LGraph* G, int s);
void relax();

void printDijkstra(LGraph* G);