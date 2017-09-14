#include "quicks.h"

void partition(int ar[], int low, int high, int *ppivot){
   int pivo, left, right, aux;
   pivo = ar[low];
   left = low;
   right = high;
   while (left < right) {
      while (ar[left] <= pivo && left < high)
          left++;
      while (ar[right] > pivo)
          right--;
      if (left < right) {
         aux = ar[right];
         ar[right] = ar[left];
         ar[left] = aux;}
   }
   ar[low] = ar[right];
   ar[right] = pivo;
   *ppivot = right;
}
void quicksort(int ar[], int low, int high){
     int ppivot;
     if (low >= high)
          return;
     partition(ar, low, high, &ppivot);
     quicksort(ar, low, ppivot - 1);
     quicksort(ar, ppivot + 1, high);
}
