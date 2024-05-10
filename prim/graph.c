#include "graph.h"

void printLGraph(LGraph* G, int size)
{

}

void printMGraph(MGraph* G, int size)
{
   printf("Graph: \n");
   printf("     ");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    printf("     ");
    for(int i = 0; i < size; i++)
    {
        printf("| ");
    }
    printf("\n");
    for(int i = 0; i < size; i++)
    {
        printf("%d--  ", i);
        for(int v = 0; v < size; v++)
        {
            printf("%d ", G->matrix[i][v]);
        }
        printf("\n");
    }
}

LGraph* createLGraph(int size)
{
    LGraph* G = (LGraph*) malloc(sizeof(LGraph));
    G->V = size;
    G->E = 0;
    G->adj = (Node**) malloc(sizeof(Node*));
    for(int v = 0; v < G->V; v++)
    {
        G->adj[v] = NULL;
    }
    return G;
}


MGraph* createMGraph(int size)
{
    MGraph* G = (MGraph*) malloc(sizeof(MGraph));
    G->V = size;
    G->E = 0;
    G->matrix = (int**) malloc(sizeof(int*) * size);
    for(int i = 0; i < size; i++)
    {
        G->matrix[i] = (int*) malloc(sizeof(int) * size);
    }
     for(int i = 0; i < size; i++)
    {
         for(int j = 0; j < size; j++)
         {
            G->matrix[i][j] = 0;
         }
    }
    return G;
}

void insertWeightEdgeMatrix(MGraph* G, int v1, int v2, int weight)
{
    G->E++;
    G->matrix[v1][v2] = weight;
    G->matrix[v2][v1] = weight;

}

void insertEdgeMatrix(MGraph* G, int v1, int v2)
{
    G->E++;
    G->matrix[v1][v2] = 1;
    G->matrix[v2][v1] = 1;
}