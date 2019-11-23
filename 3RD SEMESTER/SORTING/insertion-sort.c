#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *arr, int n){
	int i,j, item;
	for(i=1;i<n;i++){
		j=i-1;
		item=arr[i];
		while(j>=0 && arr[j]>item)
			arr[j+1] = arr[j--];
		arr[j+1]=item;
		printf("PASS %d: ", i);
		for(j=0;j<n;j++)
			printf("%d ", arr[j]);
		printf("\n");
	}
}

int main(void){
	int *arr, n, i;
	printf("enter the size of the array: ");
		scanf("%d", &n);
	arr = (int *)malloc(n*sizeof(int));
	printf("enter the array elements:\n");
	for(i=0;i<n;i++)
		scanf("%d", &arr[i]);
	printf("******APPLYING INSERTION SORT******\n");
	insertion_sort(arr, n);
	printf("\nthe sorted array is ");
	for(i=0;i<n;i++)
		printf("%d ", arr[i]);
	return 0;
}
