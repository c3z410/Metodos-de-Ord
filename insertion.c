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
    insertionsort(arr, 6);
    printarray(arr, 6);

    return 0;
}
