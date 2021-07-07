#include<stdio.h>
#include<stdlib.h>
struct Element{
	int i;
	int j;
	int x;
};
struct sparse
{
	int m;
	int n;
	int num;
	struct Element *ele;
	
};
void create (struct sparse *s)
{
	printf("Enter Dimensions");
	scanf("%d%d",&s->m,&s->n);
	printf("Number of non-zero's");
	scanf("%d",&s->num);
	s->ele=(struct Element *)malloc(s->num*sizeof(struct Element));
	printf("Enter non-Zero Elements");
	for(int i=0;i<s->num;i++)
	{
		scanf("%d %d %d ",&s->ele[i].i,&s->ele[i].j,&s->ele[i].x);
	}
}
void display(struct sparse s)
{
	int i,j,k=0;
	for(i=0;i<s.m;i++)
	{
		for(j=0;j<s.n;j++)
		{
			if(i==s.ele[k].i&&j==s.ele[k].j)
			printf("%d ",s.ele[k++].x);
			else
			printf("0 ");
		}
		printf("\n");
	}
}
struct sparse *add(struct sparse *s1,struct sparse *s2)
{
	struct sparse *sum;
	int i,j,k;
	i=j=k=0;
	sum=(struct sparse *)malloc(sizeof(struct sparse));
	sum->ele=(struct Element*)malloc((s1->num+s2->num)*sizeof(struct Element));
	
	while(i<s1->num && j<s2->num)
	{
		if(s1->ele[i].i<s2->ele[j].i)
		sum->ele[k++]=s1->ele[i++];
		else if(s1->ele[i].i>s2->ele[j].i)
		sum->ele[k++]=s2->ele[j++];
		else
		{
			if(s1->ele[i].j<s2->ele[j].j)
			sum->ele[k++]=s1->ele[i++];
			else if(s1->ele[i].j>s2->ele[j].j)
			sum->ele[k++]=s2->ele[j++];
			else
			{
				sum->ele[k]=s1->ele[i];
				sum->ele[k++]=s1->ele[i++].x+s2->ele[j++].x;
			}
		}
	}


}
int main()
{
	struct sparse s;
	create (&s);
	display(s);
	return 0;
}


