#include<stdio.h>
#define MAX 8
int stack[MAX], top=-1;
int empty(){
	return top==-1;
}
void push(int item){
	stack[++top] = item;
}

int pop(){
	top--;
	return stack[top+1];
}

int main(void){
	int n;
	printf("enter the decimal no to be converted: ");
		scanf("%d",&n);
	while(n!=0){
		push(n%2);
		n/=2;
	}
	while(!empty()){
		printf("%d",pop());
	}
	return 0;
}
