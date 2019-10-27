#include<stdio.h>
#include<stdlib.h>
#define Max 10
typedef struct Queue
{
   int Front;
   int Rear;
   int arr[Max];
}queue;
int size;
queue* createqueue(int p)
{
    queue *Q;
    Q=(queue*)malloc(sizeof(queue));
    Q->Front=-1;
    Q->Rear=-1;
    Q->arr[p];
    return(Q);
}
int queuesize(queue *Q)
{
    return(Q->arr[size]);
}
int empty(queue *Q)
{
    if(Q->Front==-1&&Q->Rear==-1)
        return(1);
    else
        return(0);
}
int full(queue *Q)
{
    if(Q->Front==0&&Q->Rear==size-1)
        return(1);
    else if(Q->Front==Q->Rear+1)
        return(1);
    else
    return(0);
}
void Enqueue(queue *Q,int value)
{
   if(size<1)
   {
       printf("Invalid Size\n");
   }
      if(Q->Front==-1&&Q->Rear==-1)
       {
          Q->Front=0;
          Q->Rear=0;
          Q->arr[0]=value;
       }
       else if(full(Q))
       {
           Q->Rear=Q->Rear+1;
           Q->arr[Q->Rear]=value;
       }
       else
       {
          Q->Rear=Q->Rear+1;
          Q->arr[Q->Rear]=value;
       }
}
int Dequeue(queue *Q)
{
    int item;
       if((empty(Q)))
       {
           printf("Queue is empty\n");
       }
    else
    {
        item=Q->arr[Q->Front];
        if(Q->Front==Q->Rear)
        {
           Q->Front=-1;
           Q->Rear=-1;
        }
        else
        {
            Q->Front=Q->Front+1;
        }
        return(item);
    }
}
void display(queue *Q)
{
    int i;
    if(empty(Q))
    {
        printf("Queue is empty\n");
    }
    else
    {
      for(i=Q->Front;i<=Q->Rear;i++)
      {
        printf("%d ",Q->arr[i]);
      }
    }
}
void main()
{
    queue *S;
    int A,n,value,item;
    while(1)
    {
        printf("\n\n");
        printf("\t\t1. Create an Queue\n");
        printf("\t\t2. Check the Queue status\n");
        printf("\t\t3. Display the Queue\n");
        printf("\t\t4. Enqueue the elements to the queue\n");
        printf("\t\t5. Dequeue the element from queue\n");
        printf("\t\t6. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d",&A);
        switch(A)
        {
        case 1:
            printf("Enter the size of the queue\n");
            scanf("%d",&size);
            S= createqueue(size);
            break;
        case 2:
            printf("Front=%d\n Rear=%d\n",S->Front,S->Rear);
            break;
        case 3:
            display(S);
            break;
        case 4:
            printf("Enter the value to be insert\n");
            scanf("%d",&value);
            Enqueue(S,value);
            break;
        case 5:
            item=Dequeue(S);
            printf("The dequeue element is=%d\n",item);
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("You entered wrong choice\n");
        }
    }
}
