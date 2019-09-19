/*
Given a linked list of integers, remove all consecutive nodes that sum up to 0.

Example:
Input: 10 -> 5 -> -3 -> -3 -> 1 -> 4 -> -4
Output: 10

The consecutive nodes 5 -> -3 -> -3 -> 1 sums up to 0 so that sequence should be removed. 4 -> -4 also sums up to 0 too so that sequence should also be removed.
*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
}*start=NULL;

struct node * create(int data){
	struct node * ptr;
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=data;
	ptr->next=NULL;
	return ptr;
}

void insert(struct node * n){
	struct node *ptr=start;
	if(start==NULL)
		start=n;
	else{
		for(ptr=start;ptr->next!=NULL;ptr=ptr->next);
		ptr->next=n;
	}
}

void display(){
	struct node * ptr=start;
	printf("********************************\n");
	if(start==NULL)
		printf("empty\n");
	else{
		for(ptr=start;ptr->next!=NULL;ptr=ptr->next)
			printf("%d -> ",ptr->data);
		printf("%d\n",ptr->data);
	}
	printf("********************************\n");
}

void removeConsecutive(){
	struct node *ptr1, *ptr2, *prev, *prev1;
	int sum=0,flag=0;
	a1:
		flag=0;
		for(ptr1=start,prev1=start;ptr1!=NULL;prev1=ptr1,ptr1=ptr1->next){
			sum=0;
			for(ptr2=ptr1,prev=prev1;ptr2!=NULL;ptr2=ptr2->next){
				sum+=ptr2->data;
				if(sum==0){
					flag=1;
					break;
				}
			}
			printf("\n");
			if(flag){
				if(prev==start && ptr2->next==NULL)
					start->next=NULL;
				else if(prev==start)
					start->next=ptr2->next;
				else
					prev->next=ptr2->next;
				goto a1;
			}
		}
	printf("Done %d\n",flag);
}

int main(void){
	int n,d,pos;
	do{
		printf("Menu:\n1. Insert\n2. Display\n3. Remove Consecutive\n4. Exit\nEnter: ");
			scanf("%d",&n);
		switch(n){
			case 1:
				printf("enter the data: ");
					scanf("%d",&d);
				insert(create(d));
				break;
			case 2:
				display();
				break;
			case 3:
				removeConsecutive();
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
