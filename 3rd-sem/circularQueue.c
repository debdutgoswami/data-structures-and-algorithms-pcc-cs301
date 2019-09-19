#include<stdio.h>
#include<stdlib.h>
void insert(int *front, int *rear, int *s, int size, int data ){
	if((*rear==size-1 && *front==0)||(*rear==*front-1))
		printf("Overflow\n");
	else{
		if(*rear==size-1)
			*rear=*rear-size;
		if(*front==-1)
			*front=*front+1;
		*(s+(++*rear))=data;
	}
}
void delQueue(int *front, int *rear, int *s, int size){
	if(*front==-1)
		printf("Underflow\n");
	else{
		printf("%d is deleted\n",*(s+*front));
		if(*front==size-1)
			*front=*front-size+1;
		else if(*front==*rear){
			*front=(*front-*front)-1;
			*rear=(*rear-*rear)-1;
		}else
			*front=*front+1;
			
	}
}
void show(int *front, int *rear, int *s, int size){
	int i;
	if(*front==-1)
		printf("Underflow\n");
	else{
		printf("The Circular Queue is ");
		if(*rear >= *front)
			for(i=*front;i<=*rear;i++)
				printf("%d ", *(s+i));
		else if(*rear < *front){
			for(i=*front;i<=size-1;i++)
				printf("%d ", *(s+i));
			for(i=0;i<=*rear;i++)
				printf("%d ", *(s+i));
		}
		printf("\n");		
	}
}
int main(void){
	int *s, *front, *rear, size, data, n, a=-1, b=-1;
	front=&a;
	rear=&b;
	printf("Enter the size of the queue: ");
		scanf("%d", &size);
	s=(int *)malloc(size*sizeof(int));
	do{
		printf("Menu:\n1. Insert\n2. Delete\n3. Show\n4. Exit\nEnter your choice: ");
			scanf("%d",&n);
		switch(n){
			case 1:
				printf("enter the data: ");
					scanf("%d",&data);
					insert(front, rear, s, size, data);
				break;
			
			case 2:
				delQueue(front, rear, s, size);
				break;
			
			case 3:
				show(front, rear, s, size);
				break;
			
			case 4:
				printf("Thank You\n");
				break;
				
			default:
				printf("Wrong choice, Try again!!\n");
		}
	}while(n!=4);
	return 1;
}
