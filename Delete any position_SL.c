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
    printf("Enter a element first\n");
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
void delete_node(int key)
{
    node *ptr, *ptr1;
    ptr=Header;
    if(Header==NULL)
    {
        printf("List is empty\n");
        exit(0);
    }
    else
    {
        if(ptr->data==key)
        {
            Header=Header->link;
            ptr->link=NULL;
            free(ptr);
        }
        else
        {
          while(ptr->link!=NULL && ptr->data!=key)
          {
            ptr1=ptr;
            ptr=ptr->link;
          }
           if(ptr->data==key)
           {
              ptr1->link=ptr->link;
              ptr->link=NULL;
              free(ptr);
           }
           else
            printf("Key is not found...Try again\n");
      }
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
        printf("%d->",ptr3->data);
        ptr3=ptr3->link;
    }
    printf("NULL");
   }
}
 main()
{
    int n,key;
    while(1)
    {
        printf("\n\n");
        printf("\t\t 1. to insert few elements\n");
        printf("\t\t 2. to delete particular position\n");
        printf("\t\t 3. to display\n");
        printf("\t\t 4. to exit\n");
        printf("Enter your choice>>> ");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            insert_item();
            break;
        case 2:
            printf("Enter the key(inserted elements)\n");
            scanf("%d",&key);
            delete_node(key);
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

