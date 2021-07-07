/*
#include<stdio.h>

struct matrix
{
	int A[10];
	int n;
};
void set(struct matrix *m,int i, int j, int x)
{
	if(i==j)
	m->A[i-1]=x;
}
int get (struct matrix m,int i, int j)
{
	if(i==j)
	return m.A[i-1];
	else
	return 0;
}
void display(struct matrix m)
{
	int i,j;
	for(i=0;i<m.n;i++)
	{
		for(j=0;j<m.n;j++)
		{
			if(i==j)
			printf("%d ",m.A[i]);
			else
			printf("0 ");
		}
		printf("\n");
	}
}

int main()
{
	struct matrix m;
	m.n=4;
	set(&m,1,1,5);set(&m,2,2,8);set(&m,3,3,11);set(&m,4,4,13);
	printf("%d\n",get(m,2,2));
	display(m);
	return 0;
}*/

#include<stdio.h>
#include<stdlib.h>

struct matrix
{
	int *A;
	int n;
};
void set(struct matrix *m,int i,int j,int x)
{
	if(i>=j)
	m->A[i*(i-1)/2+j-1]=x;
}
int get (struct matrix m,int i , int j)
{
	if(i>=j)
	return m.A[i*(i-1)/2+j-1];
	else 
	return 0;
}

void display(struct matrix m)
{
	int i,j;
	for(i=1;i<=m.n;i++)
	{
		for(j=1;j<=m.n;j++)
		{
			if(i>=j)
			printf("%d ",m.A[i*(i-1)/2+j-1]);
			else
			printf("0 ");
		}
		printf("\n");
	}
}
int main()
{
	struct matrix m;
	int i,j,x;
	printf("Enter Dimension");
	scanf("%d",&m.n);
	m.A=(int *)malloc(m.n*(m.n-1)/2*sizeof(int));
	printf("enter all numbers");
	for(i=1;i<=m.n;i++)
	{
		for(j=1;j<=m.n;j++)
		{
			scanf("%d",&x);
			set (&m,i,j,x);
		}
	}
	printf("\n");
	display(m);

	return 0;
}














