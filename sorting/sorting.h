#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void bubbleSort(int* array, int size);
void selectionSort(int* array, int size);
void insertionSort(int* array, int size);
void quickSort(int* array, int low, int high);
int partition(int* array, int low, int high);
void mergeSort(int* array, int p, int r);
void merge(int* array, int low, int mid, int high);
void countingSort(int* array, int size);

void printArray(int* array, int size);
void swap(int* array, int pos1, int pos2);
