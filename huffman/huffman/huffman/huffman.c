#include<stdio.h>
#include<stdlib.h>

#define ALPABET 26
#define MAX_LEN 255
#define MAX_ELEMENT 1000

typedef struct{
	char alpha;
	int freq;
}AlphaType;
typedef struct{
	AlphaType weight;
	TreeNode *left_child;
	TreeNode *right_child;
}TreeNode;
typedef struct{
	TreeNode *pTree;
	int key;
}Element;
typedef struct{
	Element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

void InsertHeap(HeapType *h,Element item)
{
	int i;
	i=++(h->heap_size);

	while(i != 1 && item.key < h->heap[i/2].key) // 부모노드와 비교
	{
		h->heap[i]=h->heap[i/2];
		i/=2;
	}

	h->heap[i]=item;
}
Element DeleteHeap(HeapType *h)
{
	int parent=1,child=2;
	Element data,temp;

	data = h->heap[parent];
	temp = h->heap[(h->heap_size)--]; // 삭제에 의한 size 감소

	while(child <= h->heap_size)
	{
		 //자식 노드간 작은 수 비교 
		if((child < h->heap_size) && (h->heap[child].key) > h->heap[child+1].key) 
			child++;
		
		if(temp.key <= h->heap[child].key) break;

		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2; // 다음 자식 노드와 비교
	}

	h->heap[parent]=temp;
	return data;
}
void inputmake(AlphaType *A){
	FILE *fps;
	char ap=NULL;
	int freq=0;
	int i;
	fps = fopen("C:\\input\\sample_huffman.txt","rt");
	for(i=0; i < 6; i++){ // 각 줄의 간선 연결정보를 heap에 넣어줌
		fscanf(fps,"%c %d",ap,freq);
		A[i].alpha = ap;
		A[i].freq = freq;
	}
	fclose(fps);
}
int main(void){
	int i;
	AlphaType *A;
	A=(AlphaType*)malloc(sizeof(AlphaType)*6);
	inputmake(A);
	for(i=0; i<6; i++){
		printf("%c %d",A[i].alpha,A[i].freq);
	}
}
