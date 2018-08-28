#include<stdio.h>
#define size 10
int top1=-1,item;
int top2=-1;
int A[size],B[size];
void push1(int x)
{
  if(top1>=size-1)
  {
      printf("Stack is overflow\n");
      exit(0);
  }
  else
  {
      top1=top1+1;
      A[top1]=x;
  }
}
int pop1()
{
   if(top1<0)
   {
    printf("Stack is empty\n");
    exit(0);
   }
   else
   {
       item=A[top1];
       top1=top1-1;
   }
   return(item);
}
void push2(int x)
{
  if(top2>=size-1)
  {
      printf("Stack is overflow\n");
      exit(0);
  }
  else
  {
      top2=top2+1;
      B[top2]=x;
  }
}
int pop2()
{
   if(top2<0)
   {
    printf("Stack is empty\n");
    exit(0);
   }
   else
   {
       item=B[top2];
       top2=top2-1;
   }
   return(item);
}
int empty1()
{
    if(top1<0)
        return(1);
    else
        return(0);
}
int empty2()
{
    if(top2<0)
        return(1);
    else
        return(0);
}
void enqueue()
{
    int data;
    printf("Enter the data to be insert in queue\n");
    scanf("%d",&data);
    push1(data);
    printf("Data inserted successfully\n");
}
int dequeue()
{
    int x,y;
    while(!empty1())
    {
        x=pop1();
        push2(x);
    }
    y=pop2();
    while(!empty2())
    {
        x=pop2();
        push1(x);
    }
    return(y);
}
void display()
{
    int i;
    if(top1<0)
    {
        printf("Stack is empty...Nothing to display\n");
    }
    for(i=0;i<=top1;i++)
    {
        printf("%d ",A[i]);
    }
}
main()
{
    int n,p;
    while(1)
    {
        printf("\n\n");
      printf("\t\tEnter 1 to enqueue in the queue\n");
      printf("\t\tEnter 2 to dequeue the value and display dequeue element\n");
      printf("\t\tEnter 3 to display the remaining elements\n");
      printf("Enter your choice: ");
      scanf("%d",&n);
      switch(n)
      {
      case 1:
        enqueue();
        break;
      case 2:
        p=dequeue();
        printf("The dequeue value is->%d ",p);
        break;
      case 3:
        display();
        break;
      default:
        printf("You entered wrong choice\n");
      }
    }
    return(0);
}

