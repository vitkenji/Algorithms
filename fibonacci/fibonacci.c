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
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;

    int matrix[2][2] = {{1, 1}, {1, 0}};
    power(matrix, n - 1);

    return matrix[0][0];
}

void multiply(int m1[2][2], int m2[2][2])
{
    int a = m1[0][0] * m2[0][0] + m1[0][1] * m2[1][0];
    int b = m1[0][0] * m2[0][1] + m1[0][1] * m2[1][1];
    int c = m1[1][0] * m2[0][0] + m1[1][1] * m2[1][0];
    int d = m1[1][0] * m2[0][1] + m1[1][1] * m2[1][1];

    m1[0][0] = a;
    m1[0][1] = b;
    m1[1][0] = c;
    m1[1][1] = d;
}

void power(int matrix[2][2], int exp)
{
    if (exp == 0 || exp == 1)
        return;

    int base[2][2] = {{1, 1}, {1, 0}};

    power(matrix, exp / 2);
    multiply(matrix, matrix);

    if (exp % 2 != 0)
    {
        int temp[2][2] = {{1, 1}, {1, 0}};
        multiply(matrix, temp);
    }
}