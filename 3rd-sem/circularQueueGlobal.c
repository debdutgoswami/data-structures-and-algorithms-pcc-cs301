#include <stdio.h>
#include <stdlib.h>
#define max 5
int arr[max],front=-1,rear=-1;
int isEmpty(){
	return rear==-1;
}
int isFull(){
	return ((front==0 && rear==max-1) || rear==front-1);
}
void insert(int item){
    if(isFull())
        printf("OVERFLOW\n");
    else{
        if(front==-1)
            front++;
        rear=(rear+1)%max;
        *(arr+rear)=item;
    }
}
void del(){
	if(isEmpty())
		printf("UNDERFLOW\n");
	else{
		printf("%d is deleted\n",arr[front]);
		if(front==rear){
			front=rear=-1;
		}else
			front=(front+1)%max;
	}
}
void display(){
	int i;
	if(isEmpty())
		printf("UNDERFLOW");
	else{
		if(front<=rear)
			for(i=front;i<=rear;i++)
				printf("%d ",arr[i]);
			
		else{
			for(i=front;i<max;i++)
				printf("%d ",arr[i]);
			for(i=0;i<=rear;i++)
				printf("%d ",arr[i]);
		}
	}
	printf("\n");
}
int main(void){
    int n,data;
    while(1){
    	printf("Menu:\n1. Insert\n2. Delete\n3. Show\n4. Exit\nEnter your choice: ");
			scanf("%d",&n);
		switch(n){
			case 1:
				printf("enter the data: ");
					scanf("%d",&data);
					insert(data);
				break;
			
			case 2:
				del();
				break;
			
			case 3:
				display();
				break;
			
			case 4:
				printf("Thank You\n");
				exit(0);
				
			default:
				printf("Wrong choice, Try again!!\n");
		}
	}
    return 0;
}

