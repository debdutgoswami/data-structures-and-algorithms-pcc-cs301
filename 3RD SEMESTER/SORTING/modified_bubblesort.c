#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
	int temp = *a;
	*a=*b;
	*b=temp;
}

void bsort(int *arr, int n){
	int i, j, flag;
	for(i=0;i<n-1;i++){
		flag = 1;
		for(j=0;j<n-i-1;j++)
			if(arr[j]>arr[j+1]){
				flag = 0;
				swap(&arr[j], &arr[j+1]);
			}
		if(flag)
			return;
		else{
			printf("PASS %d:", i+1);
			for(j=0;j<n;j++)
				printf("%d ",arr[j]);
			printf("\n");
		}
	}
}

int main(void){
	int *arr, n, i;
	printf("enter the size of the array: ");
		scanf("%d", &n);
	arr=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		scanf("%d", &arr[i]);
	printf("******APPLYING BUBBLE SORT******\n");
	bsort(arr, n);
	printf("\n");
	printf("the sorted array is: ");
	for(i=0;i<n;i++)
		printf("%d ", arr[i]);
	return 0;
}
