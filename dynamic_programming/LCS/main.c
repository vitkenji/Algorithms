#include "LCS.h"
#include "time.h"

int main()
{
    clock_t begin, end;
    begin = clock();
    /*
    char c2[] = "aggtab";
    char c1[] = "gxtxayb";
    
    char c2[] = "acd";
    char c1[] = "abc";   */

    char c1[] = "xyzwabcdafgtupirqqqq";
    char c2[] = "xywzaddaupiddddrttttttqqtt";

    printf("\n length: %d ", LCS(c1, c2));
    //printf("\n length: %d ", worstLCS(c1, c2, 0, 0));
    end = clock();
    
    printf("\nclock: %f", ((double) (end - begin)) / CLOCKS_PER_SEC);

    return 0;
}

