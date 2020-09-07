#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>

void swap(int *arr, int i, int j){
   int tmp ;
   if(i != j){
	tmp = arr[i] ;
	arr[i] = arr[j] ;
	arr[j] = tmp ;
   }
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
   int pivot = p+rand()%(r-p) ;
   swap(arr, p, pivot) ;
   i = p+1 ;
   for(j=p+1 ; j<=r ; j++){
      if(arr[j]<=arr[p]){
         swap(arr, j, i) ;
         i++ ;
      }
   }
   swap(arr, pivot, i-1) ;
   return i-1 ;
}

int rand_select(int *arr, int p, int r, int i) { // �迭, ����, ã�� ��, ��
	int q, k ;
   if(arr[p]==r){
	   return p ;
   }
    
   if(p==i){
	   return i ;
   }

   q = partition(arr,p,i) ;
   printf("pivot:%d , arr[%d] = %d\n",q, q,arr[q]) ;

  if(arr[q]==r){
	  return q ;
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
   for(i=0; i <= size ; i++){
      fscanf(fps,"%d",&temp) ;
      num[i]=temp ;
   }
   fclose(fps) ;

   find = num[25] ;

   // ���� ���� �ð� ����
   start = clock() ;

   // �����ϴ� �κ�
   result = rand_select(num, 0, find, size-1) ;
   // ���� �� �ð� ����
   end = clock() ;

   // ���� �ð� ���
   printf("����ð� : %lf��\n",(end-start)/(double)1000) ;

   // ���� ��� ���
   printf("------- Ž�� ��� ------- \n ã�� ���� �� : %d\n ã�� �� : %d\n",find,num[result]) ;
   //printArray(result, size) ;

   system("pause") ;

   return 0;
}