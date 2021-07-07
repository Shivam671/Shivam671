#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *prev;
	int data;
	struct node *next;
}*Head=NULL;

void create (int A[],int n)
{
	struct node *t,*last;
	int i;
	Head=(struct node *)malloc(sizeof(struct node));
	Head->data=A[0];
		Head->next=Head;
	Head->prev=Head;//->next;

	last=Head;
	
	for(i=1;i<n;i++)
	{
		t=(struct node *)malloc(sizeof(struct node));
		t->data=A[i];
	    last->next=t;//->next;
		t->prev=last;
		t->next=Head;
		Head->prev=t;
	//	last->next=t;
		last=t;
	}
}

void Display(struct node *p)
{
	while(p->next!=Head)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
int Length(struct node *p)
{
	int len=0;
	while(p)
	{
		len ++;
		p=p->next;
	}
	return len;
}
int main ()
{
	int A[]={10,20,30,35};
	create(A,4);
	printf("\nLength is %d\n",Length(Head));
	Display(Head);
	return 0;
}

