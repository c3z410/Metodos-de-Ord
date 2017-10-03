#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

int minKey(int key[], bool mstSet[], int size){
   
	int min = INT_MAX, min_index;
 
	for (int v = 0; v < size; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;
 
	return min_index;
}

int printMST(int parent[], int size, int **graph){
	printf("Edge   Weight\n");
	for (int i = 1; i < size; i++)
		printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}
 
void primMST(int **graph , int size){
	int parent[size]; 
	int key[size];   
	bool mstSet[size]; 
 
   
	for (int i = 0; i < size; i++)
		key[i] = INT_MAX, mstSet[i] = false;
 
    
	key[0] = 0;    
	parent[0] = -1; 
 
    
	for (int count = 0; count < size-1; count++){
        
		int u = minKey(key, mstSet , size);
 
        
		mstSet[u] = true;
 
        
	for (int v = 0; v < size; v++)
 
          
		if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
        		parent[v]  = u, key[v] = graph[u][v];
     	}
 
     
     printMST(parent, size, graph);
}

int minDistance(int dist[], bool sptSet[], int size)
{
	int min = INT_MAX, min_index;
  
	for (int v = 0; v < size; v++)
		if (sptSet[v] == false && dist[v] <= min)
         	min = dist[v], min_index = v;
  
  	 return min_index;
}
  

int printSolution(int dist[], int size){
	for (int i = 0; i < size; i++)
		printf("%d \t\t %d\n", i, dist[i]);
}
  
void dijkstra(int **graph, int src, int size){
	int dist[size];   
	bool sptSet[size]; 

	for (int i = 0; i < size; i++)
		dist[i] = INT_MAX, sptSet[i] = false;
  
	dist[src] = 0;
  
	for (int count = 0; count < size-1; count++){
		int u = minDistance(dist, sptSet, size);
  
	sptSet[u] = true;

	for (int v = 0; v < size; v++)
		if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v])
			dist[v] = dist[u] + graph[u][v];
     }
	printSolution(dist, size);
}
  
int main(int argc, char** argv){
	
	if (argc < 1) exit(EXIT_FAILURE);
	int size, i, j;
	scanf("%d", &size);

	int ** graph = (int**) malloc(sizeof(int*)*size);
	
	for(i = 0; i < size ; i++){
		graph[i] = (int*) malloc(sizeof(int)*size);
		for(j= 0; j < size ; j++){
			if(i == j){
				graph[i][j] = 0;
			}else if(i > j){
				graph[i][j] = graph[j][i];
			}
			else{
				scanf("%d", &graph[i][j]);
			}
		}
		
	}
	switch(atoi(argv[1])){
		case 0: 
			primMST(graph, size);	
			break;
		case 1:
			dijkstra(graph, 0,size);
			break;
		default:
			exit(EXIT_FAILURE);
			break;			
	}		
