#include<stdio.h>
#include<stdlib.h>
void tuple(int **tarr,int **arr,int c,int m, int n){
	int i,j,k=1;
	tarr[0][0]=m;
	tarr[0][1]=n;
	tarr[0][2]=c-1;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			if(arr[i][j]!=0){
				tarr[k][0]=i;
				tarr[k][1]=j;
				tarr[k++][2]=arr[i][j];
			}
}
void display(int **a,int m,int n){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++)
			printf("%3d",a[i][j]);
		printf("\n");
	}
}
int input(int **arr,int m,int n){
	int i,j,c=0;
	printf("Enter the elements:\n");
	for(i=0;i<m;i++)
		for(j=0;j<n;j++){
			scanf("%d",&arr[i][j]);
			if(arr[i][j]!=0)
				c++;
		}
	return c;
}
int main(void){
	int **arr,**tarr,m,n,i,c=0;
	printf("Enter the row X column of the given matrix:\n");
		scanf("%d %d",&m,&n);
	arr=(int **)malloc(m*sizeof(int *));	
	for(i=0;i<m;i++)
		arr[i]=(int *)malloc(n*sizeof(int));
	c=input(arr,m,n);
	printf("The entered matrix is\n");
	display(arr,m,n);
	if(c>((m*n)/2))
		printf("NOT SPARSE MATRIX!!\n");
	else{
		c++;
		tarr=(int **)malloc(c*sizeof(int *));	
		for(i=0;i<c;i++)
			tarr[i]=(int *)malloc(3*sizeof(int));
		tuple(tarr,arr,c,m,n);
		printf("The three-tuple matrix is:\n");
		display(tarr,c,3);	
	}	
	return 1;
}
