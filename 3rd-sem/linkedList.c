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
void insertFront(struct node *n){
	if(start==NULL)
		start=n;
	else{
		n->next=start;
		start=n;
	}		
}
void insertRear(struct node *n){
	struct node *ptr=start;
	if(start==NULL)
		start=n;
	else{
		while(ptr->next!=NULL)
			ptr=ptr->next;
		ptr->next=n;
	}
}
void insertPos(struct node *n, int pos){
	struct node *ptr;
	if(start==NULL)
		start=n;
	else{
		struct node *ptr,*prev;
		int i=1;
		for(ptr=start;ptr!=NULL&&i<pos-1;prev=ptr,ptr=ptr->next,i++);
		if(ptr==start){
			n->next=start;
			start=n;
		}else{
			prev->next=n;
			n->next=ptr->next;	
		}
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
void del(int d){
	if(start==NULL)
		printf("Underflow\n");
	else{
		struct node *ptr, *prev;
		for(ptr=start;ptr!=NULL;prev=ptr,ptr=ptr->next)
			if(ptr->data==d)
				break;
		if(ptr==NULL)
			printf("Not Found\n");
		else{
			printf("%d is deleted\n",d);
			if(ptr==start)
				start=ptr->next;
			else
				prev->next=ptr->next;
			free(ptr);
		}
	}
}
void rev(){
	if(start==NULL)
		printf("Underflow\n");
	else{
		struct node *ptr=start, *prev=NULL, *tmp=NULL;
		while(ptr!=NULL){
			tmp=ptr->next;
			ptr->next=prev;
			
			prev=ptr;
			ptr=tmp;
		}
		start=prev;
		printf("The list is reversed\n");
	}
}
int main(void){
	int n,d,pos;
	do{
		printf("Menu:\n1. Insert at Front\n2. Insert at Rear\n3. Insert anywhere\n4. Show\n5. Delete\n6. Reverse\n7. Exit\nEnter: ");
			scanf("%d",&n);
		switch(n){
			case 1:
				printf("enter the data: ");
					scanf("%d",&d);
				insertFront(create(d));
				break;
			case 2:
				printf("enter the data: ");
					scanf("%d",&d);
				insertRear(create(d));
				break;
			case 3:
				printf("enter the data: ");
					scanf("%d",&d);
				printf("enter the position: ");
					scanf("%d",&pos);
				insertPos(create(d),pos);
				break;
			case 4:
				show();
				break;
			case 5:
				printf("enter the data: ");
					scanf("%d",&d);
				del(d);
				break;
			case 6:
				rev();
				break;
			case 7:
				printf("Thank You\n");
				break;
			default:
				printf("Wrong Choice!! Try again noob\n");
		}
	}while(n!=7);
	return 1;
}
