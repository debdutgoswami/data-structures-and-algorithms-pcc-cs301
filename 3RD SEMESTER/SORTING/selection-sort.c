#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selection_sort(int *arr, int n){
	int i,j,key;
	for(i=0;i<n-1;i++){
		key = i;
		for(j=i+1;j<n;j++)
			if(arr[j]<arr[key])
				key = j;
		if(key!=i)
			swap(&arr[key], &arr[i]);
	}
}

int main(void){
	int *arr, n, i;
	printf("enter the size of the array: ");
		scanf("%d",&n);
	arr = (int *)malloc(n*sizeof(int));
	printf("enter the array elements:\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("******APPLYING THE SELECTION SORT******\n");
	selection_sort(arr, n);
	printf("\nthe sorted array is: ");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	return 0;
}
