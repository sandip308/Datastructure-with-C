#include<stdio.h>
#include<stdlib.h>
#define size 10
int Rear=-1;
int Front=-1;
int A[size];
void Enqueue(int x)
{
    if(Rear==(size-1))
    {
        printf("Queue is full\n");
        exit(0);
    }
    else
    {
        if(Front==-1)
            Front=0;
         Rear=Rear+1;
        A[Rear]=x;
    }
}
int Dequeue()
{
    int item;
    if(Front==-1||Front>Rear)
    {
        printf("Queue is empty\n");
        exit(0);
    }
    else
    {
       item=A[Front];
       if(Front==Rear)
            Front=Rear=-1;
       else
        Front=Front+1;
    }
    return(item);
}
void display()
{
    int i;
    if(Front==-1&&Rear==-1)
        printf("Queue is empty\n");
    else
    {
    printf("Queue is=\n");
    for(i=Front;i<=Rear;i++)
    {
        printf("%d->",A[i]);
    }
    }
}
void main()
{
    int n,p;
    int item;
    while(1)
    {
    printf("\n\n");
    printf("\t\t .............MENU ITEMS...............\n");
    printf("\n\n");
    printf("\t\t\t1. to Enqueue\n");
    printf("\t\t\t2. to dequeue\n");
    printf("\t\t\t3. to display\n");
    printf("\t\t\t4. to exit\n");
    printf("Enter your choice:-> ");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        printf("Enter a element to Enqueue this queue\n");
        scanf("%d",&p);
        Enqueue(p);
        break;
    case 2:
        item=Dequeue();
        printf("The dequeue element is=%d",item);
        break;
    case 3:
        display();
        break;
    case 4:
        exit(0);
        break;
    default:
        printf("You entered wrong choice\n");
    }
  }
}
