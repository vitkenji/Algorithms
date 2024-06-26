#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define DIAG 1
#define UP 5
#define LEFT 2

typedef struct node
{
    int id;
    struct node* next;
    int key;
    int parent;
    int weight;
    int distance;

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

int fibonacci(int  n) // O(n)
{
    int array [n + 1];
    array[0] = 0;
    array[1] = 1;
    for(int i = 0; i <= n; i++)
    {
        array[i] = array[i - 1] + array[i - 2];
    }


    return array[n];
}

int knapsack(int* v, int* w, int n, int W) // O(nW)
{
    int t[n + 1][W + 1];
    for(int i = 0; i <= n; i++)
    {
        t[i][0] = 0;
    }
    for(int i = 0; i <= W; i++)
    {
        t[0][i] = 0;
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= W; j++)
        {
            if(j < w[i - 1] || t[i - 1][j] > t[i - 1][j - w[i - 1]] + v[i - 1])
            {
                t[i][j] = t[i - 1][j];
            }
            else
            {
                t[i][j] = t[i-1][j - w[i - 1]] + v[i - 1];
            }
        }
    }
}

int LCS(char* X, char* Y) //O(mn)
{
    int m = strlen(X);
    int n = strlen(Y);
    int c[m + 1][n + 1];
    int b[m + 1][n + 1];

    for(int i = 0; i <= m; i++)
    {
        c[i][0] = 0;
    }
    for(int i = 0; i <= n; i++)
    {
        c[0][i] = 0;
    }
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; i <= n; j++)
        {
            if(X[i - 1] == Y[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = DIAG;
            }
            else
            {
                if(c[i - 1][j] >= c[i][j - 1])
                {
                    c[i][j] = c[i - 1][j];
                    b[i][j] = UP;
                }
                else
                {
                    c[i][j] = c[i][j - 1];
                    b[i][j] = LEFT;
                }
            }
        }
    }
    return c[m][n];
}

void printLCS(int** b, char* X, int i, int j) // O(m + n)
{
    if(i == 0 || j == 0)
    {
        return;
    }
    else
    {
        if(b[i][j] == DIAG)
        {
            printLCS(b, X, i - 1, j - 1);
            printf("%c", X[i - 1]);
        }
        else if(b[i][j] == UP)
        {
            printLCS(b, X, i - 1, j);
        }
        else
        {
            printLCS(b, X, i, j - 1);
        }
    }
}

void initializeSingleSource(LGraph* G)
{
    for(int i = 0; i < G->V; i++)
    {
        G->adj[i]->distance = 0;
    }

    G->adj[0]->distance = 0;
}

bool bellmanFord(LGraph* G) // O(VE)
{
    initializeSingleSource(G);

    for(int i = 0; i < G->V - 1; i++)
    {
        for(int j = 0; j < G->E; j++)
        {
            relax();
        }
    }

    for(int i = 0; i < G->E; i++)
    {
        //if(d.v > u.v + w(u, v))
        return false;
    }
    return true;

}

void relax()
{

}

int** floydWarshall(MGraph* G) //O(V^3)
{
    int n = G->V;
    int** D = (int**) malloc(sizeof(int*) * G->V);
    D = G->matrix;

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
    return D;
}

/*
NP completude:

Classe P : problemas que tem algoritmos de complexidade polinomial que solucionam o problema.
Classe NP: problemas que, dada uma solução candidata, pode ser verificada se a solução é a correta em tempo polinomial.

P pertence a NP

Redução: um problema A pode ser transformado em um problema B, para assim acharmos uma solução de B,
 e assim usar a solução de B para resolver o problema A.

problema NP-Completo:
    I) pertence à NP
    II) todo problema em NP pode ser reduzido à ele em tempo polinomial.
    exemplos: Caixeiro viajante, SAT, clique, problema da mochila, achar ciclo hamiltoniano

-Se um algoritmo de solução de complexidade polinomial for encontrada para um problema NP-Completo,
 todos os problemas em NP serão resolvidos.

*/

