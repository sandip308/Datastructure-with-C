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
void insert_any(int key)
{
    int x;
    node *ptr1,*ptr2;
    ptr1=createnode();
    printf("Enter the new node data\n");
    scanf("%d",&x);
    if(ptr1==NULL)
    {
        printf("Insufficient Memory\n");
        exit(0);
    }
    else
    {
        ptr2=Header;
        while((ptr2->Rlink!=NULL)&&(ptr2->Data!=key))
        {
            ptr2=ptr2->Rlink;
        }
        if(ptr2->Rlink==NULL)
        {
            ptr2->Rlink=ptr1;
            ptr1->Llink=ptr2;
            ptr1->Data=x;
            ptr1->Rlink=NULL;
        }
        else
        {
            ptr1->Rlink=ptr2->Rlink;
            ptr2->Rlink->Llink=ptr1;
            ptr1->Llink=ptr2;
            ptr2->Rlink=ptr1;
            ptr1->Data=x;
        }
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
void del_any(int p)
{
    node *ptr;
    if(Header==NULL)
    {
        printf("No node exist\n");
        exit(0);
    }
    else
    {
        ptr=Header;
      while((ptr->Data!=p)&&(ptr->Rlink!=NULL))
      {
              ptr=ptr->Rlink;
      }
      if(ptr->Data==p)
      {
         if(ptr==Header)
         {
          Header=Header->Rlink;
          Header->Llink=NULL;
          free(ptr);
         }
         else
         {
          ptr->Llink->Rlink=ptr->Rlink;
          free(ptr);
         }
      }
      else
        printf("Key is not found\n");
    }
}
void main()
{
    int n,key,p;
    while(1)
    {
        printf("\n\n");
        printf("\t\t 1. to insert few elements\n");
        printf("\t\t 2. to enter key after which the node to be insert\n");
        printf("\t\t 3. to delete node from any position\n");
        printf("\t\t 4. to display\n");
        printf("Enter your choice: ");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            data_insert();
            break;
        case 2:
            printf("Enter the key\n");
            scanf("%d",&key);
            insert_any(key);
            break;
        case 3:
             printf("Enter the element which you want to delete\n");
             scanf("%d",&p);
             del_any(p);
             break;
        case 4:
            Display();
            break;
        default:
            printf("You entered wrong choice\n");
            break;
        }
    }
}
