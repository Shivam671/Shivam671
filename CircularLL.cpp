#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
}*Head;

void create (int A[],int n)
{
	int i;
	struct node *t,*last;
	Head=(struct node *)malloc(sizeof(struct node));
	Head->data=A[0];
	Head->next=Head;
	last=Head;
	
	for(i=1;i<n;i++)
	{
		t=(struct node *)malloc(sizeof(struct node));
		t->data=A[i];
		t->next=last->next;
		last->next=t;
		last=t;
	}
}

void Display(struct node *p)
{
	do
	{
		printf("%d ",p->data);
		p=p->next;
	}while(p!=Head);
	printf("\n");
}

void RDisplay(struct node *p)
{
	static int flag=0;
	if(p!=Head ||flag==0)
	{
		flag=1;
		printf("%d ",p->data);
		RDisplay(p->next);
	}
	flag=0;
}

int Length (struct node *p)
{
	int len=0;
	do
	{
		len++;
		p=p->next;
	}while(p!=Head);
	return len;
}

int insert(struct node *p,int index,int x)
{
	struct node *t;
	int i;
	if(index<0 ||index>Length(Head))
		return 0;
	
	if(index==0)
	{
		t=(struct node *)malloc(sizeof(struct node));
		t->data=x;
		if(Head==NULL)
		{
			Head=t;
			Head->next=Head;
		}
		else
		{
			while(p->next!=Head)
			{
				p=p->next;
			}
		p->next=t;
		t->next=Head;
		Head=t;
		}	
	}	
	else
	{
		for(i=0;i<index-1;i++)
		{
			p=p->next;
		}
			t=(struct node *)malloc(sizeof(struct node));
			t->data=x;
			t->next=p->next;
			p->next=t;
	}
	
}

int Delete(struct node *p,int index)
{
	struct node *q;
	int i,x;
	if(index<0 ||index>Length(Head))
	 	return -1;
	 	if(index==0)
	 	{
	 		while(p->next!=Head)
	 		p=p->next;
	 		x=Head->data;
	 		if(Head==p)
	 		{
	 			free(Head);
	 			Head=NULL;
			 }
			 else
			 {
			 	p->next=Head->next;
			 	free(Head);
			 	Head=p->next;
			 }
		}
	else
	{
		for(i=0;i<index-2;i++)
		{
			p=p->next;
		}
		q=p->next;
		p->next=q->next;
		x=q->data;
		free(q);
		}
		return x;
}
int main()
{
	int A[]={1,2,3,4,5,6,7};
	create(A,7);

	//insert(Head,0,10);
	Delete(Head,5);
		printf("%d\n",Length(Head));
	Display(Head);
	return 0;
}

