#include "ordcomp.h"
#include <stdio.h>

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

    printf("Insertion Sort\n");

    printarray(arr, 6);
    insertionsort(arr, 6);
    printarray(arr, 6);

    printf("Selection Sort\n");

    printarray(arr2, 6);
    selectionsort(arr2, 6);
    printarray(arr2, 6);

    return 0;
}
