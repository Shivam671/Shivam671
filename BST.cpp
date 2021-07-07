#include<stdio.h>
#include<stdlib.h>
struct node {
	struct node *lchild;
	int data;
	struct node *rchild;
}*root=NULL;

void Insert(int key)
{
	struct node *t=root;
	struct node *r,*p;
	if(root==NULL)
	{
		p=(struct node *)malloc(sizeof(struct node));
		p->data=key;
		p->lchild=p->rchild=NULL;
		root=p;
		return ;
	}
	while(t!=NULL)
	{
		r=t;
		if(key<t->data)
		t=t->lchild;
		else if(key>t->data)
		t=t->rchild;
		else
		return;
	}
	p=(struct node *)malloc(sizeof(struct node));
	p->data=key;
	p->lchild=p->rchild=NULL;
	if(key<r->data)
	 r->lchild=p;
	else
	r->rchild=p;
	}
	
	void Inorder(struct node *p)
	{
		if(p)
		{
			Inorder(p->lchild);
			printf("%d ",p->data);
			Inorder(p->rchild);
		}
	}

struct node * search(int key)
{
	struct node *t=root;
	while(t)
	{
		if(key==t->data)
		return t;
		else if(key<t->data)
		t=t->lchild;
		else
		t=t->rchild;
	}
	return NULL;
}
struct node * RInsert(struct node *p,int key)
{
	struct node *t=NULL;
	if(p==NULL)
	{
		t=(struct node *)malloc(sizeof(struct node));
		t->data=key;
		t->lchild=t->rchild=NULL;
		return t;
	}
	if(key<p->data)
		p->lchild=RInsert(p->lchild,key);
	else if(key>p->data)
	p->rchild=RInsert(p->rchild,key);
	return p; 
}
int Height(struct node *p)
{
	int x,y;
	if(p==NULL)return 0;
	x=Height(p->lchild);
	y=Height(p->rchild);
	return x>y?x+1:y+1;
}
struct node *Inpre(struct node *p)
{
	while(p && p->rchild!=NULL)
		p=p->rchild;
	return p;
}
struct node *Insucc(struct node *p)
{
	while(p&&p->lchild!=NULL)
	p=p->lchild;
	return p;
}
struct node * Delete(struct node *p,int key)
{
	struct node *q;
	if(p==NULL)
		return NULL;
		if(p->lchild==NULL&&p->rchild==NULL)
		{
			if(p==root)
			root=NULL;
			free(p);
			return NULL;
		}
		if(key<p->data)
		p->lchild=Delete(p->lchild,key);
		else if(key>p->data)
		p->rchild=Delete(p->rchild,key);
		else
		{
			if(Height(p->lchild)>Height(p->rchild))
			{
				q=Inpre(p->lchild);
				p->data=q->data;
				p->lchild=Delete(p->lchild,q->data);
			}
			else
			{
				q=Insucc(p->rchild);
				p->data=q->data;
				p->rchild=Delete(p->rchild,q->data);
			}
		}
		return p;
}
int main()
{
	struct node *temp;
	
	root=RInsert(root,10);
	RInsert(root,5);
	RInsert(root,20);
	RInsert(root,8);
	RInsert(root,30);
	Inorder(root);
	printf("\n");
	Delete(root,10);
	temp=search(20);
	Inorder(root);
	printf("\n");
	if(temp!=NULL)
		printf("element %d is found\n",temp->data);
	else
	("element is not found\n");
	return 0;
	}	
