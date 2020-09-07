#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>

// ����Ʈ ���
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

	max = max*10+1 ; // count�迭�� ũ�� ;
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

		// ��Ŷ�� ���Ұ� ������
		if(counter[j] . value ==0 && counter[j] . link == 0)
			counter[j] . value = ar[i] ;
		else {
			// ��Ŷ�� ���Ұ� �ϳ��� ���
			if(counter[j].link==0 && counter[j] .value != 0) {
				counter[j].link=(node *) malloc(sizeof(node));
				n2 = counter[j].link;
				n2 -> link = 0;
				n2 -> value =ar[i];
				continue;
			}

			n2 = counter[j].link ;
			while(n2 -> link !=0 ) { // �� ������ ���
				n2 = n2 -> link;
			}
			n2 -> link =(node *) malloc(sizeof(node));
			n2 = n2 -> link;
			n2 -> link=0;
			n2 -> value = ar[i];
			
		}
	}

	// ��Ŷ�� ������� ����
	for(i=0;i<max ;i++) {
		// ��Ŷ�� ��尡 �������
		if(counter[i] . link ==0 && counter[i] . value == 0)
			continue;
		else {
			n1 = &counter[i];
			n2 = &counter[i] ;
			// ��Ŷ�� ���� ������ 2�̻�
			if(n2 -> link != 0) {
				// ��Ŷ�� ����
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
				// ���ʴ�� ���
				for(; n1!=0; k++) {
					fa[k] = n1 -> value;
					n1 = n1 -> link;
				}
			}
			// ��Ŷ�� �ϳ��� ��尡 �ִ� ���
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

	// input�� ���ڵ��� �迭 num�� �����ϴ� �κ�
	fps = fopen("C:\\Users\\Administrator\\Desktop\\input\\input10000.txt","rt");
	for(i=0; i <= size ; i++){
		fscanf(fps,"%d",&temp) ;
		num[i]=temp ;
	}
	fclose(fps) ;

	// ���� ���� �ð� ����
	start = clock() ;

	temp = getMaxValue(num, size) ;
	// �����ϴ� �κ�
	result = buketSort(num, size, temp) ;
	// ���� �� �ð� ����
	end = clock() ;

	// ���� �ð� ���
	printf("����ð� : %lf��\n",(end-start)/(double)1000) ;

	// ���� ��� ���
	printf("------- ���� ��� ------- \n") ;
	//printArray(result, size) ;

	free(result);
	system("pause") ;

	return 0;
}
