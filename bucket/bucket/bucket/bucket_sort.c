#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>

// 리스트 노드
typedef struct node {
	int value;
	struct node *link;
} node;

int* buketSort(int *ar, int size, int max) {
	node *counter, *n2,*n1;
	int *fa, temp ;
	int i,j,k=0 ;
	int n,a;
	fa = (int*)malloc(sizeof(int)*(size)) ;
	memset(fa, 0, sizeof(int)*size) ;

	max = max*10+1 ; // count배열의 크기 ;
	counter = (node*)malloc(sizeof(node)*(max)) ;

	for(i=0;i<max ;i++) { // init
		counter[i].value = 0;
		counter[i].link  = 0;
	}

	for(i=0;i<size ;i++) {
		// init
		n = ar[i];
		j = n * 100;
		j = j/10;

		// 버킷에 원소가 없을때
		if(counter[j] . value ==0 && counter[j] . link == 0)
			counter[j] . value = ar[i] ;
		else {
			// 버킷의 원소가 하나일 경우
			if(counter[j].link==0 && counter[j] .value != 0) {
				counter[j].link=(node *) malloc(sizeof(node));
				n2 = counter[j].link;
				n2 -> link = 0;
				n2 -> value =ar[i];
				continue;
			}

			n2 = counter[j].link ;
			while(n2 -> link !=0 ) { // 맨 마지막 노드
				n2 = n2 -> link;
			}
			n2 -> link =(node *) malloc(sizeof(node));
			n2 = n2 -> link;
			n2 -> link=0;
			n2 -> value = ar[i];
			
		}
	}

	// 버킷을 순서대로 정렬
	for(i=0;i<max ;i++) {
		// 버킷에 노드가 없을경우
		if(counter[i] . link ==0 && counter[i] . value == 0)
			continue;
		else {
			n1 = &counter[i];
			n2 = &counter[i] ;
			// 버킷의 원소 개수가 2이상
			if(n2 -> link != 0) {
				// 버킷별 정렬
				while(n1!=0) {
					while(n2!= 0) {
						if(n1 -> value   >  n2 -> value) {
							temp =n1 -> value;
							n1 -> value =n2 -> value;
							n2 -> value =temp;
						}
						n2 = n2 -> link;
					}
					n2 = n1 -> link;
					n1 = n1 -> link;
				}
				n1 = &counter[i];
				// 차례대로 담기
				for(; n1!=0; k++) {
					fa[k] = n1 -> value;
					n1 = n1 -> link;
				}
			}
			// 버킷에 하나의 노드가 있는 경우
			else {
				fa[k] = counter[i].value;
				k=k+1;
			}
		}
	}
	return fa;
}

int getMaxValue(int *arr, int size){
	int max = 0, i ;
	for(i=0 ; i<size ; i++){
		if(arr[i]>max)
			max = arr[i] ;
	}
	return max ;
}

void printArray(int* arr,int length)
{
	int i ;
	for(i=0 ; i<length ; i++){
		printf("INDEX : %d, VALUE : %d\n",i,arr[i]) ;
	}
}

int main(void) {
	int i,size , maxValue, num[10001] ;
	FILE *fps ;
	int temp = 0 ;
	int *result ;
	clock_t start,end ;

	size = 10000 ;

	// input의 숫자들을 배열 num에 저장하는 부분
	fps = fopen("C:\\Users\\Administrator\\Desktop\\input\\input10000.txt","rt");
	for(i=0; i <= size ; i++){
		fscanf(fps,"%d",&temp) ;
		num[i]=temp ;
	}
	fclose(fps) ;

	// 정렬 시작 시간 저장
	start = clock() ;

	temp = getMaxValue(num, size) ;
	// 정렬하는 부분
	result = buketSort(num, size, temp) ;
	// 정렬 후 시간 저장
	end = clock() ;

	// 실행 시간 출력
	printf("실행시간 : %lf초\n",(end-start)/(double)1000) ;

	// 정렬 결과 출력
	printf("------- 정렬 결과 ------- \n") ;
	//printArray(result, size) ;

	free(result);
	system("pause") ;

	return 0;
}
