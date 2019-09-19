#include<stdio.h>
#include<stdlib.h>
void display(int *arr,int size){
	int i;
	for(i=0;i<size;i++)
		printf("%4d",arr[i]);
}
void mergesort(int *arr,int low,int high){
	int mid,temp[100];
	if(low<high){
		mid=(low+high)/2;
		mergesort(arr,low,mid);
		mergesort(arr,mid+1,high);
		merge(arr,temp,low,mid,mid+1,high);
		cpy(arr,temp,low,high);
	}
}
void merge(int arr[],int temp[],int low1,int high1,int low2,int high2){
	int i=low1,j=low2,k=low1;
	while(i<=high1 && j<=high2){
		if(arr[i]<=arr[j])
			temp[k++]=arr[i++];
		else
			temp[k++]=arr[j++];
	}
	while(i<=high1)
		temp[k++]=arr[i++];
	while(j<=high2)
		temp[k++]=arr[j++];
	printf("\n...............\n");
	display(temp,k);
	printf("\n...............\n");
}
void cpy(int *arr,int *temp,int low,int high){
	int i;
	for(i=low;i<=high;i++)
		arr[i]=temp[i];
}
int main(void){
	int *arr,i,size;
	printf("enter the size: ");
		scanf("%d",&size);
	arr=(int *)malloc(size*sizeof(int));
	printf("enter the array elements:\n");
	for(i=0;i<size;i++)
		scanf("%d",&arr[i]);
	printf("The array is ");
	display(arr,size);
	mergesort(arr,0,size);
	printf("\nThe sorted array is ");
	display(arr,size);
	return 0;
}
