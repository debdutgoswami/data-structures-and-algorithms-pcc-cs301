#include<stdio.h>
#include<stdlib.h>
int lsearch(int *arr,int n,int p){
	int flag=1,i;
	for(i=0;i<n;i++)
		if(*(arr+i)==p){
			printf("Found at index %d\n",i);
			flag=0;
		}
	return flag;
}
int main(void){
	int *arr,n,i,p;
	printf("Enter the size of array: ");
		scanf("%d",&n);
	arr=(int *)malloc(n*sizeof(int));
	printf("Enter the elements in the array:\n");
	for(i=0;i<n;i++)
		scanf("%d",arr+i);
	printf("Enter the element to be searched: ");
		scanf("%d",&p);
	if(lsearch(arr,n,p))
		printf("NOT FOUND!!\n");
	return 0;
}
