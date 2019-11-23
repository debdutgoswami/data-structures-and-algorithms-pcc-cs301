#include<stdio.h>
#include<stdlib.h>
#define max 5
typedef struct Queue{
	int arr[max], front, rear;
}queue;
queue q={{0},-1,-1};
int isEmpty(){
	return (q.front==-1 && q.rear==-1);
}
int isFull(){
	return ((q.rear==max-1 && q.front==0) || (q.rear+1==q.front));
}
void insertFront(int item){
	if(isFull())
		printf("Overflow\n");
	else{
		if(isEmpty()){
			q.rear=0;
			q.front=1;
		}
		q.front=(q.front-1)%max;
		q.arr[q.front] = item;
	}
}
void insertRear(int item){
	if(isFull())
		printf("Overflow\n");
	else{
		if(isEmpty())
			q.front=0;
		q.rear=(q.rear+1)%max;
		q.arr[q.rear] = item;
	}
}
void deleteFront(){
	if(isEmpty())
		printf("Underflow\n");
	else{
		printf("%d is deleted from the queue.\n",q.arr[q.front]);
		q.front=(q.front+1)%max;
		if(q.front-1 == q.rear)
			q.front=q.rear=-1;
	}
}
void deleteRear(){
	if(isEmpty())
		printf("Underflow\n");
	else{
		printf("%d is deleted from the queue.\n",q.arr[q.rear]);
		q.rear=(q.rear-1)%max;
		if(q.rear+1==q.front)
			q.front=q.rear=-1;
	}
}
void display(){
	int i;
	if(isEmpty())
		printf("Underflow");
	else if(q.front>q.rear){
		for(i=q.front;i<max;i++)
			printf("%d ",q.arr[i]);
		for(i=0;i<=q.rear;i++)
			printf("%d ",q.arr[i]);
	}else
		for(i=q.front;i<=q.rear;i++)
			printf("%d ",q.arr[i]);
	printf("\n");
}
int main(void){
	int item,n;
	do{
		printf("Menu:\n1. Insert at Front\n2. Insert at Rear\n3. Delete at Front\n4. Delete at Rear\n5. Display\n6. Exit\nenter: ");
			scanf("%d",&n);
		switch(n){
			case 1:
				printf("enter the element to be inserted: ");
					scanf("%d",&item);
				insertFront(item);
				break;
			case 2:
				printf("enter the element to be inserted: ");
					scanf("%d",&item);
				insertRear(item);
				break;
			case 3:
				deleteFront();
				break;
			case 4:
				deleteRear();
				break;
			case 5:
				display();
				break;
			case 6:
				printf("Thank You\n");
				exit(0);
			default:
				printf("Wrong Choice. Try again!!\n");
		}
	}while(1);
	return 1;
}
