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
            // se peso do item for maior que a capacidade no momento, copia e cola o 0, ou o valor maximo para aquela capacidade
            //qual valor é maior? o da linha de cima e mesma coluna, ou valor do item apontado da linha de cima, coluna j - w[i-1], mais o valor do item atual?
            if(j < w[i - 1] || table[i - 1][j] >= table[i- 1][j - w[i - 1]] + v[i - 1])
            {
                table[i][j] = table[i - 1][j]; // linha de cima, mesma coluna
            }
            else
            {
                table[i][j] = table[i- 1][j - w[i - 1]] + v[i - 1]; // elemento da linha de cima apontado coluna antes peso do item, mais o valor do item atual
            }
             for(int i = 0; i <= n; i++)
            {
                for(int j = 0; j <= capacity; j++)
                {
                    printf("%d ", table[i][j]);
                }
                printf("\n");
            }printf("\n");

        }       
    }

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= capacity; j++)
        {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }


    return table[n][capacity];
}