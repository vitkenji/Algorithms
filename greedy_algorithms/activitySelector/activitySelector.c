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

void recursiveActivitySelector(int* s, int* f, int i, int j, int n)
{
    if(i == 0){printf("activities selected: %d ", i);}
    if(j < n)
    {
         if(s[j] >= f[i])
        {
            printf("%d ", j);
            recursiveActivitySelector(s, f, j, j + 1, n);
        }
        else
        {
            recursiveActivitySelector(s, f, i,j + 1,n);
        }
    }

}