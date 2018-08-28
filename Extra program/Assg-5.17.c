#include<stdio.h>
#include<stdlib.h>
#define size 10
int front=0,rear=0,q[size];

void enqueue(int x)
{
	int next;
	if(front==0)
	{
		front=1;
		rear=1;
		q[rear]=x;
	}
	else
	{
		next=(rear%size)+1;

		if(next!=front)
		{
			rear=next;
			q[rear]=x;
		}
		else
		{
			printf("queue is full");
			exit(0);
		}
	}
}
int dequeue()
{
		int item;
	if(front==0 )
    printf("Queue is empty..");
    else
    {
    	item=q[front];
    	if(front==rear)
    	{
    		front=0;
    		rear=0;
		}
		else
    {
			front=(front%size)+1;
    }
	}
	return(item);
}
void display()
{
         int i;
        printf("Queue is : \n");
        if(front<=rear)
        {

		for (i = front; i <= rear; i++)
            printf("%d ", q[i]);

		}
		else
		{
			for(i=front;i<=size;i++)
			   printf("%d ", q[i]);

			   for(i=1;i<=rear;i++)
			   printf("%d ", q[i]);
		}
}
int main()
{
    int choice,c;
    int S;
    while (1)
    {
        printf("\n\n");
        printf("1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Display all elements of queue \n");
        printf("4.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            printf("Enter the elements>>");
			scanf("%d",&c);
            enqueue(c);
            break;
            case 2:
            S=dequeue();
            printf("The deleted item is=%d ",S);
            break;
            case 3:
            display();
            break;
            case 4:
            exit(1);
            default:
            printf("Wrong choice \n");
        }
    }
}
