#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
}*start=NULL;
struct node* create(int d){
	struct node *n;
	n=(struct node*)malloc(sizeof(struct node));
	n->data=d;
	n->next=NULL;
	return n;
}
void insert(struct node *n){
	struct node *ptr=start;
	if(start==NULL)
		start=n;
	else{
		while(ptr->next!=NULL)
			ptr=ptr->next;
		ptr->next=n;
	}
}
void show(){
	if(start==NULL)
		printf("Underflow\n");
	else{
		struct node *ptr;
		printf("The list is ");
		for(ptr=start;ptr!=NULL;ptr=ptr->next)
			printf("%d ",ptr->data);
		printf("\n");
	}
}
void rev(){
	struct node *ptr=start,*prev=NULL,*tmp=NULL;
	if(start==NULL)
		printf("Underflow\n");
	else{
		for(ptr=start,tmp=ptr->next,ptr->next=prev;ptr!=NULL;prev=ptr,ptr=tmp);
		start=prev;
		printf("The list is reversed\n");
	}
}
int main(void){
	int n,d,pos;
	do{
		printf("Menu:\n1. Insert\n2. Show\n3. Reverse\n4. Exit\nEnter: ");
			scanf("%d",&n);
		switch(n){
			case 1:
				printf("enter the data: ");
					scanf("%d",&d);
				insert(create(d));
				break;
			case 2:
				show();
				break;
			case 3:
				rev();
				break;
			case 4:
				printf("Thank You\n");
				break;
			default:
				printf("Wrong Choice!! Try again noob\n");
		}
	}while(n!=4);
	return 1;
}
