#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node
{
    int id;
    struct node* next;
    int distance;
    int parent;
    int weight;

}Node;

typedef struct Lgraph{
    int E;
    int V;
    Node** adj;
    
}LGraph;

typedef struct Mgraph{
    int E;
    int V;
    int** matrix;

}MGraph;

void printMGraph(MGraph* G, int size);
MGraph* createMGraph(int size);
void insertWeightEdgeMatrix(MGraph* G, int v1, int v2, int weight);
void insertEdgeMatrix(MGraph* G, int v1, int v2);
void insertWeightEdgeMatrixDirectional(MGraph* G, int v1, int v2, int weight);
