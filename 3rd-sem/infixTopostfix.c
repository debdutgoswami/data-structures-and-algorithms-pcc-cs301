#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 15
int top = -1;
char stack[MAX];
int isFull(){
	return top==MAX-1;
}
int isEmpty(){
	return top==-1;
}
void push(char item){
	if(isFull())
		printf("Overflow\n");
	else
		stack[++top] = item;
}
char pop(){
	if(isEmpty())
		return '#';
	else{
		top--;
		return stack[top+1];
	}
}
int incomingPriority(char ch){
	if(ch == '+')
		return 1;
	else if(ch == '-')
		return 1;
	else if(ch == '*')
		return 3;
	else if(ch == '/')
		return 3;
	else if(ch == '^')
		return 6;
}
int instackPriority(char ch){
	if(ch == '+')
		return 2;
	else if(ch == '-')
		return 2;
	else if(ch == '*')
		return 4;
	else if(ch == '/')
		return 4;
	else if(ch == '^')
		return 5;
	else if(ch == '(')
		return 0;
}
int main(void){
	char s[15], postfix[] = "", ch, t;
	int size, i, k=0;
	printf("Enter the expression: ");
		scanf("%s",s);
	printf("Your entered exp is %s\n",s);
	size = strlen(s);
	for(i=0;i<size;i++){
		ch = s[i];
		if((ch>='A' && ch<='Z')||(ch>='a' && ch<='z'))
			postfix[k++] = ch;
		else{
			if(isEmpty()||ch =='(')
				push(ch);
			else if(ch == ')'){
				t = pop();
				while(t!='('){
					postfix[k++] = t;
					t = pop();
				}
			}
			else if(incomingPriority(ch)>instackPriority(stack[top]))
				push(ch);
			else if(incomingPriority(ch)<=instackPriority(stack[top])){
				while((incomingPriority(ch)<=instackPriority(stack[top]))&&!isEmpty())
					postfix[k++] = pop();
				push(ch);
			}			
		}
	}
	if(!isEmpty()){
		while(!isEmpty())
			postfix[k++] = pop();
	}
	postfix[k++]='\0';
	
	printf("The equivalent Postfix exp is %s\n",postfix);
	return 0;
}
