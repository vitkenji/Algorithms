#include "LCS.h"

int main()
{
    char* c1 = (char*) malloc(sizeof(char)*255);
    char* c2 = (char*) malloc(sizeof(char)*255);

    printf("%d ", LCS(c1, c2));
    return 0;
}

