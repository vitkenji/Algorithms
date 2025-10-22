#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node
{
    int id;
    struct node* next;
    int color;
    int first;
    int second;

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
void InsertEdgeListDirectional(LGraph* GrafoA, int index, int data);
void InsertEdgeList( LGraph* GrafoA, int data1, int data2);

void printMGraph(MGraph* G, int size);
MGraph* createMGraph(int size);
void insertWeightEdgeMatrix(MGraph* G, int v1, int v2, int weight);
void insertEdgeMatrix(MGraph* G, int v1, int v2);

void correctAdj(LGraph* G);