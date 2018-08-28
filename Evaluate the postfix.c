#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 10
int top=-1,item;
int A[size];
void push()
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
int pop()
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
main()
{
    char *ptr;
    char B[size];
    int num,n1,n2,n3;
    printf("Enter the postfix expression to evolute\n");
    gets(B);
    ptr=B;
    while(*ptr!='\0')
    {
      if ((*ptr>=48)&&(*ptr<=57))
      {
          num=*ptr-48;
          push(num);
      }
      else
      {
        n1=pop();
        n2=pop();
        switch(*ptr)
        {
        case '+':
            n3=n1+n2;
            break;
        case '-':
            n3=n2-n1;
            break;
        case '*':
            n3=n1*n2;
            break;
        case '/':
            n3=n2/n1;
            break;
        }
        push(n3);
      }
      ptr++;
    }
    printf("Result of the postfix expression is: %s = %d\n",B,pop());
}

