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

void printarray(int ar[], int n)
{
   int i;
   for (i=0; i < n; i++){printf("%d ", ar[i]);}
   printf("\n");
}

int main()
{
    int arr[] = {15, 14, 17, 11, 12, 13};
    printarray(arr, 6);
    selectionsort(arr, 6);
    printarray(arr, 6);

    return 0;
}
