#include<stdio.h>
#include<string.h>

/*int main ()
{
	char *s= "welcomeshivam";
	int i;
	for(i=0;s[i]!='\0';i++)
	{
		s[i]=s[i]-32;	
	}
	printf("%s",s);
//	printf("Length is %d",i);
	return 0;
}*/

/*9int main()
{
	char A[]="wElCoMe";
	int i;
	for(i=0;A[i]!='\0';i++)
	{
		if(A[i]>=65 && A[i]<=90)
		A[i]+=32;
		
	else if(A[i]>=97&&A[i]<=122)
		A[i]-=32;
	}
	printf("%s",A);
}*/
/*
int main()
{
	char A[]="How are you";
	int i,Vcount=0,Ccount=0,word=1;
	for (i=0;A[i]!='\0';i++)
	{
		if(A[i]=='a'||A[i]=='e'||A[i]=='i'||A[i]=='o'||A[i]=='u'||A[i]=='A'||A[i]=='E'||
		  A[i]=='I'||A[i]=='O'||A[i]=='U')
		  {
		  	Vcount++;
		  }
		  else if((A[i]==' ')&&A[i-1]!=' ')
		  word++;
		  else if((A[i]>=65&&A[i]<=90)||(A[i]>=97&&A[i]<=122))
		  {
		  	Ccount++;
		  }
	}
	printf("Vowles are:%d\n Consonents are:%d\n Total words:%d",Vcount,Ccount,word);
	return 0;
}*/
/*
int validate(char *name)
{
	int i;
	for(i=0;name[i]!='\0';i++)
	{
		if(!(name[i]>=65&&name[i]<=90)&&!(name[i]>=97&&name[i]<=122)&&
		!(name[i]>=48&&name[i]<=57))
		return 0;	
	}
	return 1;
}
int main()
{
	char * name ="Shivam671";
	if(validate (name))
	{
		printf("Valid string ");
	}
	else {
		printf("Invalid string");
	}
}*/
/*
int main()
{
	char A[]="mavihs";
	char B[7],t;
	int i,j;
	//M-1
//	for (i=0;A[i]!='\0';i++)
//	{
		
//	}
//	i=i-1;
//	for(j=0;i>=0;i--,j++)
//	{
//		B[j]=A[i];			
//	}
//	B[j]='\0';
//	printf("%s",B);
	
	//M-2
	for(j=0;A[j]!='\0';j++)
	{
	}
	j=j-1;
	for(i=0;i<j;i++,j--)
	{
		t=A[i];
		A[i]=A[j];
		A[j]=t;
	}
	
	printf("%s",A);
	
	return 0;
}*/
/*
int main()
{
	char A[]="Painter";
	char B[]="Painting";
	int i,j;
	for(i=0,j=0;A[i]!='\0'&& B[j]!='\0';i++,j++)
	{
		if (A[i]!=B[j])
		break;
	}
	if (A[i]==B[j])
	 printf("Equal");
	 else if (A[i]<B[j])
	 printf ("Smaller");
	 else 
	 printf("Greater");
	 return 0;
    }*/
/*
int main()
{
	char A[]="madam";
	char B[6];
	int i,j;
	printf("%s\n",A);
	for(i=0;A[i]!='\0';i++)
	{
		
	}
	i=i-1;
	for (j=0;i>=0;i--,j++)
	{
		B[j]=A[i];
	}
	B[j]='\0';
	printf("%s",B);
	if(B==A)
	{
	printf("\nString is Palindrome.");
	  
		}
	else
	printf("\nNot Palindrome.");
	return 0;
}*/
/*
int main()
{
	char A[]="shivam";
	char B[6];
	int i,j;
	//printf("%s\n",A);
	for(i=0;A[i]!='\0';i++)
	{
		
	}
	i=i-1;
	for (j=0;i>=0;i--,j++)
	{
		A[j]==A[i];
			
	}
			printf("Palindrome");
			return 0;
}
*/
/*

int main()
{
	char A[]="finding";
	int H[26],i;
	for (i=0;A[i]!='\0';i++)
	{
		H[A[i]-97]+=1;
	}
	for(i=0;i<26;i++)
	
		if(H[i]>1)
	
	printf("%c",i+97);
	printf("%c",H[i]);
 
	return 0;
}*/


