/*
#include<stdio.h>
int main()
{
	//Declaration of Array.
	int A[5];
	int B[10]={1,2,3,4,5};
	int C[7]={0,0};
	int D[]={2,3,5,8,9,11,14};
	//printf("%d",B[3]); //for printing 4th value of B.
	int i;
	//for printing the array.
	for(i=0;i<7;i++)
	printf("%d ",D[i]);
	return 0;
}*/

//accessing array in stack or heap.
/*
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int A[5]={2,4,6,8,10};//accessing array in stack
	int *p;
	int i;
	p=(int *)malloc (5*sizeof(int));//accessing array in heap
	p[0]=4;
	p[1]=6;
	p[2]=8;
	p[3]=10;
	p[4]=12;
	
	for(i=0;i<5;i++)
	printf("%d ",A[i]);
	printf("\n");
	for(i=0;i<5;i++)
	printf("%d ",p[i]);
	return 0;
}*/
/*
//Increasing size of array
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *p,*q,i;
	p=(int*)malloc(5*sizeof(int));//assigning 1st arrray of size 5.
	p[0]=3;p[1]=5;p[2]=7;p[3]=9;p[4]=11;//initializing values of array
	q=(int*)malloc(10*sizeof(int));//increasing size of array to taking new array.
	
	for(i=0;i<5;i++)
	q[i]=p[i];//copying values 
	free(p);//deleting p
	p=q;//pointing  q as p
	q=NULL; //removing q
	
	for(i=0;i<5;i++)
	printf("%d ",p[i]);
	return 0;
}*/
/*
//Creating a 2D array

#include<stdio.h>
#include<stdlib.h>
int main ()
{
	int A[3][4]={{1,2,3,4},{2,4,6,8},{3,5,7,9}};//1st method //inside stack
	
	int *B[3];	//2nd method //created inside stack	//Arrays of pointers of integer type
	B[0]=(int *)malloc(4*sizeof(int));//creating array in heap
	B[1]=(int *)malloc(4*sizeof(int));
	B[2]=(int *)malloc(4*sizeof(int));
	B[0][0]=11;B[0][1]=12;B[0][2]=13;B[0][3]=14;//for initializing value
	B[1][0]=0;B[1][1]=01;B[1][2]=2;B[1][3]=3;
	
	int **C; //3rd mrthod //creted inside Heap//
	C=(int **)malloc(3*sizeof(int *));
	C[0]=(int *)malloc(4*sizeof(int));
	C[1]=(int *)malloc(4*sizeof(int));
	C[2]=(int*)malloc(4*sizeof(int));
	
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)	
		printf("%d  ",C[i][j]);
		printf("\n");
	}
	return 0;
}*/

#include<stdio.h>
#include<stdlib.h>

struct array
{
	int *A;
	int size;
	int length;
};
int main()
{
		struct Array arr;
	int n,i,size;
	printf("Enter Size of an array");
	scanf("%d",&arr.size);
	arr.A=(int *)malloc(arr.size*size of (int));
	arr.length=0;
	printf("Enter number of numbers");// no.of elements initializing 
	scanf("%d",&n);
	
	printf("Enter all numbers");
	for(i=0;i<n;i++)
	scanf("%d",&arr.A[i]);
	arr.length=n;
	Display(arr);
	return 0;
}

void Display(struct Array arr)
{
	int i;
	printf("\n Elements are:\n");
	for(i=0;i<arr.length;i++)
	printf("%d",arr.A[i]);
}




