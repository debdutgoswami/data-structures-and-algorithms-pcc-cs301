#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void insert(int *heap, int n, int size, int item){
	int p;
	if(n==size)
		printf("heap is full!!\n");
	else{
		n = n+1;
		heap[n] = item;
		p = n/2;
		while(p>0 && heap[p]<heap[n]){
			swap(&heap[p], &heap[n]);
			n = p;
			p=p/2;
		}
	}
}

void display(int *heap, int n){
	int i;
	for(i=1;i<=n;i++)
		printf("%d ",heap[i]);
	printf("\n");
}

void heapify(int *heap, int n, int pos){
	int left=2*pos, right=2*pos + 1, largest=pos;
	if(left<=n && heap[largest]<heap[left])
		largest=left;
	if(right<=n && heap[largest]<heap[right])
		largest=right;
	if(largest!=pos){
		swap(&heap[largest], &heap[pos]);
		heapify(heap, n, largest);
	}
}

void delete_node(int * heap, int n, int pos){
	heap[pos]=heap[n--];
	heapify(heap, n, pos);
}

int main(void){
	int *heap, size, i, n=0, data, pos;
	printf("enter the size of the heap tree: ");
		scanf("%d", &size);
	heap = (int *)malloc(size+1*sizeof(int));
	printf("HEAP FUNCTIONS:\n1. insert\n2. delete\n3. show\n4. exit\n");
	while(1){
		printf("enter: ");
			scanf("%d", &i);
		switch(i){
			case 1:
				printf("enter the data: ");
					scanf("%d", &data);
				insert(heap, n++,size,data);
				break;
			
			case 2:
				printf("enter the position to be deleted: ");
					scanf("%d",&pos);
				delete_node(heap, n--, pos);
				break;
			
			case 3:
				display(heap, n);
				break;
			
			case 4:
				printf("thank you!!\n");
				exit(0);
			
			default:
				printf("try again!!\n");
				break;
		}
	}
	return 0;
}
