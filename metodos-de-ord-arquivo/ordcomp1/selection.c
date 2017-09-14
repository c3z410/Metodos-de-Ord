#include "ordcomp.h"

void selectionsort(int ar[], int n)
{
	int i, j, indice, maior;

	for (i = n - 1; i > 0; --i) {

		maior = ar[0];
		indice = 0;

		for (j = 1; j <= i; ++j){

			if (ar[j] > maior) {
				maior = ar[j];
				indice = j;
			}
		}
		ar[indice] = ar[i];
		ar[i] = maior;
	}
}
