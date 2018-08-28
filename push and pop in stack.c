#include<stdio.h>
#include<stdlib.h>
#define size 5
int top=-1,item;
int A[size];
void push()
{
    printf("Enter a element to be push on stack\n");
    scanf("%d",&item);
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
void palind()
{
    int i,flag=0;
    for(i=0;i<=top;i++)
    {
        if(A[i]!=pop())
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
        printf("Stack elements are palindrome\n");
    else
        printf("Stack elements are not palindrome\n");
}
void display()
{
    int i;
    for(i=top;i>=0;i--)
    {
        printf("%d\n",A[i]);
    }
}
main()
  {
      int c;
    while(1)
    {
      printf("\n\t\t\t..........MENU ITEMS...........\n");
      printf("\n\n");
      printf("\t\t\t Enter 1 to push the elements\n");
      printf("\t\t\t Enter 2 to pop the elements\n");
      printf("\t\t\t Enter 3 to palindrome the elements\n");
      printf("\t\t\t Enter 4 to display the items\n");
      printf("\t\t\t Enter 5 to exit\n");
      printf("\n\n");
      printf("Enter your choice\n");
      scanf("%d",&c);
      switch(c)
      {
      case 1:
        push();
        break;
      case 2:
        item=pop();
        printf("%d\n ",item);
        break;
      case 3:
        palind();
        break;
      case 4:
        display();
        break;
      case 5:
        exit(0);
        break;
        default:
        printf("You entered wrong choice");
      }
  }
}

