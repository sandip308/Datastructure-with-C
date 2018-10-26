#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int Data;
    struct Node *Rlink;
    struct Node *Llink;
}node;
node *Header;
node* createnode()
{
    node *ptr;
    ptr=(node*)malloc(sizeof(node));
    if(ptr==NULL)
    {
        printf("Insufficient Memory\n");
        exit(0);
    }
    return(ptr);
}
void data_insert()
{
    node *new_node,*ptr1;
    new_node=createnode();
    printf("Enter the data to be inserted to the node\n");
    scanf("%d",&new_node->Data);
    new_node->Llink=NULL;
    new_node->Rlink=NULL;
   if(Header==NULL)
   {
       Header=new_node;
   }
   else
   {
     ptr1=Header;
     while(ptr1->Rlink!=NULL)
     {
         ptr1=ptr1->Rlink;
     }
     ptr1->Rlink=new_node;
     new_node->Llink=ptr1;
     new_node->Rlink=NULL;
   }
}
void Display()
{
    node *ptr;
    if(Header==NULL)
    {
        printf("Linked list is empty\n");
    }
    else
    {
        ptr=Header;
        while(ptr!=NULL)
        {
            printf("%d->",ptr->Data);
            ptr=ptr->Rlink;
        }
        printf("NULL");
    }
}
void main()
{
    int n;
    while(1)
    {
      printf("\t\t\t1.create double linked list\n");
      printf("\t\t\t2.Display List\n");
      printf("Enter Your choice: ");
      scanf("%d",&n);
      switch(n)
      {
      case 1:
        data_insert();
        break;
      case 2:
        Display();
        break;
      default:
        printf("You entered wrong choice\n");
        break;
      }
    }

}
