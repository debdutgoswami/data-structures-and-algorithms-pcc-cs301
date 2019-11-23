#include <stdio.h>
#include <stdlib.h>
void insert(int *front, int *rear, int *s, int size, int data){
	if(*rear==size-1)
		printf("Overflow\n");
	else{
		++(*rear);
		*(s+*rear)=data;
	}
}
void del(int *front, int *rear, int *s){
	int a=-1;
	if(*rear==-1)
		printf("Underflow\n");
	else{
		printf("%d is deleted\n",*(s+(*front)));
		if(*front==*rear){
			rear=&a;
			*front=-1;
		}
		++(*front);
	}
}
void display(int *front, int *rear, int *s){
	if(*rear==-1)
		printf("Underflow\n");
	else{
		int i;
		printf("Queue is ");
		for(i=*front;i<=*rear;i++)
			printf("%d ",*(s+i));
		printf("\n");
	}
}
int main(void){
	int *front,*rear,size,*s,n,d,a=-1,b=0;
	front=&b;
	rear=&a;
	printf("Enter the size of the array: ");
		scanf("%d",&size);
	s=(int *)malloc(size*sizeof(int));
	do{
		printf("Menu:\n1. Insert\n2. Delete\n3. Show\n4. Exit\n");
			scanf("%d",&n);
		switch(n){
			case 1:
				printf("Enter the data to be inserted: ");
					scanf("%d",&d);
				insert(front, rear, s, size, d);
				break;
			case 2:
				del(front,rear,s);
				break;
			case 3:
				display(front,rear,s);
				break;
			case 4:
				printf("Thank You!!\n");
				break;
			default:
				printf("Wrong choice!! Try again\n");
		}
	}while(n!=4);
	return 1;
}
