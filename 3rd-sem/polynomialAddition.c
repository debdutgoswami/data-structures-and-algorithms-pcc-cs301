#include<stdio.h>
#include<stdlib.h>
struct node{
	int cof;
	int deg;
	struct node *next;
}*poly1=NULL,*poly2=NULL,*poly=NULL;

struct node* create(int c, int d){
	struct node *n;
	n=(struct node*)malloc(sizeof(struct node));
	n->cof=c;
	n->deg=d;
	n->next=NULL;
	return n;
}
struct node* makePoly(struct node *n, struct node *p){
	struct node *ptr=p;
	if(p==NULL)
		p=n;
	else{
		while(ptr->next!=NULL)
			ptr=ptr->next;
		ptr->next=n;
	}
	return p;
}
struct node* addition(struct node* p1, struct node* p2, struct node* po){
	struct node *p=po;
	struct node *n;
	n=(struct node*)malloc(sizeof(struct node));
	while(p1 && p2){
		if(p1->deg > p2->deg){
			n=create(p1->cof,p1->deg);
			p=makePoly(n,p);
			/*p->cof=p1->cof;
			p->deg=p1->deg;*/

			p1=p1->next;
		}else if(p2->deg > p1->deg){
			n=create(p2->cof,p2->deg);
			p=makePoly(n,p);
			/*p->cof=p2->cof;
			p->deg=p2->deg;*/

			p2=p2->next;
		}else{
			n=create(p1->cof + p2->cof, p1->deg);
			p=makePoly(n,p);
			/*p->cof = p1->cof + p2->cof;
			p->deg = p1->deg;*/

			p1=p1->next;
			p2=p2->next;
		}
		/*p->next=(struct node*)malloc(sizeof(struct node));
		p=p->next;
		p->next=NULL;*/
	}
	while(p1 || p2){
		if(p1){
			n=create(p1->cof,p1->deg);
			p=makePoly(n,p);
			/*p->cof=p1->cof;
			p->deg=p1->deg;*/

			p1=p1->next;	
		}else{
			n=create(p2->cof,p2->deg);
			p=makePoly(n,p);
			/*p->cof=p2->cof;
			p->deg=p2->deg;*/

			p2=p2->next;
		}
		/*p->next=(struct node*)malloc(sizeof(struct node));
		p=p->next;
		p->next=NULL;*/
	}
	return po;
}
void show(struct node *p){
	struct node *ptr=p;
	while(ptr){
		printf("%dx^%d ",ptr->cof,ptr->deg);
		if(ptr->next!=NULL)
			printf("+ ");
		ptr=ptr->next;
	}
	printf("\n");
}
int main(void){
	int c,d,ch;
	poly=(struct node*)malloc(sizeof(struct node));
	printf("Enter the equation of first polynomial: \n");
	do{
		printf("enter the co-efficient: ");
			scanf("%d",&c);
		printf("enter the degree: ");
			scanf("%d",&d);
		poly1=makePoly(create(c,d), poly1);
		printf("Do you want to continue? (Y=1/N=0)\n");
			scanf("%d",&ch);
	}while(ch!=0);
	printf("Enter the equation of second polynomial: \n");
	do{
		printf("enter the co-efficient: ");
			scanf("%d",&c);
		printf("enter the degree: ");
			scanf("%d",&d);
		poly2=makePoly(create(c,d), poly2);
		printf("Do you want to continue? (Y=1/N=0)\n");
			scanf("%d",&ch);
	}while(ch!=0);
	printf("The first equation is: ");
		show(poly1);
	printf("The second equation is: ");
		show(poly2);
	printf("The addition of the two equation is: ");
		poly=addition(poly1, poly2, poly);
		show(poly);
	return 1;
}
