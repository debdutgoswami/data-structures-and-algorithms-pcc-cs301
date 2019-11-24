#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void TOH(int n, char A, char B, char C){
	if(n==1)
		printf("%c to %c\n",A,C);
	else{
		TOH(n-1,A,C,B);
		TOH(1,A,B,C);
		TOH(n-1,B,A,C);
	}
}

int main(void){
	int n;
	printf("enter the number of disk: ");
		scanf("%d",&n);
	printf("\n***moving disks***\n\n");
	TOH(n,'A','B','C');
	printf("\n***done***\n");
	n = (int)pow(2,n) - 1;
	printf("\ntotal number of steps needed is %d\n",n);
	return 0;
}
