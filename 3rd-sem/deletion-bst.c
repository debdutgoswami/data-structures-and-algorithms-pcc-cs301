#include <stdio.h>
#include <stdlib.h>

/*node definition*/
struct node{
	int data;
	struct node *left, *right;
};

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

void inorder(struct node * root){
	if(root==NULL)
		return;
	else{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

/*finds the inorder successor of the passed node*/
struct node * inorder_successor(struct node * ptr){
	struct node * current;
	if(ptr==NULL)
		return NULL;
	else{
		current = ptr;
		while(current && current->left)
			current = current->left;
	}
	return current;
}

struct node * delete_node(struct node * root, int key){
	struct node * temp;
	if(root == NULL)
		return root;
	
	if(root->data>key)
		root->left = delete_node(root->left, key);
	else if(root->data<key)
		root->right = delete_node(root->right, key);
	else{
		if(root->left==NULL){
			temp = root->right;
			free(root);
			return temp;
		}else if(root->right == NULL){
			temp = root->left;
			free(root);
			return temp;
		}
		/*inorder successor will be present in right sub-tree*/
		temp = inorder_successor(root->right);
		root->data = temp->data;
		root->right = delete_node(root->right, temp->data);
	}
	
	return root;
}

int main(void){
	struct node * root = NULL;
	int data, n;
	printf("Menu:\n1. insert\n2. delete\n3. exit\n");
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
				printf("which node do you want to delete: ");
					scanf("%d", &data);
				printf("\nbefore deletion: ");
				inorder(root);
				root = delete_node(root, data);
				printf("\nafter deletion: ");
				inorder(root);
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
