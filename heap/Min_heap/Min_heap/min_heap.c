#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<time.h>

/*	Swap node i and node j in array A
	parameter A : heap implemented as array
	parameter i, j : index of node in array A */
void swap(int A[], int i, int j) {
	int temp ; 
	temp = A[i] ; 
	A[i] = A[j] ; 
	A[j] = temp ;
}

/*	function to do return parent of node i
	parameter i : index of node i */
int parent(int i) {
	return ((i-1)/2) ;
}

/*	function to do return left child of node i
	parameter i : index of node i
	parameter n : heap size */
int leftChild(int i, int n) {
	int child = (2*i + 1) ;
	if(child >= n)
		return -1 ;
	return child ; 
}

/*	function to do return right child of node i
	parameter i : index of node i
	parameter n : heap size */
int rightChild(int i, int n) {
	int child = (2*i + 2) ;
	if(child >= n)
		return -1 ;
	return child ; 
}

/*	function to do maintain the heap property
	parameter A : heap implemented as array
	parameter i : index of subtree root node 
	parameter n : heap size */
void MinHeapify(int A[], int i, int n) {
	int left = leftChild(i, n) ;
	int right = rightChild(i, n) ;
	int index ;
	// 부모보다 작은 경우
	if(left <= n && A[((i-1)/2)] > A[i]) 
		index = ((i-1)/2) ;
	else
		index = i ;

	if(index != i){
		// 부모보다 작은 경우 swap
		swap(A, i, index) ; 
		//다음 heapify로 넘어감
		MinHeapify(A ,index, n) ; 
	}
}

/*	Build Min-Heap
	parameter A : heap implemented as array
	parameter n : heap size */
void buildMinHeap(int A[], int n){
	int i ;
	for(i = n ; i > 0 ; i--)
		MinHeapify(A ,i ,n) ;
}

/*	Sort Min-heap A
	parameter A : Min-heap implemented as array
	parameter n : heap size */
void heapSort(int A[], int n) {	
	int i;
	for(i = n ; i > 0 ; i--)
		MinHeapify(A,i,n);
}

// main function
int main(void)
{
	int i, num[17], n ;
	FILE *fps ;
	int temp = 0 ;
	clock_t start,end ;

	n = 16 ;

	// input의 숫자들을 배열 num에 저장하는 부분
	fps = fopen("C:\\Users\\Administrator\\Desktop\\input\\input_small.txt","rt");
	for(i=0; i <= n ; i++){
		fscanf(fps,"%d",&temp) ;
		num[i]=temp ;
	}
	fclose(fps) ;
	
	// 정렬 시작 시간 저장
	start = clock() ;
	
	// 정렬하는 부분
	for(i=0; i<sizeof(num)/sizeof(int); i++){
		buildMinHeap(num,i) ;
	}

	// 정렬 후 시간 저장
	end = clock() ;

	// 실행 시간 출력
	printf("실행시간 : %lf초\n",(end-start)/(double)1000) ;
	
	// 정렬 결과 출력
	printf("------- 정렬 결과 ------- \n") ;
	temp = 0 ;
	for(i=0 ; i<n ; i++){
		printf("%d\n",num[i]) ;	
	}
	

	system("pause") ;

	return 0;
}
