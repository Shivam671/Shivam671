#include<stdio.h>
#include<stdlib.h>
struct node1{
	struct node1 *lchild;
	int data;
	struct node1 *rchild;
};
struct Queue{
	int size;
	int front;
	int rear;
	node1 **Q;
};
void create (struct Queue *q,int size)
{
	q->size=size;
	q->front=q->rear=NULL;
	q->Q=(node1 **)malloc(q->size*(sizeof(node1 *)));
}
void enqueue(struct Queue *q,node1 * x)
{
	if((q->rear+1)%q->size==q->front)
	printf("Queue is Full\n");
	else
	{
		q->rear=(q->rear+1)%q->size;
		q->Q[q->rear]=x;
	}
}

node1 * dequeue(struct Queue *q)
{
	struct node1 *x=NULL;
	if(q->front ==q->rear)
	printf("Queue is Empty\n");
	else
	{
		q->front=(q->front+1)%q->size;
		x=q->Q[q->front];
	}
	return x;
}
int isEmpty(struct Queue q)
{
	return q.front==q.rear;
}

