#include <stdio.h>
#include <stdlib.h>
/*test data:
size = 7
elements = {25,35,18,9,46,70,48}
*/
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void insert(int *heap, int n, int data){
	int p;
	n=n+1;
	heap[n]=data;
	p=n/2;
	while(p>0 && heap[p]<heap[n]){
		swap(&heap[p], &heap[n]);
		n=p;
		p=n/2;
	}
}

void heapify(int *heap, int n, int pos){
	int left=2*pos, right=2*pos+1, largest=pos;
	if(left<=n && heap[left]>heap[largest])
		largest=left;
	if(right<=n && heap[right]>heap[largest])
		largest=right;
	if(largest!=pos){
		swap(&heap[largest], &heap[pos]);
		heapify(heap, n, largest);
	}
}

void heap_sort(int *heap, int n){
	int i;
	for(i=n;i>=1;i--){
		swap(&heap[1], &heap[i]);
		heapify(heap,i-1,1);
	}
}

void display(int *heap, int n){
	int i;
	for(i=1;i<=n;i++)
		printf("%d ", heap[i]);
	printf("\n");
}

int main(void){
	int *heap, n, i, data;
	printf("enter the size of heap: ");
		scanf("%d",&n);
	heap=(int *)malloc((n+1)*sizeof(int));
	printf("enter the heap elements:\n");
	for(i=0;i<n;i++){
		scanf("%d",&data);
		insert(heap, i, data);
	}
	printf("before sorting...\n");
	display(heap, n);
	
	heap_sort(heap, n);
	
	printf("after sorting...\n");
	display(heap, n);
	
	return 0;
}
