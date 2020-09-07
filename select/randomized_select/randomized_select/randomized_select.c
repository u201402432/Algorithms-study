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

int rand_select(int *arr, int p, int r, int i) { // 배열, 시작, 찾는 값, 끝
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
   // input의 숫자들을 배열 num에 저장하는 부분
   fps = fopen("C:\\Users\\Administrator\\Desktop\\input\\input50.txt","rt") ;
   for(i=0; i <= size ; i++){
      fscanf(fps,"%d",&temp) ;
      num[i]=temp ;
   }
   fclose(fps) ;

   find = num[25] ;

   // 정렬 시작 시간 저장
   start = clock() ;

   // 정렬하는 부분
   result = rand_select(num, 0, find, size-1) ;
   // 정렬 후 시간 저장
   end = clock() ;

   // 실행 시간 출력
   printf("실행시간 : %lf초\n",(end-start)/(double)1000) ;

   // 정렬 결과 출력
   printf("------- 탐색 결과 ------- \n 찾고 싶은 값 : %d\n 찾은 값 : %d\n",find,num[result]) ;
   //printArray(result, size) ;

   system("pause") ;

   return 0;
}