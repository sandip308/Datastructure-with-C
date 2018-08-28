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
void insert_item()
{
    node *ptr, *t;
    ptr=createnode();
    printf("Enter a element to be insert \n");
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
}
void delet()
{
	node *temp;
	if(Header==NULL)
	{
		printf("No node exist\n");
		exit(0);
	}
	else
	{
		temp=Header;
	  Header=Header->link;
	  temp->link=NULL;
	  free(temp);
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
        printf("%d\t",ptr3->data);
        ptr3=ptr3->link;
    }
   }
}
 main()
{
    int n;
    while(1)
    {
    	printf("\n\n");
        printf("\t\t 1. to insert item\n");
        printf("\t\t 2. to delete from 1st position\n");
        printf("\t\t 3. to display elements\n");
        printf("\t\t 4. to exit\n");
        printf("Enter your choice\t");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            insert_item();
            break;
        case 2:
            delet();
            break;
        case 3:
            display();
            break;
        case 4:
        	exit(0);
            break;
        default:
            printf("You entered wrong choice\n");
            break;
        }
    }
    return 0;
}
