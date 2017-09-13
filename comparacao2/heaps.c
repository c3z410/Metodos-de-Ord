#include "heaps.h"

void heapify(int heap[], int ify, int n){
   int son, aux;
   aux = heap[ify];
   while (2*ify + 1 < n) {
      son = 2*ify + 1;
      if((son != n-1) && (heap[son+1] > heap[son]))
         son++;
      if(aux < heap[son])
         heap[ify] = heap[son];
      else
         break;
      ify = son;
   }
   heap[ify] = aux;
}

void HeapSort(int ar[], int size){
   int i, aux;
   for(i = (size-2)/2; i >= 0; i--)
      heapify(ar, i, size);
   for(i = size-1; i >= 1; i--){
      aux = ar[0];
      ar[0] = ar[i];
      ar[i] = aux;
      heapify(ar, 0, i);}
}
