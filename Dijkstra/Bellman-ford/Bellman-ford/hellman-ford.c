#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <math.h>

/* bellman-ford.c57.  C57 code to run the Bellman-Ford algorithm on a
   small directed graph. */

#include <stdio.h>

/* Relax edge (u,v) with weight w. */
void relax(int u, int v, double w, double d[], int pi[]) {
  if (d[v] > d[u] + w) {
    d[v] = d[u] + w;
    pi[v] = u;
  }
}

/* Initialize a single-source shortest-paths computation. */
void initialize_single_source(double d[], int pi[], int s, int n) {
  int i;
  for (i = 1; i <= n; ++i) {
    d[i] = 1000000000.0;
    pi[i] = 0;
  }

  d[s] = 0.0;
}

/* Run the Bellman-Ford algorithm from vertex s.  Fills in arrays d
   and pi. */
int bellman_ford(int first[], int node[], int next[], double w[], double d[],
		 int pi[], int s, int n) {
  int u, v, i, j;

  initialize_single_source(d, pi, s, n);

  for (i = 1; i <= n-1; ++i) {
    for (u = 1; u <= n; ++u) {
      j = first[u];

      while (j > 0) {
	v = node[j];
	relax(u, v, w[j], d, pi);
	j = next[j];
      }
    }
  }

  for (u = 1; u <= n; ++u) {
    j = first[u];

    while (j > 0) {
      v = node[j];
      if (d[v] > d[u] + w[j])
		return 0;
      j = next[j];
    }
  }

  return 1;
}

void printArray(int* arr)
{
	int i ;
    for(i=0 ; i<31 ; i++){
		printf("INDEX : %d, VALUE : %d\n",i,arr[i]) ;
	}
      
}

void getArr(int*num){
	FILE *fps ;
	int temp = 0 , i ;
	int n1, n2, n3 ;

	// input의 숫자들을 배열 num에 저장하는 부분
	fps = fopen("C:\\Users\\Administrator\\Desktop\\graph_sample_bellman.txt","rt");
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

int main(void)
{
	int first[6], node[11], next[11], pi[6], num[31];
	double w[11], d[6];
	int s;
	int i, j;
	int ok;
	clock_t start,end ;

	getArr(num) ; // Get Input Data

	// clock start
	start = clock() ;
	
	// search
	first[1] = 1 ;
	first[2] = 3 ;
	first[3] = 6 ;
	first[4] = 8 ;
	first[5] = 9 ;

	j = 0 ;
	for(i=1 ; i<31 ; i=i+3){
		node[j] = num[i] ;
		next[j] = num[i+1] ;
		w[j] = num[i+2] ;
		j++ ;
	}
	
	for(i=1 ; i<6 ; i++){
		ok = bellman_ford(first, node, next, w, d, pi, i, 5);
	
		printf("bellman_ford returns ");
		printf("%d\n\n", ok);

		for (i = 1; i <= 5; ++i) {
			printf("%d: %f  %d\n", i, d[i], pi[i]);
		}
	}

	// clock stop
	end = clock() ;

	// print using time
	printf("실행시간 : %lf초\n",(end-start)/(double)1000) ;
	
	// print result
	//printf("------- 정렬 결과 ------- \n") ;
	//printArray(num) ;
	
	system("pause") ;

    return 0;
}
