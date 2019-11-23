#include<stdio.h>
#include<stdlib.h>
struct node{
	int data,priority;
	struct node * next;
}*start=NULL;
struct node * create(int data,int priority){
	struct node * ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	ptr->data=data;
	ptr->priority=priority;
	ptr->next=NULL;
	return ptr;
}
void insertSorted(struct node * n){
	struct node * ptr,*prev;
	if(start==NULL)
		start=n;
	else{
		/*if(ptr->priority>n->priority){
			start=n;
			n->next=ptr;
			return;
		}
		while(ptr->next!=NULL){
			if(ptr->next->priority>n->priority){
				n->next=ptr->next;
				ptr->next=n;
				return;
			}
			ptr=ptr->next;
		}
		ptr->next=n;
		*/
		for(ptr=start;ptr!=NULL&&ptr->priority<=n->priority;prev=ptr,ptr=ptr->next);
		if(ptr==start){
			n->next=start;
			start=n;
		}else{
			n->next=ptr;
			prev->next=n;
		}
	}
}
void pop(){
	if(start==NULL)
		printf("Underflow\n");
	else{
		printf("%d is poped\n",start->data);
		start=start->next;
	}
}
void display(){
	struct node *ptr=start;
	if(start==NULL)
		printf("Underflow\n");
	else{
		while(ptr!=NULL){
			printf("%d ",ptr->data);
			ptr=ptr->next;
		}
		printf("\n");
	}
}
int main(void){
	int data,n,prio;
	while(1){
		printf("Menu:\n1.Insert\n2.Pop\n3.Display\n4.Exit\nenter: ");
			scanf("%d",&n);
		switch(n){
			case 1:
				printf("enter the data: ");
					scanf("%d",&data);
				printf("enter the priority: ");
					scanf("%d",&prio);
				insertSorted(create(data,prio));
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("Thank You\n");
				exit(0);
			default:
				printf("Wrong Choice!! Try again");
		}
	}
	return 1;
}
