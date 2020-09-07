#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>

int getMaxValue(int arr[],int length)
{
    int maxValue, i ;

	maxValue = 0 ;
    for(i=0 ; i<length ; i++){
        if(arr[i] > maxValue) 
			maxValue = arr[i] ;
    }
    return maxValue ;
}

int* countingSort(int maxValue, int arr[],int length)
{
    int i, j, value, arrIndex, count ;
	int* bucket ;
	
	bucket = (int*)malloc(sizeof(int)*(maxValue+1)) ;
	memset(bucket, 0, sizeof(int)*maxValue+1) ;

	for(i=0 ; i<=length ; i++){
        bucket[ arr[i] ]++ ;
    }

	for(i=1 ; i<maxValue ; i++){
		bucket[i] += bucket[i-1] ;
	}

	arrIndex = 0 ;
	for(i=1 ; i<maxValue ; i++){
		if(bucket[i]!=bucket[i-1]){
			for(j=bucket[i] ; j>bucket[i-1] ; j--){
				arr[arrIndex] = i ;
				arrIndex ++ ;
			}
		}
	}

	return arr ;
}

void printArray(int* arr,int length)
{
	int i ;
    for(i=0 ; i<length ; i++){
		//if(arr[i]!=0 && arr[i]>=0)
		printf("INDEX : %d, VALUE : %d\n",i,arr[i]) ;
	}
      
}

// main function
int main(void)
{
	int i,n, maxValue, num[10001] ;
	FILE *fps ;
	int temp = 0 ;
	int *bucket ;
	clock_t start,end ;

	n = 10000 ;

	// input�� ���ڵ��� �迭 num�� �����ϴ� �κ�
	fps = fopen("C:\\Users\\Administrator\\Desktop\\input\\input10000.txt","rt");
	for(i=0; i <= n ; i++){
		fscanf(fps,"%d",&temp) ;
		num[i]=temp ;
	}
	fclose(fps) ;
	
	// ���� ���� �ð� ����
	start = clock() ;

	maxValue = getMaxValue(num, sizeof(num)/sizeof(int)) ;
	bucket = (int*)malloc(sizeof(int)*(maxValue+1)) ;
	// �����ϴ� �κ�
	bucket = countingSort(maxValue, num, n) ;
	// ���� �� �ð� ����
	end = clock() ;

	// ���� �ð� ���
	printf("����ð� : %lf��\n",(end-start)/(double)1000) ;
	
	// ���� ��� ���
	printf("------- ���� ��� ------- \n") ;
	//printArray(bucket, n) ;
	
	system("pause") ;

    return 0;
}
