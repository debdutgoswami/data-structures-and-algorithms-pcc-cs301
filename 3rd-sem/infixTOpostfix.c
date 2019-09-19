#include<stdio.h>
#include<stdlib.h>
char pop(char *s, int *top){
	char ch;
	if(*top==-1)
		ch = '#';
	else{
		ch = *(s+*top);
		--*top;
	}
	return ch;
}
char top(char *s, int *top){
	if(*top==-1)
		return '#';
	else return *(s+*top);
}
int braces(char infix[]){
	int i, leftB=0, rightB=0;
	for(i=0;infix[i]!='\0';i++){
		if(infix[i]=='(')
			leftB++;
		else if(infix[i]==')')
			rightB++;
	}
	return (leftB-rightB);
}
void push(char *s, int *top, char data){
	
}
int main(void){
	char infix[50], postfix[50], *s;
	s=(char *)malloc(50*sizeof(char));
	strcpy(postfix,"");
	int i,j=0, checkB;
	printf("Enter the expression: ");
		scanf("%s", infix);
	checkB = braces(infix);
	if(checkB){
		printf("Wrong Braces\n");
		exit(1);
	}
	for(i=0;infix[i]!='\0';i++){
		if(infix[i]!='('&&infix[i]!=')'&&infix[i]!='^'&&infix[i]!='/'&&infix[i]!='*'&&infix[i]!='+'&&infix[i]!='-')
			postfix[j++] = infix[i];
		else if(infix[i]=='(')
			push(s, top, infix[i]);
		else if(infix[i]==')'){
			
		}
	}
}
