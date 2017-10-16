#include "knapsack.hpp"

void knapsack(int cap, int wt[], int val[], int n)
{
   int i, j;
   int K[n+1][cap+1];

   for (i = 0; i <= n; i++)
   {
       for (j = 0; j <= cap; j++)
       {
           if ((!i) || (!j))
               K[i][j] = 0;
           else if (wt[i-1] <= j)
                 K[i][j] = std::max(val[i-1] + K[i-1][j-wt[i-1]],  K[i-1][j]);
           else
                 K[i][j] = K[i-1][j];
       }
   }
   i--;
   j--;
   printf("value : %d \n",K[n][cap]);
   printf("posicoes escolhidas : ");

   while(K[i][j]){
	if(K[i][j] == K[i-1][j])
		i--;
	else{
		printf(" %d ", i);
		i--;
		j = j - wt[i];

	}
   }


}
int main(int argc, char** argv){

	if (argc < 1) exit(EXIT_FAILURE);
	int n, capacity, i ;
	scanf("%d", &n);
	scanf("%d", &capacity);
	//printf("%d  %d\n",n, capacity);

	int * weight = (int*) malloc(sizeof(int)*(n));
	int * value = (int*) malloc(sizeof(int)*(n));

	for(i = 0; i < (2*n) -1; i+2){
		scanf("%d", &weight[i]);
		scanf("%d", &value[i++]);}

	/*for(i = 0; i < n; i++)
		printf("%d\n",weight[i]);

	printf("\n");

	for(i = 0; i < n; i++)
		printf("%d\n",value[i]);

	printf("\n");*/

	knapsack(capacity, weight, value, n);

	return 0;
}
