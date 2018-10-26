#include<stdio.h>
#include<stdlib.h>
void TOH(char ORG,char INT,char DES,int n)
{
  if(n<0)
  {
      printf("Invalid number of movement\n");
  }
  if(n==1)
  {
    printf("Move disk from %c to %c \n",ORG,DES);
  }
  if(n>1)
  {
    TOH(ORG,DES,INT,n-1);
    TOH(ORG,INT,DES,1);
    TOH(INT,ORG,DES,n-1);
  }
}
void main()
{
    system("color 3");
    int n;
    printf("Enter the number of move\n");
    scanf("%d",&n);
    TOH('A','B','C',n);
}
