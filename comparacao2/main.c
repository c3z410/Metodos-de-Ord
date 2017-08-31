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
    int arr[] = {15, 14, 17, 11, 12, 13};
    int arr2[] = {15, 14, 17, 11, 12, 13};
    int arr3[] = {15, 14, 17, 11, 12, 13};

    printf("Merge Sort\n");

    printarray(arr, 6);
    mergesort(arr, 6);
    printarray(arr, 6);

    printf("Selection Sort\n");

    printarray(arr2, 6);
    quicksort(arr2, 6);
    printarray(arr2, 6);
    
    printf("Heaps Sort\n");
    
    printarray(arr3, 6);
    heapsort(arr3, 6);
    printarray(arr3, 6);

    return 0;
