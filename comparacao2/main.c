#include "merges.h"
#include "quicks.h"
#include "heaps.h"
#include <stdio.h>
#include <stlib.h>

void printarray(int ar[], int n)
{
   int i;
   for (i=0; i < n; i++){printf("%d ", ar[i]);}
   printf("\n");
}

int main()
{
    int arr[] = {15, 14, 17, 11, 12, 13, 16, 10};
    int arr2[] = {15, 14, 17, 11, 12, 13, 16, 10};
    int arr3[] = {15, 14, 17, 11, 12, 13, 16, 10};

    printf("Merge Sort\n");

    printarray(arr, 8);
    mergesort(arr, 0 , 7);
    printarray(arr, 8);

    printf("Selection Sort\n");

    printarray(arr2, 8);
    quicksort(arr2, 0 , 7);
    printarray(arr2, 8);
    
    printf("Heap Sort\n");
    
    printarray(arr3, 8);
    heapsort(arr3, 8);
    printarray(arr3, 8);

    return 0;
