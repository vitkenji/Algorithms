#include "LCS.h"
#define UP 1
#define LEFT 2
#define DIAG 3



int LCS(char* x, char* y)
{
    int m = strlen(x);
    int n = strlen(y);
    int** c = (int**) malloc(sizeof(int*)*(m + 1));
    for(int i = 0; i < m + 1; i++)
    {
        c[i] = (int*) malloc(sizeof(int)*(n + 1));
    }
    int** b = (int**) malloc(sizeof(int*)*(m + 1));
    for(int i = 0; i < m + 1; i++)
    {
        b[i] = (int*) malloc(sizeof(int)*(n + 1));
    } 

    for(int i = 0; i <= m; i++)
    {
        c[i][0] = 0;
        b[i][0] = 0;
    }
    for(int i = 0; i <= n; i++)
    {
        c[0][i] = 0;
        b[0][i] = 0;
    }

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(x[i - 1] == y[j - 1])
            {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = DIAG;
            }
            else
            {
                if(c[i -1][j] >= c[i][j - 1])
                {
                    c[i][j] = c[i-1][j];
                    b[i][j] = UP;
                }
                else{
                    c[i][j] = c[i][j - 1];
                    b[i][j] = LEFT;
                }
            }
            
        }
    }

    printMatrix(c, x, y, m, n);
    printMatrix(b, x, y, m, n);
    printf("subsequence: "); printLCS(b, x, m, n);
    return c[m][n];
}

void printLCS(int** b, char* x, int i, int j)
{
    if(i == 0 || j == 0)
    {
        return;
    }
    if(b[i][j] == DIAG)
    {
        printLCS(b, x, i - 1, j - 1);
        printf("%c", x[i - 1]);
    }
    else if(b[i][j] == UP)
    {
        printLCS(b, x, i - 1, j);
    }
    else
    {
        printLCS(b, x, i, j - 1);
    }
}

void printMatrix(int** c, char* x, char* y, int m, int n)
{
    printf("\n");
    printf("     ");
    for(int i = 0; i <= n; i++)
    {
        if(i ==0){printf("  ");}
        else { printf("%c ", y[i - 1]); }
    }
    printf("\n");
    printf("     ");
    for(int i = 0; i <= n; i++)
    {
        printf("| ");
    }
    printf("\n");
    for(int i = 0; i <= m; i++)
    {
        if(i == 0){printf(" --  ");}
        else { printf("%c--  ", x[i - 1]); }
        for(int j = 0; j <= n; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}


int worstLCS(char* X, char* Y, int i, int j)
{
    if (X[i] == 0 || Y[j] == 0)
        return 0;
    if (X[i] == Y[j])
        return 1 + worstLCS(X, Y, i + 1, j + 1);
    else
        return max(worstLCS(X, Y, i, j + 1),
                   worstLCS(X, Y, i + 1, j));
}

int max(int a, int b) { return (a > b) ? a : b; }