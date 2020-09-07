#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>

// Number of vertices in the graph
#define V 5

int minDistance(int dist[], bool sptSet[]){
   // Initialize
   int min = INT_MAX, min_index;
  
   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
  
   return min_index;
}
  
void printSolution(int dist[], int n)
{
   printf("Vertex   Distance from Source\n");
   for (int i = 0; i < V; i++)
      printf("%d \t\t %d\n", i, dist[i]);
   
}
  
void dijkstra(int graph[V][V], int src){
     int dist[V]; 
  
     bool sptSet[V];
  
     for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
  
     dist[src] = 0;
  
     for (int count = 0; count < V-1; count++){
       int u = minDistance(dist, sptSet);
  
       sptSet[u] = true;
  
       for (int v = 0; v < V; v++)
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
     }
     printSolution(dist, V);
}

void getArr(int*num){
	FILE *fps ;
	int temp = 0 , i ;
	int n1, n2, n3 ;

	// input의 숫자들을 배열 num에 저장하는 부분
	fps = fopen("C:\\Users\\Administrator\\Desktop\\알고8주\\graph_sample_dijkstra.txt","rt");
	fscanf(fps,"%d",&temp) ;
	num[0] = temp ;
	for(i=1; i < 31 ; i=i+3){
		fscanf(fps,"%d %d %d",&n1, &n2, &n3) ;
		num[i] = n1 ;
		num[i+1] = n2 ;
		num[i+2] = n3 ;
	}
	
	fclose(fps) ;

}

int main(){
	int num[31], i, j ;
	int graph[V][V] ;

	getArr(num) ;
	for(i=0 ; i<5 ; i++){
		for(j=0 ; j<5 ; j++){
			graph[i][j] = 0 ;
		}
	}

	for(i=1 ; i<30 ; i=i+3){
		graph[num[i]][num[i+1]] = num[i+2] ;
	}
	
	for(i=0 ; i<5 ; i++){
		printf("\n Dist From %d\n", i) ;
		dijkstra(graph, i);
	}

	system("pause");

    return 0;

}
