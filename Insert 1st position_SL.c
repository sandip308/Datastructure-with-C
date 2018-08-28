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
void insert_beg()
{
	node *new_node, *ptr;
	new_node=createnode();
	printf("Enter a new node element\n");
	scanf("%d",&new_node->data);
	new_node->link=NULL;
	if(Header==NULL)
	Header=new_node;
	else
	{
		ptr=Header;
		new_node->link=ptr;
		Header=new_node;
	}
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
 main()
{
    int n;
    while(1)
    {
        printf("\t\t 1. to insert begining\n");
        printf("\t\t 2. to view the begining position element\n");
        printf("\t\t 3. to exit\n");
        printf("Enter your choice\t");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            insert_beg();
            break;
        case 2:
            display();
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("You entered wrong choice\n");
        }
    }
    return 0;
}
