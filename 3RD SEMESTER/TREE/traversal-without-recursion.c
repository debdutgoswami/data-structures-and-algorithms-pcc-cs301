#include <stdio.h>
#include <stdlib.h>

/*tree*/
struct node{
	int data;
	struct node *left, *right;
};

/*stack1*/
struct node * stack1[100];
int top1=-1;
int isEmpty1(){
	return top1==-1;
}
void push1(struct node * ptr){
	stack1[++top1] = ptr;
}
struct node * pop1(){
	struct node * ptr = stack1[top1];
	top1--;
	return ptr;
}

/*stack2*/
struct node * stack2[100];
int top2=-1;
int isEmpty2(){
	return top2==-1;
}
void push2(struct node * ptr){
	stack2[++top2] = ptr;
}
struct node * pop2(){
	struct node * ptr = stack2[top2];
	top2--;
	return ptr;
}

struct node * create(int item){
	struct node *ptr;
	ptr = (struct node *)malloc(sizeof(struct node));
	ptr->data = item;
	ptr->left = NULL;
	ptr->right = NULL;
	return ptr;
}

struct node * insertAscending(struct node * start, struct node *ptr, struct node * n){
	if(start == NULL)
		start = n;
	else if(ptr->data > n->data){
		if(ptr->left == NULL)
			ptr->left = n;
		else
			start = insertAscending(start,ptr->left,n);
	}else if(ptr->data < n->data){
		if(ptr->right == NULL)
			ptr->right = n;
		else
			start = insertAscending(start, ptr->right, n);
	}
	return start;	
}

void inorder(struct node * root){
	struct node * ptr = root;
	while(1){
		while(ptr->left != NULL){
			push1(ptr);
			ptr = ptr->left;
		}
		while(ptr->right == NULL){
			printf("%d ", ptr->data);
			if(isEmpty1())
				return;
			else
				ptr = pop1();
		}
		printf("%d ", ptr->data);
		ptr = ptr->right;
	}
}

void postorder(struct node * root){
	struct node * ptr;
	push1(root);
	
	while(!(isEmpty1())){
		ptr = pop1();
		push2(ptr);
		
		if(ptr->left)
			push1(ptr->left);
		if(ptr->right)
			push1(ptr->right);
	}
	
	while(!(isEmpty2())){
		ptr = pop2();
		printf("%d ", ptr->data);
	}
}

int main(void){
	struct node * start = NULL;
	int a, data;
	while(1){
		printf("Menu:\n1. Insert Ascending\n2. Inorder\n3. Preorder\n4. Postorder\n5. Exit\nenter: ");
			scanf("%d",&a);
		switch(a){
			case 1:
				printf("enter the data: ");
					scanf("%d",&data);
				start = insertAscending(start, start, create(data));
				break;
			case 2:
				inorder(start);
				printf("\n");
				break;
			case 3:
				//preorder(start);
				printf("\n");
				break;
			case 4:
				postorder(start);
				printf("\n");
				break;
			case 5:
				exit(1);
			default:
				printf("Try Again!!");
		}
	}
	return 0;
}
