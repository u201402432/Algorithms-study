#include <stdio.h>
#include <stdlib.h>
#include<time.h>

/*	function to do swap in array A
	parameter A : array
	parameter i, j : index to be swapped*/

void swap(int A[], int i, int j) {
	int temp ; 
	temp = A[i] ; 
	A[i] = A[j] ; 
	A[j] = temp ;
}

/*	Randomized-Partition
	parameter A : array to be sorted
	parameter p, r :index of start, end point in array */
int partition(int A[], int p, int r) {

    int pivotIndex = p + rand()%(r - p + 1); //랜덤한 수를 pivot으로 설정
    int pivot;
    int i = p - 1;
    int j;
    pivot = A[pivotIndex];
    swap(A, pivotIndex, r) ;
    for (j = p; j < r; j++)
    {
        if (A[j] < pivot)
        {
            i++;
            swap(A, i, j) ;
        }
    }
    swap(A, i+1, r) ;
    return i + 1 ;
}

/*	Randomized-Quicksort
	parameter A : array to be sorted
	parameter p, r : index of start, end point in array */
void quickSort(int A[], int p, int r) {
	int j ;
    if (p < r)
    {
        j = partition(A, p, r) ;
        quickSort(A, p, j-1) ;
        quickSort(A, j+1, r) ;
    }
}


// main fucntion
int main(void)
{
   int i, num[10001], n ;
	FILE *fps ;
	int temp = 0 ;
	clock_t start,end ;

	n = 10000 ;

	// input50.txt의 숫자들을 배열 num에 저장하는 부분
	fps = fopen("C:\\Users\\Administrator\\Desktop\\input\\input10000.txt","rt");
	for(i=0; i <= n ; i++){
		fscanf(fps,"%d",&temp) ;
		num[i]=temp ;
	}
	fclose(fps) ;
	
	// 정렬 시작 시간 저장
	start = clock() ;
	
	// 정렬하는 부분
	quickSort(num, 0, n-1) ;

	// 정렬 후 시간 저장
	end = clock() ;

	// 실행 시간 출력
	printf("실행시간 : %lf초\n",(end-start)/(double)1000) ;
	
	// 정렬 결과 출력
	/*
	printf("------- 정렬 결과 ------- \n") ;
	temp = 0 ;
	for(i=0 ; i<n ; i++){
		printf("%d\n",num[i]) ;	
	}
	*/

	system("pause") ;

	return 0;
}