#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ALPHABET 26
#define MAX_LEN 255
#define MAX_ELEMENT 1000

typedef struct{
	char alpha;
	int freq;
}AlphaType;

typedef struct TreeNode{
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

void InsertHeap(HeapType *h,Element item){
	int i;
	i=++(h->heap_size);

	while(i != 1 && item.key < h->heap[i/2].key){
		h->heap[i]=h->heap[i/2];
		i/=2;
	}
	h->heap[i]=item;
}

Element DeleteHeap(HeapType *h){

	int parent=1,child=2;
	Element data,temp;

	data = h->heap[parent];
	temp = h->heap[(h->heap_size)--];

	while(child <= h->heap_size){
		if((child < h->heap_size) && (h->heap[child].key) > h->heap[child+1].key) 
			child++;
      
		if(temp.key <= h->heap[child].key) break;

		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}

	h->heap[parent]=temp;
	return data;
}

void inputmake(AlphaType *A){

	FILE *fps;
	char ap=NULL;
	int freq=0;
	int i;
	int temp=0;
	fps = fopen("C:\\Users\\Administrator\\Desktop\\sample_huffman.txt","rt");
	for(i=0; i<6; i++){
		fscanf(fps,"%c %d %d",&ap,&freq,&temp);
		A[i].alpha = ap;
		A[i].freq = freq;
	}
	fclose(fps);
}

TreeNode* MakeNode(TreeNode *left,TreeNode *right){
	TreeNode *node=(TreeNode*)malloc(sizeof(TreeNode));
	node->left_child=left;
	node->right_child=right;

	return node;
}

void PrintTree(TreeNode *p,int i,char *pCode){
	if(p)
	{
		i++;
		pCode[i]='0';
		PrintTree(p->left_child,i,pCode);
		pCode[i]='1';
		PrintTree(p->right_child,i,pCode);
		pCode[i]='\0';
	
		if(p->left_child == NULL && p->right_child == NULL)
		{
			printf("%c   %d\t %s\t\n",p->weight.alpha,p->weight.freq,pCode);
		}
	}
	
}
void HuffmanTree(AlphaType *pArr,int n){
	TreeNode *node,*temp;
	Element e,e1,e2;
	HeapType heap;
	char binaryCode[100];
	int i;

	heap.heap_size=0;

	for(i=0;i<n;i++)
	{
		node=MakeNode(NULL,NULL);  
		node->weight.alpha=pArr[i].alpha;
		e.key=node->weight.freq=pArr[i].freq;
		e.pTree=node;
		InsertHeap(&heap,e);
	}

	for(i=0;i<n-1;i++){
		e1=DeleteHeap(&heap);
		e2=DeleteHeap(&heap); 
		
		temp=MakeNode(e1.pTree,e2.pTree);

		e.key=temp->weight.freq=e1.key+e2.key;
		e.pTree=temp;

		InsertHeap(&heap,e);
	}
	e = DeleteHeap(&heap);

	PrintTree(e.pTree,-1,binaryCode);
}
void Printcode(TreeNode *p,int i,char *pCode,char alpha){
	if(p)
	{
		i++;
		pCode[i]='0';
		Printcode(p->left_child,i,pCode,alpha);
		pCode[i]='1';
		Printcode(p->right_child,i,pCode,alpha);
		pCode[i]='\0';
	
		if(p->left_child == NULL && p->right_child == NULL && p->weight.alpha == alpha )
		{
			printf("%s",pCode);
		}
	}
	
}
void HuffmanTreeC(AlphaType *pArr,int n,char alpha){
	TreeNode *node,*temp;
	Element e,e1,e2;
	HeapType heap;
	char binaryCode[100];
	int i;

	heap.heap_size=0;

	for(i=0;i<n;i++)
	{
		node=MakeNode(NULL,NULL);  
		node->weight.alpha=pArr[i].alpha;
		e.key=node->weight.freq=pArr[i].freq;
		e.pTree=node;
		InsertHeap(&heap,e);
	}

	for(i=0;i<n-1;i++){
		e1=DeleteHeap(&heap);
		e2=DeleteHeap(&heap); 
		
		temp=MakeNode(e1.pTree,e2.pTree);

		e.key=temp->weight.freq=e1.key+e2.key;
		e.pTree=temp;

		InsertHeap(&heap,e);
	}
	e = DeleteHeap(&heap);

	Printcode(e.pTree,-1,binaryCode,alpha); 
}

void Init(AlphaType *p){
	for(int i=0;i<ALPHABET;i++){
		p[i].alpha=i+65;
		p[i].freq=0;
	}
}

int main(void){
	int i;
    AlphaType *A;

    char *string = (char*)malloc(sizeof(char)*MAX_LEN);
    A = (AlphaType*)malloc(sizeof(AlphaType)*6);
   
    inputmake(A);

    printf("freq\t\n"); 
    for(i=0; i<6; i++){
       printf("%c %d\n",A[i].alpha,A[i].freq);
    }

    printf("Huffman code\t\n");
    HuffmanTree(A,6);

    printf("input String : ");
    scanf("%s",string);
    printf("\n");
    
	for(i=0; i<8; i++)
		HuffmanTreeC(A,6,string[i]);

	printf("\n");

	system("pause") ;
	return 0 ;
}