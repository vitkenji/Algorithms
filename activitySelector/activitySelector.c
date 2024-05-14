#include "activitySelector.h"

void activitySelector(int* s, int* f, int n)
{
    printf("activities selected: ");
    int i = 0;
    printf("%d ", i);

    for(int m = 1; m < n; m++)
    {
        if(s[m] >= f[i])
        {
            printf("%d ", m);
            i = m;
        }
    }
    printf("\n");
}