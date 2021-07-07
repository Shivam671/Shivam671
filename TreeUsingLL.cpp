#include<stdio.h>


#include"Queue.h"

struct node *root=NULL;
void treecreate()
{
	struct node *p,*t;
	int x;
	struct Queue q;
	create (&q,100);
	printf("Enter Root Value");
	scanf("%d",&x);
	root=(struct node *)malloc (sizeof(struct node ));
	root->data=x;
	root->lchild=root->rchild=NULL;
	
	enqueue(&q,root);
	while(!isEmpty(q)){
		p=dequeue(&q);
		printf("Enter left child of %d ",p->data);
		scanf("%d",&x);
		if(x!=-1)
		{
			t=(struct node *)malloc(sizeof(struct node));
			t->data=x;
			t->lchild=t->rchild=NULL;
			p->lchild=t;
			enqueue(&q,t);
		}
		printf("Enter Right child of %d ",p->data);
		scanf("%d",&x);
		if(x!=-1)
		{
			t=(struct node *)malloc(sizeof(struct node));
			t->data=x;
			t->lchild=t->rchild=NULL;
			p->rchild=t;
			enqueue(&q,t);
		}
	}
}

void preorder(struct node *p)
{
	if(p)
	{
		printf("%d ",p->data);
		preorder(p->lchild);
		preorder(p->rchild);
	}
}

void inorder(struct node *p)
{
	if(p)
	{
		
		inorder(p->lchild);
		printf("%d ",p->data);
		inorder(p->rchild);
	}
}

void postorder(struct node *p)
{
	if(p)
	{
		
		postorder(p->lchild);
		postorder(p->rchild);
		printf("%d ",p->data);
	}
}
int main()
{
	treecreate();
	printf("Preorder ");
	preorder(root);
	printf("\nInorder ");
	inorder(root);
	printf("\nPostorder ");
	postorder(root);
}
