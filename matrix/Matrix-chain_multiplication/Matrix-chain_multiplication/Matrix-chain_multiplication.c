#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void getArr(int* num){
	FILE *fps ;
	int temp = 0 ;
	int temps[8] = {0} ;

	// input의 숫자들을 배열 num에 저장하는 부분
	fps = fopen("C:\\Users\\Administrator\\Desktop\\sample\\sample_mat2.txt","rt");
	fscanf(fps,"%d",&temp) ;
	num[7] = temp ;
	
	fscanf(fps,"%d %d %d %d %d %d %d", &num[0], &num[1], &num[2], &num[3], &num[4], &num[5], &num[6] ) ;
	
	fclose(fps) ;

}

void PRINT_OPIMAL_PARENS(int(*s)[7], int i, int j){
	if(i==j)
		printf("%d",i) ;
	else{
		printf("(") ;
		PRINT_OPIMAL_PARENS(s,i,s[i][j]) ;
		PRINT_OPIMAL_PARENS(s,s[i][j]+1,j) ;
		printf(")") ;
	}

}

/*
int find_min(int *M[7], int *p, int i, int j, int k){
	int temp = (M[i][k-1] + M[k][j] + p[i-1]*p[k]*p[j]) ;

	if(M[i][j] > temp){
		return temp ;
	}
	return M[i][j] ;
}
*/

int matrix_multiplication(int p[], int n){
  int L,i,k, j, temp;
  int M[7][7];
  int S[7][7] ;
 
  for(i=0;i<7 ; i++){
		for(j=0;j<7 ; j++){
		    M[i][j] = 0 ;
			S[i][j] = 0 ;
		}
   }
 
   for(L=2; L<7 ; L++){
         for(i=1; i<7-L+1; i++){
           j = i+L-1 ;
           M[i][j] = 999999 ;
              for(k=i; k<=j-1; k++){
					temp = M[i][k] + M[k+1][j] + p[i-1] * p[k] * p[j];
					if(temp < M[i][j]){
						M[i][j] = temp;
						S[i][j] = k ;
					}
              }
        }
  }

   

	PRINT_OPIMAL_PARENS(S,1,4) ;
	printf("\n") ;
  return M[1][4] ;
}

 int main(){
         int *num ;
		 int n ;
		 num = (int*) malloc(sizeof(int)*9) ;

		 getArr(num) ; // Get Input Data
		 n = num[7] ;
		 num[7] = 0 ;
		 printf("%d\n", matrix_multiplication(num, n));
		 system("pause") ;
         return 0;
 }
