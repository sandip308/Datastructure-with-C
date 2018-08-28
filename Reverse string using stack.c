#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 5
int top=-1;
char A[size],item;
void push(char item)
{
  if(top>=size-1)
  {
      printf("Stack is overflow\n");
      exit(0);
  }
  else
  {
      top=top+1;
      A[top]=item;
  }
}
char pop()
{
  
   if(top<0)
   {
    printf("Stack is empty\n");
    exit(0);
   }
   else
   {
       item=A[top];
       top=top-1;
   }
   return(item);
}
int main()
{
  char s[size];
  int i;
  printf("Enter a string\n");
  gets(s);
  for(i=0;s[i]!='\0';i++)
  {
    push(s[i]);
  }
    while(top!=-1)
    {
      printf("%c",pop());
    }

}
