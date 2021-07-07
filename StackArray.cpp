#include<stdio.h>
#include<stdlib.h>

struct stack{
	int size;
	int top;
	int *s;
};
void create(struct stack *st)
{
	printf("Enter Size");
	scanf("%d",&st->size);
	st->top=-1;
	st->s=(int *)malloc(st->size*sizeof(int));
}
void display(struct stack st)
{
	int i;
	for(i=st.top;i>=0;i--)
	printf("%d ",st.s[i]);
	printf("\n");
}

void Push(struct stack *st,int x)
{
	if(st->top==st->size-1)
	{
		printf("Stack overflow\n");
	}
	else
	{
		st->top++;
		st->s[st->top]=x;
	}
}

int pop(struct stack *st)
{
	int x=-1;
	if(st->top==-1)
	printf("Stack underflow\n");
	else
	{
		x=st->s[st->top--];
	}
	return x;
}

int peek(struct stack st,int index)
{
	int x=-1;
	if(st.top-index+1<0)
	printf("Invalid Index\n");
	x=st.s[st.top-index+1];
	return x;
}

int isEmpty(struct stack st)
{
	if(st.top==-1)
	{
		return 1;
	}
	
	return 0;
}
int isFull(struct stack st)
{
	return st.top==st.size-1;
}
int stacktop(struct stack st)
{
	if(!isEmpty(st))
	{
		return st.s[st.top];
	}
	else 
	return -1;
}

int main()
{
	struct stack st;
	create(&st);
	Push(&st,10);
//	Push(&st,15);
//	Push(&st,20);
//	Push(&st,25);
	
//	printf("Deleted element is :%d\n\n",pop(&st));
//	printf("Deleted element is : %d\n\n",pop(&st));
	
	//printf("%d\n\n",peek(st,2));
	printf("%d\n\n",isEmpty(st));
	printf("%d\n\n",isFull(st));
	printf("StackTop element is:%d\n\n",stacktop(st));
	display(st);
	return 0;
}


