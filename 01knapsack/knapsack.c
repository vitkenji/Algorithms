#include "knapsack.h"

int knapsack(int* w, int* v, int n, int capacity)
{
    int table[n + 1][capacity + 1];
    
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= capacity; j++)
        {
            table[i][j] = 0;
        } 
    }    
    

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j<= capacity; j++)
        {
            if(j < w[i - 1] || table[i - 1][j] >= table[i- 1][j - w[i - 1]] + v[i - 1])
            {
                table[i][j] = table[i - 1][j];
            }
            else
            {
                table[i][j] = table[i- 1][j - w[i - 1]] + v[i - 1];
            }
            printf("%d ", table[i][j]);
        }
        printf("\n");
        
    }

    return table[n][capacity];
}