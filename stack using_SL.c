#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node *link;
}node;
node *Header=NULL;
node* createnode()
{
    node *ptr;
    ptr=(node*)malloc(sizeof(node));
    return(ptr);
}
void push()
{
    node *new_node, *Top;
	new_node=createnode();
	printf("Enter a new node element\n");
	scanf("%d",&new_node->data);
	new_node->link=NULL;
	if(Header==NULL)
	Header=new_node;
	else
	{
		Top=Header;
		new_node->link=Top;
		Header=new_node;
		Top=new_node;
	}
}
int pop()
{
    int item;
    node *Top,*ptr;;
    Top=Header;
	if(Top==NULL)
	{
		printf("Stack is empty\n");
		exit(0);
	}
	else
	{
	    item=Top->data;
       ptr=Top;
	  Top=Top->link;
	  Header=Header->link;
	  ptr->link=NULL;
	  free(ptr);
    }
    return(item);
}
void display()
{
    node *ptr3;
    if(Header==NULL)
    {
    	printf("Linked list is empty\n");
	}
	else
	{
	  ptr3=Header;
    while(ptr3!=NULL)
    {
        printf("%d\n",ptr3->data);
        ptr3=ptr3->link;
    }
   }
}
void main()
{
    int n,p;
    while(1)
    {
        system("color 9");
        printf("Enter 1. to push\n");
        printf("Enter 2 to pop\n");
        printf("Enter 3. to display\n");
        printf("Enter your choice: ");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            push();
            break;
        case 2:
            p=pop();
            printf("The poped value is= %d\n",p);
            break;
        case 3:
            display();
            break;
        default:
            printf("You entered wrong choice\n");
        }
    }
}
