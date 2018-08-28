#include<stdio.h>
#include<stdlib.h>
#define size 3

struct q
{
	int front;
	int rear;
	int q[size];
}p;
void enqueue()
{
	
	int item;
	if(p.rear==size)
	printf("que is full..");
	else
	{
		printf("enter the element..");
		scanf("%d",&item);
		p.rear=p.rear+1;
		p.q[p.rear]=item;
	}
}
void dequeue()
{
	
	int item;
	if(p.front==-1 )
    printf("que is empty..");
    else
    {
    	item=p.q[p.front];
    	if(p.front==p.rear)
    	{
    		p.front=-1;
    		p.rear=-1;
		}
		else
    	p.front=p.front+1;
	}
}
void display()
{
	
	
    int i;
   

        printf("Queue is : \n");
        for (i = p.front+1; i <= p.rear; i++)
            printf("%d ", p.q[i]);
        printf("\n");

}
int main()
{
    int choice;
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
            enqueue();
            break;
            case 2:
            dequeue();
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
