#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define N 6
#define inf 999

void printArray(int** arr)
{
	int i,j ;
    for(i=0 ; i<N ; i++){
		for(j=0 ; j<N ; j++){
			if(arr[i][j]==inf)
				printf("X ") ;
			else
				printf("%d ",arr[i][j]) ;
		}
		printf("\n") ;
	}
      
	printf("\n") ;
}

void getArr(int*num){
	FILE *fps ;
	int temp = 0 , i ;
	int n1, n2, n3 ;

	// input의C 숫?y자U들?e을¡? 배?e열?¡? num에??® 저u장a하I는?A 부?I분?¨?
	fps = fopen("C:\\Users\\Administrator\\Desktop\\graph_sample_directed.txt","rt");
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

int** doFloyd(int** via){
	// int** d = cost table
	int i, j, k ;
	int **d ; // Via Table.
    
	d = (int**)malloc(sizeof(int *)*N);
	for(i=0 ; i<N ; i++)
		d[i] = (int *)malloc(sizeof(int)*N);

	for(i=0 ; i<N ; i++)
		for(j=0 ; j<N ; j++)
			d[i][j] = inf ;
	// Init
    for (i = 0; i < N; ++i)
    {
        for (j = 0; j < N; ++j)
        {
            d[i][j] = via[i][j];
        }
    }
		// Floyd-Warshall Algorithm
    for (k = 0; k < N; ++k){
        for (i = 0; i < N; ++i){
            for (j = 0; j < N; ++j){
                if (d[i][j] > d[i][k] + d[k][j] && d[i][k] != inf && d[k][j] != inf){
                    d[i][j] = d[i][k] + d[k][j] ;
                    via[i][j] = k ;
                }
            }
        }
		printArray(via) ;
    }
	return d ;
}

int** setCostTable(int* arr){
	int **array ;
	int i, j ;
	array = (int**)malloc(sizeof(int *)*N);
	for(i=0 ; i<N ; i++)
		array[i] = (int *)malloc(sizeof(int)*N);

	
	for(i=0 ; i<N ; i++)
		for(j=0 ; j<N ; j++)
			array[i][j] = inf ;

	for(i=1 ; i<30 ; i=i+3 ){
		array[arr[i]][arr[i+1]] = arr[i+2] ;
	}

	return array ;
}
int main(void){
	int num[31], **d ;
	getArr(num) ; // Get Input Data
	d = setCostTable(num) ;
	printArray(d) ;
	doFloyd(d) ;
	system("pause") ;
    return 0;
}
