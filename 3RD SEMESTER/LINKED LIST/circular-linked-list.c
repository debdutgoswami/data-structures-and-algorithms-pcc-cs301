#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node * create(int data){
	struct node *ptr;
	ptr = (struct node *)malloc(sizeof(struct node));
	ptr->data = data;
	ptr->next = NULL;
}

struct node * insert_begin(struct node *end, struct node *n){
	struct node *ptr = end;
	if(end==NULL){
		end = n;
		n->next = end;
	}else{
		n->next = end->next;
		end->next = n;
	}
	return end;
}

struct node * insert_end(struct node *end, struct node *n){
	struct node *ptr = end;
	if(end==NULL){
		end = n;
		n->next = end;
	}else{
		n->next = ptr->next;
		ptr->next = n;
		end = n;
	}
	return end;
}

struct node * insert_any(struct node *end, struct node *n, int pos){
	struct node *ptr = end->next;
	if(end->data==pos){
		end = insert_end(end,n);
		return end;
	}else{
		while(ptr!=end){
			if(ptr->data==pos){
				n->next = ptr->next;
				ptr->next = n;
				return end;
			}
			ptr = ptr->next;
		}
		
		printf("element not found!!\n");
		return end;
	}
}

struct node * delete_node(struct node *end, int data){
	struct node *prev = end, *ptr = end->next, *tmp;
	while(ptr!=end){
		if(ptr->data == data){
			tmp = ptr;
			prev->next = ptr->next;
			free(tmp);
			return end;
		}
		ptr = ptr->next;
		prev = prev->next;
	}
	/*for the last node*/
	if(ptr->data == data){
		tmp = ptr;
		prev->next = ptr->next;
		free(tmp);
		end = prev;
		return end;
	}
	printf("element not found!!\n");
	return end;
}

void display(struct node * end){
	struct node *ptr = end->next;
	while(ptr!=end){
		printf("%d -> ",ptr->data);
		ptr = ptr->next;
	}
	printf("%d\n",ptr->data);
}

int main(void){
	struct node *end = NULL;
	int n, data, pos;
	printf("******CIRCULAR QUEUE******\n");
	printf("1. insert(begining)\n2. insert(end)\n3. insert(any)\n4. delete\n5. display\n6. exit\n");
	while(1){
		printf("enter: ");
			scanf("%d",&n);
		switch(n){
			case 1:
				printf("enter the data: ");
					scanf("%d",&data);
				end = insert_begin(end,create(data));
				break;
			
			case 2:
				printf("enter the data: ");
					scanf("%d",&data);
				end = insert_end(end,create(data));
				break;
			
			case 3:
				printf("enter the data: ");
					scanf("%d",&data);
				printf("enter the element after which you want to enter: ");
					scanf("%d",&pos);
				end = insert_any(end,create(data),pos);
				break;
				
			case 4:
				printf("enter the element to be deleted: ");
					scanf("%d",&data);
				end = delete_node(end, data);
				break;
				
			case 5:
				display(end);
				break;
			
			case 6:
				printf("thank you!\n");
				exit(0);
			
			default:
				printf("try again!!\n");
		}
	}
	return 0;
}
