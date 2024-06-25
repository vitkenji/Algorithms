#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int LCS(char* x, char* y);
void printLCS(int** b, char* x, int i, int j);
void printMatrix(int** c, char* x, char* y, int m, int n);

int worstLCS(char* X, char* Y, int i, int j);
int max(int a, int b);