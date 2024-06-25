#include "sorting.h"

void bubbleSort(int* array, int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if(array[i] > array[j])
            {
                swap(array, i, j);
            }
        }
    }
}

void selectionSort(int* array, int size)
{
    int min;
    for(int i = 0; i < size; i++)
    {
        min = i;
        for(int j = i + 1; j < size; j++)
        {
            if(array[j] < array[min])
            {
                min = j;
            }
        }
        swap(array, min, i);
    }
}

void insertionSort(int* array, int size)
{
    int i, key;
    for(int j = 1; j < size; j++)
    {
        key = array[j];
        i = j - 1;
        while(i >= 0 && array[i] > key)
        {
            array[i + 1] = array[i];
            i--; 
        }
        array[i + 1] = key;
    }
}

void quickSort(int* array, int low, int high)
{
    if(low < high)
    {
        int pi = partition(array, low,high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);

    }
}

int partition(int* array, int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    for(int j = low; j <= high; j++)
    {
        if(array[j] < pivot)
        {
            i++;
            swap(array, i, j);
        }
    }
    swap(array, i + 1, high);
    return (i + 1);
}

void mergeSort(int* array, int p, int r) //0 8
{
  
    if(p < r)
    {
        int q = (p + r) / 2;
        mergeSort(array, p, q); 
        mergeSort(array, q + 1, r);
        merge(array, p, q, r); // 0 4 8
    }
}
                                
void merge(int* array, int p, int q, int r) // 0 4 8 
{  
    int n1 = q - p + 1; 
    int n2 = r - q; 

    int* L = (int*) malloc(sizeof(int)*(n1+1));
    int* R = (int*) malloc(sizeof(int)*(n2+1));

    for(int i = 0; i < n1; i++) //
    {
        L[i] = array[p + i];
    }


    for(int j = 0; j < n2; j++)
    {
        R[j] = array[q + 1 + j];
    }
    

    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    int i = 0; int j = 0;
    for(int k = p; k <= r; k++)
    {
       if(L[i] < R[j])
       {
        array[k] = L[i];
        i++;
       }
       else
       {
        array[k] = R[j];
        j++;
       }
    }


}

void countingSort(int* array, int size)
{
    int max = -1;
    for(int i = 0; i < size; i++)
    {
        if(array[i] > max)
        {
            max = array[i];
        }
    }

    int* countArray = (int*) malloc(sizeof(int)*(max + 1));
    for(int i = 0; i <= max; i++)
    {
        countArray[i] = 0;
    }

    for(int i = 0; i < size; i++)
    {
        countArray[array[i]]++;
    }

    for(int i = 1; i <= max; i++)
    {
        countArray[i] += countArray[i - 1];
    }
    
    int* outputArray = (int*) malloc(sizeof(int)*size);
    for(int i = size - 1; i >= 0; i--)
    {
        outputArray[countArray[array[i]] - 1] = array[i];
        countArray[array[i]]--;
    }

    for(int i = 0; i < size; i++)
    {
        array[i] = outputArray[i];
    }

    free(countArray);
    free(outputArray);

}


void printArray(int* array, int size)
{
    printf("array: ");
    for(int i = 0; i != size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void swap(int* array, int pos1, int pos2)
{
    int aux = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = aux;
}