#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct node *link;
}node;
node *Header;
int c=0;
node* createnode()
{
    node *p;
    int x;
    p=(node*)malloc(sizeof(node));
    printf("Enter a element to be insert in node\n");
    scanf("%d",&x);
    p->data=x;
    p->link=NULL;
    c=c+1;
    return(p);
}
void getnode()
{
    node *ptr, *ptr1;
    ptr=createnode();
    if(Header==NULL)
     Header=ptr;
     else
     {
         ptr1=Header;
         while(ptr1->link!=NULL)
         {
             ptr1=ptr1->link;
         }
         ptr1->link=ptr;
     }
}
int link_count()
{
    return(c);
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
    int n,p;
    node *S;
    while(1)
    {
        printf("\n\n");
        printf("\t\t 1. to create the node\n");
        printf("\t\t 2. to know the count\n");
        printf("\t\t 3. to display\n\n");
        printf("Enter your choice: ");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            getnode();
            break;
        case 2:
            p=link_count();
            printf("The node count is=%d",c);
            break;
        case 3:
            display();
            break;
        default:
            printf("You entered wrong choice\n");
        }
    }
    return 0;
}
