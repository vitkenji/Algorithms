#include "fibonacci.h"

int worstFibonacci(int n)
{
    if(n == 0){return 0;}
    else if(n == 1){return 1;}
    return (worstFibonacci(n - 1) + worstFibonacci(n - 2));
}

int betterFibonacci(int n)
{
    int* array = (int*) malloc(sizeof(int)*(n + 1));
    array[0] = 0;
    array[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        array[i] = array[i - 1] + array[i - 2];

    }
    return array[n];
}

int bestFibonacci(int n)
{
    int matrix[2][2] = {{1, 1}, {1, 0}};
    multiply(matrix, matrix);
    

    return matrix[1][0];
}

void multiply(int** m1, int** m2)
{
    m1[0][0] = m1[0][0]*m2[0][0] + m1[0][1]*m2[1][0];
    m1[1][0] = m1[1][0]*m2[0][0] + m1[1][1]*m2[1][0];
    m1[0][1] = m1[0][0]*m2[0][1] + m1[0][1]*m2[1][1];
    m1[1][1] = m1[1][0]*m2[1][1] + m1[1][1]*m2[1][1];
}

void power(int* matrix, int exp)
{

}