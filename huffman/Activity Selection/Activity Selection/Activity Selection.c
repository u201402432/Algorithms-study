#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define LEN 11

int S[LEN] ;
int F[LEN] ;

void getArr(){
	FILE *fps ;
	int i, n1, n2 ;

	fps = fopen("C:\\Users\\Administrator\\Desktop\\sample_selection.txt","rt");

	for(i=0 ; i < LEN ; i++){
		fscanf(fps,"%d %d",&n1, &n2) ;
		S[i] = n1 ;
		F[i] = n2 ;
	}
	
	fclose(fps) ;
}

int Iterative_greedy_algorithm(int *A, int k){
	int i ;

	k=0 ;
	A[k] = k ;

	for(i=0 ; i<LEN ; i++){
		if(S[i] >= F[A[k]])
			A[++k] = i ;
	}

	return k ;
}

int main(void){

	int A[LEN] ;
	int i, k=0 ;

	getArr() ;
	
	k = Iterative_greedy_algorithm(A, k) ;

	for(i=0 ; i<=k ; i++){
		printf("%d[%d %d]",A[i]+1, S[A[i]], F[A[i]]) ;
		if(i==k)
			printf("\n");
		else
			printf(" -> ") ;
	}
	
 	system("pause") ;
    return 0;
}
  