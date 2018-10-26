#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int count=1;
void permutation(char *ptr,int i,int n)
{
  int j;
  if(i==n)
   {
     printf("The number of possible string is=%d ->%s\n",count++,ptr);
   }
   else
   {
       for(j=i;j<=n;j++)
       {
          interchange((ptr+i),(ptr+j));
          permutation(ptr,i+1,n);
          interchange((ptr+i),(ptr+j));
       }
   }
}
void interchange(char *c, char *p)
{
    char temp;
    temp=*c;
    *c=*p;
    *p=temp;
}
void main()
{
    char A[10];
    printf("Enter a string\n");
    gets(A);
    permutation(A,0,strlen(A)-1);
}
