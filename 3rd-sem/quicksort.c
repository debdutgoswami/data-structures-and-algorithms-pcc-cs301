#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int partition(int *arr, int low, int high){
	int i = low-1, pivot = arr[high], j;
	
	for(j=low; j<=high-1;j++){
		if(arr[j]<=pivot){
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	return i+1;
}
void q_sort(int *arr, int low, int high){
	int p;
	if(low<high){
		p = partition(arr, low, high);
		q_sort(arr, low, p-1);
		q_sort(arr, p+1, high);
	}
}
int main(void){
	int *arr, n, i;
	printf("enter the size of the array - ");
		scanf("%d", &n);
	arr = (int *)malloc(n*sizeof(int));
	printf("enter the array elements -\n");
	for(i=0;i<n;i++)
		scanf("%d", &arr[i]);
	q_sort(arr, 0, n-1);
	printf("the sorted array is - ");
	for(i=0;i<n;i++)
		printf("%d ", arr[i]);
	return 0;
}
