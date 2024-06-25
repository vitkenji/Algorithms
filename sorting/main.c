#define SIZE 1000000
#include "sorting.h"
#include <time.h>

int main()
{
    clock_t begin, end;
    srand(time(NULL));
    int* array = (int*) malloc(sizeof(int)*SIZE);
    int k = SIZE;
    for(int i = 0; i < SIZE; i++)
    {
        array[i] = k;
        k--;
        
    }
   begin = clock();
   printArray(array, SIZE);
   //mergeSort(array,0, SIZE -1 );
   countingSort(array, SIZE);
    printArray(array, SIZE);
    end = clock();
    printf("\nclock: %f", ((double) (end - begin)) / CLOCKS_PER_SEC);
    free(array);
    return 0;
}

//100.000 ELEMENTS:
//BUBBLESORT: CLOCK = 16.23
// MERGESORT: CLOCK = 4.11
//COUNTINGSORT: CLOCK = 3.815

//1.000.000 ELEMENTS:
//BUBBLESORT: CLOCK = failed
// MERGESORT: CLOCK = 37.47
//COUNTINGSORT: CLOCK = 39.32