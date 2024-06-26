#include "graph.h"
#include "stdbool.h"

void initializeSingleSource(LGraph** G);
bool bellmanFord(LGraph* G);
void relax(LGraph** G, int v, int u, int w);
void printBellmanFord(LGraph* G);