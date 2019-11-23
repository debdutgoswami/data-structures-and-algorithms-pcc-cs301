#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int q1[MAX],q2[MAX],f1=-1,r1=-1,f2=-1,r2=-1;
int isFull(){
	return r1+1==MAX;
}
int isEmpty(int f){
	return f==-1;
}
void enQueue(int item){
	int i;
	if(isFull())
		printf("Overflow\n");
	else
		if(isEmpty(f1)){
			f1=0;
			q1[++r1]=item;
		}else{
			for(i=0;;i++){
				if(isEmpty(f2))
			}
		}
}
