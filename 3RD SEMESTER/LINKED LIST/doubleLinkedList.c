#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next,*prev;
}* start=NULL;

struct node * create(int data){
	struct node *p;
	p=(struct node *)malloc(sizeof(struct node));
	p->data=data;
	p->next=NULL;
	p->prev=NULL;
	return p;
}

void insert(struct node * n){
	struct node *ptr=start;
	if(start==NULL)
		start=n;
	else{
		while(ptr->next!=NULL)
			ptr=ptr->next;
		ptr->next=n;
		n->prev=ptr;
	}
}

void del(int data){
	struct node * ptr=start,*tmp;
	int f=0;
	if(start==NULL)
		printf("UNDERFLOW\n");
	else{
		while(ptr!=NULL){
			if(start->data==data){
				start=NULL;
				f=1;
				printf("%d is deleted\n",data);
				break;
			}
			else if(ptr->data == data){
				tmp=ptr->next;
				ptr->prev->next=tmp;
				tmp->prev=tmp->prev->prev;
				printf("%d is deleted\n",data);
				f=1;
				break;
			}
			ptr=ptr->next;
		}
		if(f==0)
			printf("NOT FOUND\n");
	}
}

void display(){
	struct node * ptr=start;
	if(start==NULL)
		printf("UNDERFLOW\n");
	else{
		while(ptr!=NULL){
			printf("%d ",ptr->data);
			ptr=ptr->next;
		}
		printf("\n");
	}
}

int main(void){
	int n,data;
	do{
		printf("Menu:\n1. Insert\n2. Display\n3. Delete\n4. Exit\nenter: ");
			scanf("%d",&n);
		switch(n){
			case 1:
				printf("enter the data: ");
					scanf("%d",&data);
				insert(create(data));
				break;
			case 2:
				display();
				break;
			case 3:
				printf("enter the value: ");
					scanf("%d",&data);
				del(data);
				break;
			case 4:
				printf("Thank You!!\n");
			
			default:
				printf("Wrong Choice!! Try again\n");
		}
	}while(n!=3);
	return 1;
}
