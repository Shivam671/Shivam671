#include<stdio.h>
#include<stdlib.h>
struct node {
	struct node *prev;
	int data;
	struct node *next;
}*Head=NULL;

void create(int A[],int n)
{
	struct node *t,*last;
	int i;
	Head=(struct node *)malloc(sizeof(struct node));
	Head->data=A[0];
	Head->prev=Head->next=NULL;
	last=Head;
	
	for(i=1;i<n;i++)
	{
		t=(struct node *)malloc(sizeof(struct node));
		t->data=A[i];
		t->next=last->next;
		t->prev=last;
		last->next=t;
		last=t;
	}
}

void Display(struct node *p)
{
	while(p)
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
		len++;
		p=p->next;
	}
	return len;
}

void insert(struct node *p,int index,int x)
{
	struct node *t;
	int i;
	if(index<0||index>Length(Head))
		return ;
	if(index==0)
	{
		t=(struct node *)malloc(sizeof(struct node));
		t->data=x;
		t->prev=NULL;
		t->next=Head;
		Head->prev=t;
		Head=t;
	}
	else
	{
		for(i=0;i<index-1;i++)
		{
			p=p->next;
		}
		t=(struct node *)malloc(sizeof(struct node));
		t->data=x;
		t->prev=p;
		t->next=p->next;
		if(p->next)
		{
			p->next->prev=t;
		}
		p->next=t;
	}
}

int Delete(struct node *p,int index)
{
	struct node *q;
	int x=-1,i;
	if(index<0||index>Length(Head))
		return x;
	if(index==0)
	{
		Head=Head->next;
		if(Head) Head->prev=NULL;
		x=p->data;
		free(p);
	}
	else
	{
		for(i=0;i<index;i++)
		{
			p=p->next;
		}
		p->prev->next=p->next;
		if(p->next)
		{
			p->next->prev=p->prev;
		}
		x=p->data;
		free(p);
		}
		return x;	
}

void Reverse(struct node *p)
{
	struct node *temp;
	while(p)
	{
		temp=p->next;
		p->next=p->prev;
		p->prev=temp;
		p=p->prev;
		if(p && p->next==NULL)
		Head=p;
	}
}
int main()
{
	int A[]={10,20,30,40,50,60,70,80};
	create (A,8);
//	insert(Head,0,5);
//	Delete(Head,0);
    Reverse(Head);
	printf("Length is :%d\n",Length(Head));
	Display(Head);
}
