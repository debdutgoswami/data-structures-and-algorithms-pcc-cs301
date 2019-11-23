#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left, *right;
};

struct node * create(int item){
	struct node *ptr;
	ptr = (struct node *)malloc(sizeof(struct node));
	ptr->data = item;
	ptr->left = NULL;
	ptr->right = NULL;
	return ptr;
}

int max(int a, int b){
	if(a>=b)
		return a;
	else
		return b;
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
int height(struct node * root){
	if(root==NULL)
		return 0;
	else{
		int a = 1+height(root->left);
		int b = 1+height(root->right);
		return max(a,b);
	}
}
void inorder(struct node * ptr){
	if(ptr==NULL){
		return;
	}else{
		inorder(ptr->left);
		printf("%d ",ptr->data);
		inorder(ptr->right);
	}
}
void preorder(struct node * ptr){
	if(ptr==NULL){
		return;
	}else{
		printf("%d ",ptr->data);
		inorder(ptr->left);
		inorder(ptr->right);
	}
}
void postorder(struct node * ptr){
	if(ptr==NULL){
		return;
	}else{
		inorder(ptr->left);
		inorder(ptr->right);
		printf("%d ",ptr->data);
	}
}
int main(void){
	struct node * start = NULL;
	int a, data;
	while(1){
		printf("Menu:\n1. Insert Ascending\n2. Inorder\n3. Preorder\n4. Postorder\n5. Height\n6. Exit\nenter: ");
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
				preorder(start);
				printf("\n");
				break;
			case 4:
				postorder(start);
				printf("\n");
				break;
			case 5:
				printf("%d\n",height(start));
				break;
			case 6:
				exit(1);
			default:
				printf("Try Again!!");
		}
	}
	return 1;
}
