#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct node *link;
}node;
node *Header;
node* createnode()
{
    node *p;
    p= (node*)malloc(sizeof(node));
    return (p);
}
void insert_few()
{
    node *ptr, *t;
    ptr=createnode();
    printf("Enter a element to be insert few elements\n");
    scanf("%d",&ptr->data);
    ptr->link=NULL;
    if(Header==NULL)
    Header=ptr;
    else
    {
      t=Header;
	  while (t->link!=NULL)
	  	t=t->link;
		  t->link=ptr;
	}
	return(ptr);
}

void reverse_string()
{
    node *ptr1,*ptr2,*ptr3;
    ptr3=Header;
    ptr1=NULL;
    ptr2=NULL;
    while(ptr3!=NULL)
    {
        ptr2=ptr3->link;
        ptr3->link=ptr1;
        ptr1=ptr3;
        ptr3=ptr2;
    }
    Header=ptr1;
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
    int n;
    while(1)
    {
        printf("\n\n");
        printf("\t\t\tEnter 1. to insert few elements\n");
        printf("\t\t\tEnter 2. to Reverse elements\n");
        printf("\t\t\tEnter 3. to Display\n");
        printf("Enter your choice: ");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            insert_few();
            break;
        case 2:
           reverse_string();
           break;
        case 3:
            display();
            break;
        default:
            printf("You entered wrong choice\n");
        }
    }
}
