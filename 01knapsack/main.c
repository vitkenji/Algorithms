#include "knapsack.h"
#define CAPACITY 6
#define ITEMS 4

int main()
{
    int* w = (int*) malloc(sizeof(int)*ITEMS);
    int* v = (int*) malloc(sizeof(int)*ITEMS);
    w[0] = 4; w[1] = 3; w[2] = 2; w[3] = 3;
    v[0] = 3; v[1] = 2; v[2] = 4; v[3] = 4;

    printf("%d ", knapsack(w, v, ITEMS, CAPACITY));

    return 0;
}