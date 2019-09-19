#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node* create(int d){
	struct node *n;
	n=(struct node*)malloc(sizeof(struct node));
	n->data=d;
	n->next=NULL;
	return n;
}
struct node * insertRear(struct node *start, struct node *ptr, struct node * n){
	if(start==NULL)
		start = n;
	else if(ptr->next==NULL)
		ptr->next = n;
	else
		start = insertRear(start, ptr->next, n);
	return start;
}
void show(struct node * ptr){
	if(ptr == NULL)
		printf("Underflow\n");
	else if(ptr->next != NULL){
		printf("%d -> ",ptr->data);
		show(ptr->next);
	}else
		printf("%d\n",ptr->data);
}
int main(void){
	struct node * start = NULL;
	int n,d,pos;
	do{
		printf("Menu:\n1. Insert at Rear\n2. Show\n3. Exit\nEnter: ");
			scanf("%d",&n);
		switch(n){
			case 1:
				printf("enter the data: ");
					scanf("%d",&d);
				start = insertRear(start, start, create(d));
				break;
			case 2:
				printf("The list is ");
				show(start);
				break;
			case 3:
				printf("Thank You\n");
				break;
			default:
				printf("Wrong Choice!! Try again noob\n");
		}
	}while(n!=3);
	return 1;
}
