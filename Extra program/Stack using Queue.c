#include<stdio.h>
#include<stdlib.h>
#define size 15
typedef struct Queue
{
    int rear,front;
    int sizeQ;
    int *arr;
}queue;
int count;
queue* createqueue(int n)
{
    queue *Q;
    Q=(queue*)malloc(sizeof(queue));
    if(Q==NULL)
    {
        printf("Insufficient memory\n");
        exit(0);
    }
    Q->sizeQ=n;
    Q->front=n-1;
    Q->rear=n-1;
    Q->arr=(int*)malloc(Q->sizeQ*sizeof(int));
    return(Q);
}
void Enqueue(queue *Q, int x)
{
    int i;
    if(count==Q->sizeQ)
    {
      printf("Queue is full\n");
    }
    else
    {
      Q->rear = (Q->rear + 1) % Q->sizeQ;
      Q->arr[Q->rear] = x;
      count++;
    }
}
int Dequeue(queue *Q)
{
    int item;
    if(count==0)
        printf("Queue is empty\n");
    else
    {
        Q->front = (Q->front + 1) % Q->sizeQ;
      item = Q->arr[Q->front];
       count--;
    return item;
    }
}
int queuecount(queue *Q)
{
    return (count);
}
int pop(queue *Q)
{
    int i,n;
    int p;
    n=queuecount(Q);
    for(i=0;i<n-1;i++)
    {
        p=Dequeue(Q);
        Enqueue(Q,p);
    }
    p=Dequeue(Q);
    return(p);
}
void push(queue *Q, int x)
{
    Enqueue(Q,x);
}
void view(queue *Q)
{
    int i;
    int F;
    F=queuecount(Q);
    if(count==0)
    {
        printf("Queue is empty\n");
    }
    else
    {
        i = (Q->front + 1) % Q->sizeQ;
      while(F--)
      {
        printf("%d ",Q->arr[i]);
        if(i>=Q->sizeQ)
            i=0;
        else
            i=i+1;
      }
    }
}
void main()
{
    queue *V;
    int z;
    int M,t;
    V=createqueue(size);
    while(1)
    {
        printf("\n\n");
        printf("\t\t $$$$$$$$$$$$$ MENU ITEMS $$$$$$$$$$$$$$");
        printf("\n\n");
        printf("\t\t\t\t 1. PUSH\n");
        printf("\t\t\t\t 2. POP\n");
        printf("\t\t\t\t 3. Display\n");
        printf("Enter your choice: ");
        scanf("%d",&M);
        switch(M)
        {
        case 1:
            printf("Enter the value to be pushed\n");
            scanf("%d",&z);
            push(V, z);
            printf("%d value has been pushed\n",z);
            break;
        case 2:
           t= pop(V);
           printf("The poped value is=%d\n",t);
           break;
        case 3:
            view(V);
            break;
        default :
            printf("You entered wrong choice\n");

        }
    }
}

