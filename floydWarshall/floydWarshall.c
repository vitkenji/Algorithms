#include "floydWarshall.h"

int** floydWarshall(MGraph* G)
{
    int n = G->V;
    int** D = (int**) malloc(sizeof(int*)*G->V);
    for(int i = 0; i < G->V; i++)
    {
        D[i] = (int*) malloc(sizeof(int)*G->V);
    }

    for(int i = 0; i < G->V; i++)
    {
        for(int j = 0; j < G->V; j++)
        {
            if(i == j) { D[i][j] = 0; }
            else if(G->matrix[i][j] != 0){D[i][j] = G->matrix[i][j];}
            else{ D[i][j] = 100;}   
        }
    }

    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
            }
        }
    }
    printFloydWarshall(D, G->V);
    return D;
}

int min(int n1, int n2)
{
    if(n1 < n2){ return n1; }
    return n2;
}

void printFloydWarshall(int** D, int size)
{
    printf("Floyd-Warshall:\n");
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
            if(D[i][v] != 100){printf("%d ", D[i][v]); }
            else { printf("N "); }
        }
        printf("\n");
    }
}