#include <stdio.h>
#include <stdlib.h>

/*BST*/
struct node
{
    int data;
    struct node *left, *right;
};

/*helper QUEUE funtions*/
int front = -1, rear = -1;
void push(struct node * *queue, struct node * n){
    if(front==-1)
        front = 0;
    queue[++rear] = n;
}
struct node * pop(struct node * *queue){
    struct node * temp = queue[front];
    front+=1;
    if(front>rear)
        front=rear=-1;
    return temp;
}
int size(){
    return rear-front; //checks if one element is present
}

/*helper BST functions*/
struct node * create(int data){
    struct node * ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;

    return ptr;
}

struct node * insertBST(struct node *root, struct node *n){
    if(root==NULL)
        root = n;
    else{
        if(root->data > n->data)
            root->left = insertBST(root->left, n);
        else
            root->right = insertBST(root->right, n);
    }
    return root;
}

int height(struct node * root){
    if(root==NULL)
        return 0;
    else{
        int a = 1 + height(root->left);
        int b = 1 + height(root->right);
        return __max(a,b); //library function
    }
}

/*main code*/
void levelOrder(struct node * root){
    if(root==NULL)
        return;

    struct node * queue[2*height(root)-1];
    push(queue,root);
    push(queue,NULL);
    while(size()){
        struct node * n = pop(queue);
        if(n==NULL){
            printf("\n");
            push(queue, NULL);
            continue;
        }
        printf("%d ",n->data);
        if(n->left)
            push(queue, n->left);
        if(n->right)
            push(queue, n->right);
    }
}

/*driver code*/
int main(void){
    struct node * root=NULL1;
    int n, data;
    while (1){
        printf("\nenter your choice: ");
            scanf("%d",&n);
        switch (n)
        {
        case 1:
            printf("enter the data: ");
                scanf("%d",&data);
            root = insertBST(root,create(data));
            break;

        case 2:
            levelOrder(root);
            break;

        case 3:
            printf("Thank You\n");
            exit(0);

        default:
            printf("try again!!");
            break;
        }
    }
    return 0;
}
