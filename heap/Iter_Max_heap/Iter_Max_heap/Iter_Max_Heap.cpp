#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
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

/*	Build Max-Heap
	parameter A : heap implemented as array
	parameter n : heap size */
void buildMaxHeap(int A[], int n){
	int i, index, left, right ;
	for(i = n ; i >= 0 ; i--){
		left = leftChild(i, n) ;
		right = rightChild(i, n) ;
		// �����ڽ��� ū ���
		if(left <= n && A[left] > A[i]) 
			index = left ;
		else
			index = i ;
		// ������ �ڽ��� ū���
		if(right <= n && A[right] > A[i]) 
			index = right ;
		if(index != i){
			// �ڽ��� ���� �� Ŭ���
			swap(A, i, index) ; 
			//���� heapify�� �Ѿ
			i++ ;
			continue ;
		}

	}
}

// main function
int main(void)
{
	int i, num[51], n ;
	FILE *fps ;
	int temp = 0 ;
	clock_t start,end ;

	n = 50 ;

	// input50.txt�� ���ڵ��� �迭 num�� �����ϴ� �κ�
	fps = fopen("C:\\Users\\Administrator\\Desktop\\input\\input50.txt","rt");
	for(i=0; i <= n ; i++){
		fscanf(fps,"%d",&temp) ;
		num[i]=temp ;
	}
	fclose(fps) ;
	
	// ���� ���� �ð� ����
	start = clock() ;
	
	// �����ϴ� �κ�
	for(i=0; i<sizeof(num)/sizeof(int); i++){
		buildMaxHeap(num,i) ;
	}

	// ���� �� �ð� ����
	end = clock() ;

	// ���� �ð� ���
	printf("����ð� : %lf��\n",(end-start)/(double)1000) ;
	
	// ���� ��� ���
	printf("------- ���� ��� ------- \n") ;
	temp = 0 ;
	for(i=0 ; i<n ; i++){
		printf("%d\n",num[i]) ;	
	}
	
	system("pause") ;

	return 0;
}
