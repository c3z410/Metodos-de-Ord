#include "ordcomp.h"

void insertionsort(int ar[], int n)
{

int i, j, key;

for (i = 1; i < n; ++i){
	key = ar[i];

	for (j = i - 1; j >= 0 && key < ar[j]; --j){
		ar[j + 1] = ar[j];
	}
	ar[j + 1] = key;
	}
}
