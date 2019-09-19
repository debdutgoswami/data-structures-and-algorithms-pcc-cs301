#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int top=-1;
char s[100];
int isEmpty(){
	return top==-1;
}
void push(char ch){
	s[++top]=ch;
}
char pop(){
	return s[top--];
}
int main(void){
	char str[100];
	int size,i;
	printf("Enter the string: ");
		scanf("%s",str);
	for(i=0;str[i];i++)
		push(str[i]);	
	i=0;
	while(1){
		if(isEmpty())
			break;
		str[i++]=pop();
	}
	str[i]='\0';
	printf("%s",str);
	return 1;
}
