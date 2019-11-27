#include<stdio.h>
#include<stdlib.h>

void merge(int *arr, int low, int mid, int high){
	int n1 = mid-low+1, n2 = high-mid, i=0, j=0, k = low;
	int left[n1], right[n2];
	
	for(i=0;i<n1;i++)
		left[i] = arr[low+i];
	
	for(i=0;i<n2;i++)
		right[i] = arr[mid+i+1];
	
	i=0;
	while(i<n1 && j<n2){
		if(left[i]<=right[j])
			arr[k++] = left[i++];
		else
			arr[k++] = right[j++];
	}
	while(i<n1)
		arr[k++] = left[i++];
	while(j<n2)
		arr[k++] = right[j++];
}

void merge_sort(int *arr, int low, int high){
	if(low<high){
		int mid = (low+high)/2;
		merge_sort(arr, low, mid);
		merge_sort(arr, mid+1, high);
		merge(arr, low, mid, high);
	}
}

int main(void){
	int *arr, n, i;
	printf("enter the size of array - ");
		scanf("%d", &n);
	arr = (int *)malloc(n*sizeof(int));
	printf("enter the array elements - ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	merge_sort(arr, 0, n-1);
	printf("the sorted array is ");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	return 0;
}
