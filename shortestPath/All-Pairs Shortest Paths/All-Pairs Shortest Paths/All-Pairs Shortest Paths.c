#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define INF 999 ; // Max, inf

int ver = 0 ;
void insertGraph() ;

int setViaVerSize(){

	int ver = 0 ;
	FILE *fps ;
	int num1 = 0;
	fps = fopen("C:\\Users\\Administrator\\Desktop\\graph_sample_directed.txt","rt");
	fscanf(fps,"%d",&num1);
	ver = num1;
	
	fclose(fps);
	return ver ;
}

int **setVia(int **arr){
	FILE *fps ;
	int i ;
	int num1 = 0 ;
	int num2 = 0 ;
	int	num3 = 0 ;
	int num4 = 0 ;

	fps = fopen("C:\\Users\\Administrator\\Desktop\\graph_sample_directed.txt","rt");
	fscanf(fps,"%d",&num1) ;

	for(i=0; i<10; i++){
		fscanf(fps,"%d %d %d",&num2, &num3, &num4);
		insertGraph(arr, num2, num3, num4);
	}

	fclose(fps);
	
	return arr ;
}

void insertGraph(int **A,int num2,int num3,int num4){
	*(*(A+num2)+num3) = num4;
}

int **Extend_Shortest_Paths(int **L,int **A){
	int **L_new ;
	int i,j,k,temp ;
	int min = INF ;

	L_new = (int **)malloc (sizeof(int*)*ver) ;
	for(i=0; i<ver; i++){
		*(L_new + i) = (int*)malloc(sizeof(int)*ver) ;
	}

	for(i=0 ; i<ver ; i++){
		for(j=0 ; j<ver ; j++){
			L_new[i][j] = INF ;
			for(k=0 ; k<ver ; k++){
				temp = L[i][k] + A[k][j] ;
				if(L_new[i][j] > temp) // 최O소ùO비¬n용¯e 저u장a
					L_new[i][j] = temp;
			}
		}
	}
	return L_new ;
}

int **SAPSP(int **A){
	int **newL ; 
	int num=1 ;
	int m,a,b,i ;

	newL = (int **)malloc (sizeof(int*)*ver);
	
	for(i=0; i<ver; i++){
		*(newL + i) = (int*)malloc(sizeof(int)*ver) ;
	}
	for(a=0; a<ver; a++){
		for(b=0; b<ver; b++){
			newL[a][b]=A[a][b] ;
		}
	}

	for(m=0; m<ver-1; m++){
		newL = Extend_Shortest_Paths(newL,A) ;
		num++ ;
		printf(" L%d\n ",num) ;

		for(a=0; a<ver; a++){
			for(b=0; b<ver; b++){
				printf("%d\t",newL[a][b]) ;
			}
			printf("\n") ;
		}
	}

	return newL ;
}
int **FAPSP(int **A){
	int **newL ;
	int **LL ;
	int num=1 ;
	int m=1 ;
	int a,b,i ;

	newL = (int **)malloc (sizeof(int*)*ver) ;

	for(i=0; i<ver; i++){
		*(newL + i) = (int*)malloc(sizeof(int)*ver) ;
	}
	for(a=0; a<ver; a++){
		for(b=0; b<ver; b++){
			newL[a][b]=A[a][b] ;
		}
	}

	while(m < ver-1){
		newL = Extend_Shortest_Paths(newL,newL) ;
		printf("\n") ;
		m = 2*m ;
		printf(" L%d\n ",m) ;

		for(a=0 ; a<ver ; a++){
			for(b=0 ; b<ver ; b++){
				printf("%d\t",newL[a][b]) ;
			}
			printf("\n") ;
		}
	}

	return newL ;
}

int main(void){
	int **graph = NULL ;
	int i, a, b ;

	ver = setViaVerSize() ;

	graph = (int **)malloc (sizeof(int*)*ver);
	for(i=0; i<ver; i++){
		*(graph + i) = (int*)malloc(sizeof(int)*ver);
	}
	for(a=0; a<ver; a++){
		for(b=0; b<ver; b++){
			if(a==b)
				graph[a][b]=0;
			else
				graph[a][b]=INF;
		}
	}

	**setVia(graph);
	printf(" L1\n ") ;

	for(a=0; a<ver; a++){
		for(b=0 ; b<ver ; b++){
			printf("%d\t",graph[a][b]) ;
		}
		printf("\n") ;
	}

	**SAPSP(graph) ;
	**FAPSP(graph) ;

	system("pause") ;

}
