#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left, *right;
};

struct node * queue[100];
int front = -1, rear = -1;

void push(struct node * ptr){
	if(front==-1)
		front=0;
	queue[++rear] = ptr;
}
struct node * pop(){
	struct node * temp = queue[front];
	if(front==rear)
		front=rear=-1;
	else
		front++;
	return temp;
}

/*helper function*/
struct node * create(int data){
	struct node * ptr;
	ptr = (struct node *)malloc(sizeof(struct node));
	ptr->data = data;
	ptr->left = ptr->right = NULL;
	
	return ptr;
}

struct node * insert(struct node * root, struct node * ptr){
	if(root == NULL)
		root = ptr;
	else if(root->data > ptr->data)
		root->left = insert(root->left, ptr);
	else if(root->data < ptr->data)
		root->right = insert(root->right, ptr);
	
	return root;
}

void zigzag(struct node * root){
	struct node * ptr = root, *temp;
	push(root);
	while(front!=-1){
		temp = pop();
		if(temp){
			push(temp->right);
			push(temp->left);
			printf("%d ", temp->data);
		}
	}
}

int main(void){
	struct node * root = NULL;
	int data, n;
	printf("Menu:\n1. insert\n2. zigzag traversal\n3. exit\n");
	while(1){
		printf("\nenter the choice: ");
			scanf("%d", &n);
		switch(n){
			case 1:
				printf("enter the data: ");
					scanf("%d", &data);
				root = insert(root, create(data));
				break;
			
			case 2:
				printf("\nbefore: ");
				zigzag(root);
				break;
			
			case 3:
				printf("thank you\n");
				exit(0);
			
			default:
				printf("try again\n");
				break;
		}
	}
	return 0;
}
