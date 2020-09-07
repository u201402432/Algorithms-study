#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <math.h>

void radixSort(int *data, int size, int p, int k) {
    int *count, *tmp ;
    int index, pval, i, j, n;
   
    if ( (count=(int*)malloc(k*sizeof(int))) == NULL ){
		memset(count, 0, sizeof(int)*k) ;
		return;
	}
    if ( (tmp=(int*)malloc(size*sizeof(int))) == NULL ){
		memset(tmp, 0, sizeof(int)*size) ;
		return;
	}
    for (n=0; n<p; n++) {
      for (i=0; i<k; i++) 
        count[i] = 0;
      // ��ġ ���
      
      pval = (int)pow((double)k, (double)n);
      
      for (j=0; j<size; j++) {
        index = (int)(data[j] / pval) % k;
        count[index] = count[index] + 1;
      }
      
      for (i=1; i<k; i++) {
        count[i] = count[i] + count[i-1];
      }
     
      // ������� ���
      for (j=size-1; j>=0; j--) {
        index = (int)(data[j] / pval) % k;
        tmp[count[index] -1] = data[j];
        count[index] = count[index] - 1;
      }

      memcpy(data, tmp, size * sizeof(int));
    }

	free(count) ;
	free(tmp) ;

}

int count_large(int arr[], int n){
	int i, j, big ;

	big = arr[0] ;
	for(i=1 ; i<n ; i++){
		if(big < arr[i])
			big = arr[i] ;
	}

	j=0 ;
	while(big != 0){
		big= big/10 ;
		j++ ;
	}

	return j ;
}
void printArray(int* arr,int length)
{
	int i ;
    for(i=0 ; i<length ; i++){
		printf("INDEX : %d, VALUE : %d\n",i,arr[i]) ;
	}
      
}

int main(void)
{
	int i,n, maxValue, num[5002] ;
	FILE *fps ;
	int temp = 0 ;
	clock_t start,end ;

	n = 5000 ;

	// input�� ���ڵ��� �迭 num�� �����ϴ� �κ�
	fps = fopen("C:\\Users\\Administrator\\Desktop\\input\\input10000.txt","rt");
	for(i=0; i <= n ; i++){
		fscanf(fps,"%d",&temp) ;
		num[i]=temp ;
	}
	fclose(fps) ;
	
	temp = count_large(num, n) ;

	// ���� ���� �ð� ����
	start = clock() ;
	
	// �����ϴ� �κ�
	radixSort(num, n, temp, 10) ; // (�迭, �迭ũ��, �ִ� �ڸ���, ����)

	// ���� �� �ð� ����
	end = clock() ;

	// ���� �ð� ���
	printf("����ð� : %lf��\n",(end-start)/(double)1000) ;
	
	// ���� ��� ���
	printf("------- ���� ��� ------- \n") ;
	//printArray(num, n) ;
	
	system("pause") ;

    return 0;
}
