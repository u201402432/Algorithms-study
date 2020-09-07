#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>

void swap(int *arr, int i, int j){
   int tmp ;
   if(i != j && j>=0 && i>=0){
	tmp = arr[i] ;
	arr[i] = arr[j] ;
	arr[j] = tmp ;
   }
}

int findMid(int *arr, int i, int j){
	int k, q ;
	for(q=i ; q<j ; q++){
		for(k=q ; k<j ; k++){
			if(arr[i]>arr[k])
				swap(arr, i, k) ;
		}
	}
	return i+(j-i)/2 ;
}
int getPivot(int *arr, int i, int j){
	int k, q, *mid, index ;
	mid = (int*)malloc(sizeof(int)*((j-i)/5+1) ) ;
	memset(mid,0,(j-i)/5+1) ;
	index = 0 ;
	for(k=i ; k<j ; k=k+5){
		mid[index]=findMid(arr,i,i+5) ;
		index ++ ;
		if(k+5>j){
			mid[index] = findMid(arr,k,j) ;
			index++ ;
			break ;
		}
	}
	
	for(k=0 ; k<index ; k++){
		for(q=k ; q<index ; q++){
			if(mid[k]>mid[q])
				swap(mid, k, q) ;
		}
	}

	return mid[index/2] ;

}

void printArray(int* arr,int length)
{
   int i ;
   for(i=0 ; i<length ; i++){
      printf("INDEX : %d, VALUE : %d\n",i,arr[i]) ;
   }
}
int partition(int *arr, int p, int r){
   int i, j, tmp ;
   int pivot = getPivot(arr, p, r) ;
   swap(arr, p, pivot) ;
   i = p+1 ;
   for(j=p+1 ; j<=r ; j++){
      if(arr[j]<=arr[p]){
         swap(arr, j, i) ;
         i++ ;
      }
   }
   swap(arr, pivot, i-1) ;
   return i ;
}

int rand_select(int *arr, int p, int r, int i) { // �迭, ����, ã�� ��, ��
	int q, k ;
   if(arr[p]==r){
	   return arr[p] ;
   }
    
   if(p==i){
	   return arr[i] ;
   }

   q = partition(arr,p,i) ;
   printf("pivot:%d , arr[%d] = %d\n",q, q,arr[q]) ;

  if(arr[q]==r){
	  return arr[q] ;
  }
   else if(r<arr[q])
      return rand_select(arr, p, r, q-1) ;
   else
      return rand_select(arr, q+1, r,i) ;
}



int main(void) {
   int i,size , maxValue, num[51], find ;
   FILE *fps ;
   int temp = 0 ;
   int result ;
   clock_t start,end ;

   size = 50 ;
   // input�� ���ڵ��� �迭 num�� �����ϴ� �κ�
   fps = fopen("C:\\Users\\Administrator\\Desktop\\input\\input50.txt","rt") ;
   for(i=0; i < size ; i++){
      fscanf(fps,"%d",&temp) ;
      num[i]=temp ;
   }
   fclose(fps) ;

   find = num[30] ;

   // ���� ���� �ð� ����
   start = clock() ;

   // �����ϴ� �κ�
   temp = rand_select(num, 0, find, size-1) ;
   // ���� �� �ð� ����
   end = clock() ;

   // ���� �ð� ���
   printf("����ð� : %lf��\n",(end-start)/(double)1000) ;

   // ���� ��� ���
   printf("------- ���� ��� ------- \n%d == %d\n",find,temp) ;
   //printArray(result, size) ;

   system("pause") ;

   return 0;
}