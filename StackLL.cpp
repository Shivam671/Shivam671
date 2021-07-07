#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}*top=NULL;

void push(int x)
{
	struct node *t;
	t=(struct node *)malloc(sizeof(struct node));
	if(t==NULL)
	{
		printf("Stack is Full\n");
	}
	else
	{
		t->data=x;
		t->next=top;
		top=t;
	}
}

int pop()
{
	struct node *t;
	int x=-1;
	if(top==NULL)
	{
		printf("Stack is Empty\n");
	}
	else
	{
		t=top;
		top=top->next;
		x=t->data;
		free(t);
	}
	return x;
}

int peek(int pos)
{
	int x=-1;
 node *p=top;
	
	for(int i=0;p!=NULL&&i<pos-1;i++)
	{
		p=p->next;
	}
	if(p!=NULL)
		return p->data;
	else
		return -1;
}

int stacktop()
{
	if(top)
		return top->data;
	return -1;
}
int isEmpty()
{
	return top?0:1;
}
int isFull()
{
	node *t=(struct node *)malloc(sizeof(struct node));
	int r=t?1:0;
	free(t);
	return r;
}
void display()
{
	struct node *p;
	p=top;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
int main()
{
	push(10);
	push(20);
	push(30);
	push(40);
	display();
	printf("%d\n",isEmpty());
//	printf("%d\n",pop());
//	display();
	return 0;
}
