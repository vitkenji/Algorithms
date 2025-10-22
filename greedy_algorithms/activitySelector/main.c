#include "activitySelector.h"

int main()
{
    int s[] = { 1, 3, 0, 5, 8, 5 }; 
    int f[] = { 2, 4, 6, 7, 9, 9 }; 
    int n = 6;
    recursiveActivitySelector(s, f, 0, 1, n);
    return 0;
}