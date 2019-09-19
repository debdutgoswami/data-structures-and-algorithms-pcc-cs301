#include<stdio.h>
#include<stdio.h>
#define MAX 100
int stack[MAX];
int top=-1;
int isEmpty(){
	return top==-1;
}
int isFull(){
	return top==MAX;
}
void push(int item){
	if(isFull())
		printf("Overflow\n");	
	else
		stack[++top]=item;	
}
int pop(){
	if(isEmpty()){
		printf("INVALID!\n");
		exit(0);
	}
	else
		return stack[top--];
}
int main(void){
	char s[100],a,b,ch;
	int i,exp;
	printf("enter the postfix expression: ");
		scanf("%s",s);
	for(i=0;s[i];i++){
		ch=s[i];
		if(ch>='0' && ch<='9')
			push((int)ch-'0');
		else{
			a=pop();
			b=pop();
			switch(ch){
				case '+':
					exp=b+a;
					push(exp);
					break;
				case '-':
					exp=b-a;
					push(exp);
					break;
				case '*':
					exp=b*a;
					push(exp);
					break;
				case '/':
					exp=b/a;
					push(exp);
					break;
			}
		}
	}
	printf("The evaluated form is %d",pop());
	return 0;
}
