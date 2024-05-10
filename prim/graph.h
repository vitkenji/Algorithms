#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;

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

void printLGraph(LGraph* G, int size);
LGraph* createLGraph(int size);
void insertEdgeListDiretional(LGraph* G, int index, int data);


void printMGraph(MGraph* G, int size);
MGraph* createMGraph(int size);
void insertWeightEdgeMatrix(MGraph* G, int v1, int v2, int weight);
void insertEdgeMatrix(MGraph* G, int v1, int v2);