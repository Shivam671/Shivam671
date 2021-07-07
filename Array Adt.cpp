/*
#include<stdio.h>
#include<stdlib.h>

struct Array
{
	int *A;//Array created in heap
	int size;
	int length;
};
void Display(struct Array arr)
{
	int i;
	printf("\nElements are:\n");
	for(i=0;i<arr.length;i++)
	printf("%d  ",arr.A[i]);
}

int main()
{
	struct Array arr;
	int n,i;
	printf("Enter Size of an Array");
	scanf("%d",&arr.size);
	arr.A=(int *)malloc(arr.size*sizeof(int));//for pointer address
	arr.length=0;//initialy no of element in array is 0 .Hence length 0
	printf("Enter number of numbers");// no.of elements initializing 
	scanf("%d",&n);
	
	printf("Enter all numbers");
	for(i=0;i<n;i++)
	scanf("%d",&arr.A[i]);
	arr.length=n; // length of array after initializing numbers.
	Display(arr); // for displaying we call display function.
	return 0;
}*/
//Array created in stack
/*
#include<stdio.h>
struct Array {
	int A[12];
 	int	size;
	int length;
};
 
void Display (struct Array arr)
{
	int i;
	printf("Elements are:\n");
	for(i=0;i<arr.length;i++)
	printf("%d ",arr.A[i]);
}

int main()
{
	struct Array arr={ {2,5,7,9,11,13,15,14},12 ,5};
	Display (arr);
	return 0;
}*/

#include<stdio.h>
#include<stdlib.h>
struct Array{
	int A[15];
	int size;
	int length;
};

void Display(struct Array arr)//For displaying any array
{
	int i;
	printf("\nElements are:\n");
	for(i=0;i<arr.length;i++)
	
	printf("%d ",arr.A[i]);
	
}

	void Append(struct Array *arr,int x) //for adding any element
{
	if(arr->length<arr->size)
	{
		arr->A[arr->length++]=x;
	}
}
void insert(struct Array *arr,int index,int x)//for inserting any element (
{											//at a given location )
	int i;
	if(index>=0 && index<=arr->length)
	{
		for(i=arr->length;i>index;i--)
		arr->A[i]==arr->A[i-1];
		arr->A[index]=x;
		arr->length++;
	}
}
int Delete(struct Array *arr,int index)
{
	int x=0;
	int i;
	if(index>=0&& index<arr->length)
	{
		x=arr->A[index];
		for(i=index;i<arr->length-1;i++)
		arr->A[i]=arr->A[i+1];
		arr->length--;
		return x;
	}
	return 0;
}
void swap(int*x,int*y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
//for linear search 
int Linearsearch(struct Array *arr,int key)
{
	int i;
	for(i=0;i<arr->length;i++)
	{
		if(key==arr->A[i])
		{
			swap(&arr->A[i],&arr->A[i-1]);//for transposition
			
			//swap(&arr->A[i],&arr->A[0]);//for move to front
			return i;
		}
	}
		return -1;
}
int Linearsearch1(struct Array *arr,int key)
{
	int i;
	for(i=0;i<arr->length;i++)
	{
		if(key==arr->A[i])
		return i;
	}
	return -1;
}
int BinarySearch(struct Array arr,int key)
{
	int l,mid,h;
	l=0;
	h=arr.length;
	while(l<=h)
	{
		mid=(l+h)/2;
		if(key==arr.A[mid])
		return mid;
		else if(key<arr.A[mid])
		h=mid-1;
		else
		l=mid+1;
	}
	return -1;
}
int RBinarySearch(int a[],int l,int h,int key)
{
	int mid;
	if(l<=h)
	{
		mid=(l+h)/2;
		if(key==a[mid])
		return mid;
		else if(key<a[mid])
		return RBinarySearch(a,l,mid-1,key);
		else
		return RBinarySearch(a,mid+1,h,key);
	}
	return -1;
}

int Get (struct Array arr,int index)
{
	if(index>=0&&index < arr.length)
	return arr.A[index];
return -1;	
}

int Set (struct Array *arr,int index,int x)
{
	if(index>=0 && index<arr->length)
	arr->A[index]=x;
}
int Max(struct Array *arr)
{
	int Max=arr->A[0];
	int i;
	for(i=0;i<=arr->length;i++)
	{
		if(arr->A[i]>Max)
		Max=arr->A[i];
	}
	return Max;
}
int Min(struct Array arr)
{
	int min=arr.A[0];
	int i;
	for(i=1;i<arr.length;i++)
	{
		if(arr.A[i]<min)
		min=arr.A[i];
	}
	return min;
}
int Sum(struct Array arr)
{
	int s=0;
	int i;
	for(i=0;i<arr.length;i++)
	{
		s+=arr.A[i];
	}
	return s;
}
	float Avg(struct Array arr)
	{
		return (float) Sum(arr)/arr.length;
	}
	void Reverse(struct Array *arr)
	{
		int *B;
		int i,j;
		B=(int *)malloc(arr->length*sizeof(int));
		for(i=arr->length-1,j=0;i>=0;i--,j++)
		{
		B[j]=arr->A[i];
		}
		for(i=0;i<arr->length;i++)
		{
		arr->A[i]=B[i];
	}
	}
	
	void Reverse2(struct Array *arr)
	{
		int i,j;
		for(i=0,j=arr->length-1;i<j;i++,j--)
		{
			swap(&arr->A[i],&arr->A[j]);
		}
	}
	void Leftshift(struct Array *arr)
	{
		int x,i;
		x=arr->A[0];
		for(i=0;i<arr->length-1;i++)
		{
		arr->A[i]=arr->A[i+1];
		}
		arr->A[arr->length-1]=x;	
	}
		void Rightshift(struct Array *arr)
	{
		int x,i;
		x=arr->A[arr->length-1];
		for(i=arr->length-1;i>=0;i--)
		{
		arr->A[i]=arr->A[i-1];
		}
		arr->A[0]=x;	
	}
	void InsertSort(struct Array *arr,int x)
	{
		int i=arr->length-1;
		if(arr->length==arr->size)
		return ;
		while(i>=0 && arr->A[i]>x)
		{
			arr->A[i+1]=arr->A[i];
			i--;
		}
		arr->A[i+1]=x;
		arr->length++;
	}
	int isSorted (struct Array arr)
	{
		int i;
		for(i=0;i<arr.length-1;i++)
		{
			if(arr.A[i]>arr.A[i+1])
			return 0;
		}
		return 1;
	}
	void REarrange  (struct Array *arr)
	{
	 int i,j;
	 i=0;
	 j=arr->length-1;
	 while(i<j)
	 {
	 	while (arr->A[i]<0) i++;
	 	while (arr->A[j]>=0) j--;
	 	
	 	if(i<j)
	 	{
	 		swap(&arr->A[i],&arr->A[j]);
		 }
	 }
	}
	struct Array * Merge ( struct Array *arr1,struct Array *arr2)
	{
		int i,j,k;
		i=j=k=0;
		struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
		while (i<arr1->length && j<arr2->length)
		{
			if(arr1->A[i]<arr2->A[j])
			arr3->A[k++]=arr1->A[i++];
			else
			arr3->A[k++]=arr2->A[j++];
		}
		for(;i<arr1->length;i++)
		arr3->A[k++]=arr1->A[i];
		for(;j<arr2->length;j++)
		arr3->A[k++]=arr2->A[j];
		
		arr3->length=arr1->length + arr2->length;
		arr3->size=10;
		return arr3;
	}
	struct Array * Union ( struct Array *arr1,struct Array *arr2)
	{
		int i,j,k;
		i=j=k=0;
		struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
		while (i<arr1->length && j<arr2->length)
		{
			if(arr1->A[i]<arr2->A[j])
			arr3->A[k++]=arr1->A[i++];
			else if(arr1->A[j]<arr1->A[i])
			arr3->A[k++]=arr2->A[j++];
			else
			{
				arr3->A[k++]=arr1->A[i++];
				j++;
			}
		}
		for(;i<arr1->length;i++)
		arr3->A[k++]=arr1->A[i];
		
		for(;j<arr2->length;j++)
		arr3->A[k++]=arr2->A[j];
		
		arr3->length=k;
		arr3->size=10;
		return arr3;
	}
	struct Array * Intersection ( struct Array *arr1,struct Array *arr2)
	{
		int i,j,k;
		i=j=k=0;
		struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
		while (i<arr1->length && j<arr2->length)
		{
			if(arr1->A[i]<arr2->A[j])
			i++;
			else if(arr2->A[j]<arr1->A[i])
				j++;
			else if(arr1->A[i]==arr2->A[j])
			{
				arr3->A[k++]=arr2->A[i++];
				j++;
			}
		}
		arr3->length=k;
		arr3->size=10;
		return arr3;
	}
	struct Array * Difference( struct Array *arr1,struct Array *arr2)
	{
		int i,j,k;
		i=j=k=0;
		struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
		while (i<arr1->length && j<arr2->length)
		{
			if(arr1->A[i]<arr2->A[j])
			arr3->A[k++]=arr1->A[i++];
			else if (arr2->A[j]<arr1->A[i])
			j++;
			else
			{
				i++;
				j++;
			}
		}
		for(;i<arr1->length;i++)
		arr3->A[k++]=arr1->A[i];
		
		arr3->length=k;
		arr3->size=10;
		return arr3;
	}
	
int main()
{
/*	struct Array arr1;
	int ch,x,index;
	
	printf("Enter Size of Array");
	scanf("%d",&arr1.size);
	arr1.A=(int *)malloc(arr1.size*sizeof(int));
	
	do
	{
	printf("Menu\n");
	printf("1.Insert\n");
	printf("2.Delete\n");
	printf("3.Search\n");
	printf("4.Sum\n");
	printf("5.Display\n");
	printf("6.Exit\n");
	
	printf("Enter your Choice");
	scanf("%d" ,&ch);
	
	switch (ch)
	{
	case 1: printf("Enter an element and index");
		scanf("%d%d",&x,&index);
		insert (&arr1,index,x);
		break;
	case 2: printf("Enter index");
		scanf("%d%d",&index);
		x=Delete (&arr1,index);
		printf("Deleted Element is %d\n",x);
		break;
	case 3: printf("Enter element to search");
		scanf("%d%d",&x);
		index=Linearsearch (&arr1,x);
		printf("Element index %d",index);
		break;
	case 4: printf("Sum is %d\n",Sum(arr1));
			break;
	
	case 5: Display(arr1);	
	}
	
}while(ch<6);
return 0;
}*/
	
/*	
	struct Array arr={{0,1,2,-3,14,5,6,7,-4,-11,13},15,11};
	struct Array arr1={{2,6,7,10,18,20,25},10,7};
	struct Array arr2={{3,4,7,14,18,20},10,6};
	struct Array *arr3;
	arr3=Merge(&arr1,&arr2);*/
	//insert(&arr,4,15);//inserting 15 at index 4.

	//Append(&arr,10);//adding  element 10 at the end of array.

	//printf(" Deleted element:%d\n ",Delete(&arr,4));

//	printf("Old index:%d\n",Linearsearch(&arr,4));//for searching & printing 

//	printf("New index: %d\n",Linearsearch1(&arr,4));//index of key element.

//	printf("%d",BinarySearch(arr,5));

//	printf("%d\n",RBinarySearch(arr.A,0,arr.length,5));

//	printf("%d\n ",Get(arr,3));//for knowing value at any given index 

//	Set(&arr,0,15);//for replacing value of any given index

//	printf("%d\n",Max(arr));//for finding maxm element of an array

//	printf("%d\n",Min(arr));//for finding minm element of an array

//	printf("%d\n",Sum(arr)); //for finding sum of an arrray

//	printf("%f\n",Avg(arr));//for finding avg of an array

//	Reverse(&arr);
//	Leftshift(&arr);//for left shift
//	Rightshift(&arr); //for Right Shift
//	InsertSort(&arr,20); //for inserting any element in a sorted 

//	printf("%d \n",isSorted (arr));	//for checking array is sorted or not
//	REarrange(&arr);
//	arr3=Merge(&arr1,&arr2);
/*	arr3=Union(&arr1,&arr2);
	arr3=Intersection(&arr1,&arr2);
	arr3=Difference(&arr1,&arr2);
	Display(*arr3);	//Displaying array.*/
	
/*	struct Array arr = {{1,2,3,4,5,6,8,9,10,11,12},15,10};
	int s,i,sum =0;
	
	printf("%d\n",Max(&arr));
	int n=Max(&arr);
	for(i=0;i<12;i++)
	{
		sum =sum +arr.A[i];
	}
	s=(n*(n+1))/2;
	int x= s-sum;
	printf("Misiing No is %d",x);
	Display(arr);
	return 0;*/
	
	struct Array arr = {{6,7,8,9,10,11,13,14,15,16,17},15,11};
	int i,n,diff,l;
	
	diff=l-0;
	for(i=0;i<n;i++)
	{

		if(arr.A[i]-i!=diff)
		{
			printf("Missing element %d\n",i+diff);
			break;
		}
	}
	Display(arr);
	return 0;
		
}




