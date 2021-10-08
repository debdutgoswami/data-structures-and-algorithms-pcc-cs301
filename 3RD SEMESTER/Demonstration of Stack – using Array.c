#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 

struct stackk { 
	int top; 
	unsigned size; 
	int* array; 
}; 



    
struct stackk* create(unsigned size) 
{ 
	struct stackk* stackk = (struct stackk*)malloc(sizeof(struct stackk)); 
	stackk->size = size; 
	stackk->top = -1; 
	stackk->array = (int*)malloc(stackk->size * sizeof(int)); 
	return stackk; 
} 

int isFull(struct stackk* stackk) 
{ 
	return stackk->top == stackk->size - 1; 
} 

int isEmpty(struct stackk* stackk) 
{ 
	return stackk->top == -1; 
} 

void push(struct stackk* stackk, int item) 
{ 
	if (isFull(stackk)) 
		return; 
	stackk->array[++stackk->top] = item; 
} 


int pop(struct stackk* stackk) 
{ 
	if (isEmpty(stackk)) 
		return -1; 
	return stackk->array[stackk->top--]; 
} 

int peek(struct stackk* stackk) 
{ 
	if (isEmpty(stackk)) 
		return INT_MIN; 
	return stackk->array[stackk->top]; 
} 


int main()
{ 
  int val,n;
  struct stackk* stackk = create(100); 
  do
	{printf("\n************************* MENU ************************");
	 printf("\n1.PUSH");
	 printf("\n2.POP");
	 printf("\n3.PEEK");
	 printf("\n4 IS EMPTY");
	 printf("\n5.EXIT");
	 printf("\n enter ur choice : ");
	 scanf("%d",&n);
	 switch(n)
		{
		 case 1: 
		     printf("\nenter the value ");
			 scanf("%d",&val);
			 push(stackk , val);
			 break;
		 case 2: 
			 printf("\n popped element : %d",pop(stackk));
			 break;
		 
		case 3: 
			printf("\n top element : %d",peek(stackk));
			 break;
		 case 4: printf("\n is empty : %d",isEmpty(stackk));
		 		 break;
		 case 5: exit(0);
		 		 break;
		 default: printf("\n Wrong Choice!");
		 		  break;
		}
	 printf("\n do u want to cont... ");
	}while('y'==getch());

 }




Output:

************************* MENU ************************
1.PUSH
2.POP
3.PEEK
4 IS EMPTY
5.EXIT
enter ur choice :
1

enter the value
45

do u want to cont...
************************* MENU ************************
1.PUSH
2.POP
3.PEEK
4 IS EMPTY
5.EXIT
enter ur choice :
1

enter the value
56

do u want to cont...
************************* MENU ************************
1.PUSH
2.POP
3.PEEK
4 IS EMPTY
5.EXIT
enter ur choice :
3

 top element : 56
do u want to cont...
************************* MENU ************************
1.PUSH
2.POP
3.PEEK
4 IS EMPTY
5.EXIT
enter ur choice :
4

 is empty : 0
do u want to cont...
