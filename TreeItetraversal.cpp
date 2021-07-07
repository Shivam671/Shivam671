#include<stdio.h>
#include<stdlib.h>
#include "Queue.h"
#include"Stack.h"
struct Node *root=NULL;

void treecreate()
{
	struct Node *p,*t;
	int x;
	struct Queue q;
	create (&q,100);
	printf("Enter Root Value");
	scanf("%d",&x);
	root=(struct Node *)malloc (sizeof(struct Node ));
	root->data=x;
	root->lchild=root->rchild=NULL;
	
	enqueue(&q,root);
	while(!isEmpty(q)){
		p=dequeue(&q);
		printf("Enter left child of %d ",p->data);
		scanf("%d",&x);
		if(x!=-1)
		{
			t=(struct Node *)malloc(sizeof(struct Node));
			t->data=x;
			t->lchild=t->rchild=NULL;
			p->lchild=t;
			enqueue(&q,t);
		}
		printf("Enter Right child of %d ",p->data);
		scanf("%d",&x);
		if(x!=-1)
		{
			t=(struct Node *)malloc(sizeof(struct Node));
			t->data=x;
			t->lchild=t->rchild=NULL;
			p->rchild=t;
			enqueue(&q,t);
		}
	}
}

void preorder(struct Node *p)
{
	if(p)
	{
		printf("%d ",p->data);
		preorder(p->lchild);
		preorder(p->rchild);
	}
}

void inorder(struct Node *p)
{
	if(p)
	{
		
		inorder(p->lchild);
		printf("%d ",p->data);
		inorder(p->rchild);
	}
}

void postorder(struct Node *p)
{
	if(p)
	{
		
		postorder(p->lchild);
		postorder(p->rchild);
		printf("%d ",p->data);
	}
}
void Ipreorder(struct Node *p)
{
	struct Stack Stk;
	Stackcreate(&Stk,100);
	while(p||!isEmptyStack(Stk))
	{
		if(p)
		{
			printf("%d ",p->data);
			push(&stk,p);
			p=p->lchild;
		}
		else
		{
			p=pop(&stk);
			p=p->rchild;
		}
	}
}

void IInorder(struct Node *p)
{
	struct Stack Stk;
	Stackcreate(&Stk,100);
	while(p||isEmptyStack(Stk))
	{
		if(p)
		{
			push(&Stk,p);
			p=p->lchild;
		}
		else
		{
			p=pop(&Stk);
			printf("%d ",p->data);
			p=p->rchild;
		}
	}
}
int count(struct node *root)
{
	if(root)
	return count(root->lchild)+count(root->rchild)+1;
	return 0;
}
int height(struct node * root)
{
	int x=0,y=0;
	if(root==0)
		return 0;
	x=height(root->lchild);
	y=height(root->rchild);
	if(x>y)
	return x+1;
	else return y+1;
}
int main()
{
	treecreate();
/**	printf("Preorder ");
	preorder(root);
	printf("\nInorder ");
	inorder(root);
	printf("\nPostorder ");
	postorder(root);
*/
Ipreorder(root);
IInorder(root);
return 0;
}
