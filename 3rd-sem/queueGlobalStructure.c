#include<stdio.h>
#include<stdlib.h>
#define MAX 5
typedef struct Queue{
	int arr[MAX],front,rear;
}queue;
queue q={{0},-1,-1};
int isEmpty(){
	return q.front==-1;
}
int isFull(){
	return q.rear==MAX-1;
}
void enqueue(int item){
	if(isFull())
		printf("Overflow\n");
	else{
		if(isEmpty())
			q.front=0;
		q.arr[++q.rear]=item;
	}
}
void dequeue(){
	if(isEmpty())
		printf("Underflow\n");
	else{
		printf("%d is deleted.\n",q.arr[q.front++]);
		if(q.front==MAX)
			q.front=q.rear=-1;
	}
}
void display(){
	int i;
	if(isEmpty())
		printf("Underflow\n");
	else{
		for(i=q.front;i<=q.rear;i++)
			printf("%d ",q.arr[i]);
		printf("\n");
	}
}
int main(void){
	int n,data;
	do{
		printf("Menu:\n1. Insert\n2. Delete\n3. Display\n4.Exit\nenter: ");
			scanf("%d",&n);
		switch(n){
			case 1:
				printf("enter the data: ");
					scanf("%d",&data);
				enqueue(data);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("Thank You!!\n");
				exit(0);
			default:
				printf("Wrong Choice!! Try again\n");
		}
	}while(1);
	return 1;
}
