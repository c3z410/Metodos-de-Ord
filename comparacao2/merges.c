#include "merges.h"
#include <stdlib.h>

void merge(int ar1[], int ar2[], int L, int m, int r){
   int i, L2, nElement, posAux;
   L2 = m - 1;
   posAux = L;
   nElement = r - l + 1;
   while((L <= L2) && (m <= r))
      if(ar1[L] <= ar1[m])
         ar2[posAux++] = ar1[L++];
      else
         ar2[posAux++] = ar1[m++];
   while(L <= L2)
      ar2[posAux++] = ar1[L++];
   while(m <= r)
      ar2[posAux++] = ar1[m++];
   for(i = 0; i < nElement; i++, r--)
      ar1[r] = ar2[r];
}
void mergesort(int ar[], int L, int r){
     int *aux, m;
     int nElem = r-L+1;
     aux = malloc(nElem*sizeof(int));
     if(L < r) {
          m = (L + r)/2;
          mergesort(array, L, m);
          mergesort(ar, m + 1, r);
          merge(array, aux, L, m + 1, r);
     }
     free(aux);
}
