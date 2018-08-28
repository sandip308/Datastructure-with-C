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
void insert_end()
{
    node *ptr, *t;
    ptr=createnode();
    printf("Enter a element to be insert end\n");
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
        printf("\t\t 1. to insert end\n");
        printf("\t\t 2. to view\n");
        printf("\t\t 3. to exit\n");
        printf("Enter your choice\t");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            insert_end();
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
