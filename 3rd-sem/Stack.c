#include <stdio.h>
#include<stdlib.h>
void push(int *s,int *top,int data,int size){
	if(*top==size-1)
		printf("Overflow\n");
	else
		s[++*top]=data;
}
void pop(int *s, int *top){
	if(*top==-1)
		printf("Underflow\n");
	else{
		printf("%d is deleted\n",*(s+(*top)));
		--*top;
	}
}
void peek(int *s, int *top){
	if(*top==-1)
		printf("Underflow\n");
	else
		printf("%d\n",*(s+(*top)));
}
int main(void){
	int i,n,a=-1,size,d,*s, *top;
	top=&a;
	printf("Enter the size of array: ");
		scanf("%d",&size);
	s=(int *)malloc(size*sizeof(int));
	do{
		printf("Menu:\n1. Push\n2. Pop\n3. Peek\n4. Exit\nEnter?\n");
			scanf("%d",&n);
		switch(n){
			case 1:
				printf("Enter the data: ");
					scanf("%d",&d);
				push(s,top,d,size);
			break;
			
			case 2:
				pop(s,top);
			break;
			
			case 3:
				peek(s,top);
			break;
			
			case 4:
				printf("Thank You");
			break;
			
			default:
				printf("Wrong Choice!!");
		}
	}while(n!=4);
	return 1;
}
