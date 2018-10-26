#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
typedef struct Tree
{
    int data;
    struct Tree *lchild;
    struct Tree *rchild;
}tree;
int get_y_dir()
{
    int y;
    CONSOLE_SCREEN_BUFFER_INFO sp;
    if(GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&sp))
    {
       y=sp.dwCursorPosition.Y;
    }
    return(y);
}
void gotoxy(int x,int y)
{
  COORD v;
  v.X=x;
  v.Y=y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),v);
}
tree* createnode()
{
    tree *ptr;
    printf("Enter the data which you want to insert\n");
    ptr=(tree*)malloc(sizeof(tree));
    scanf("%d",&ptr->data);
    ptr->lchild=NULL;
    ptr->rchild=NULL;
    return(ptr);
}
void insertion(tree *Root, tree *ptr1)
{
        if(ptr1->data<Root->data)
        {
            if(Root->lchild!=NULL)
            {
                insertion(Root->lchild,ptr1);
            }
            else
                Root->lchild=ptr1;
        }
        if(ptr1->data>Root->data)
        {
            if(Root->rchild!=NULL)
            {
                insertion(Root->rchild,ptr1);
            }
            else
                Root->rchild=ptr1;
        }
}
void del_node(tree *Root)
{
    tree *ptr,*parent;
    int flag=0,item1,item;
    ptr=Root;
    printf("Enter the data which you want to delete\n");
    scanf("%d",&item);
    while((ptr!=NULL)&&(flag==0))
    {
        if(item<ptr->data)
        {
           parent=ptr;
           ptr=ptr->lchild;
        }
        if(item>ptr->data)
        {
            parent=ptr;
            ptr=ptr->rchild;
        }
        if(item==ptr->data)
        {
            flag=1;
        }
    }
    if(flag==0)
        printf("Item not found\n");
        if(ptr->lchild==NULL&&ptr->rchild==NULL)
        {
            if(parent->rchild==ptr)
                parent->rchild=NULL;
            else
                parent->lchild=NULL;
            free(ptr);
        }
        else
        {
           if(ptr->lchild!=NULL&&ptr->rchild!=NULL)
           {
               tree *ptr1,*parent1=NULL;
              ptr1=ptr->rchild;
              if(ptr1!=NULL)
              {
                  while(ptr1->lchild!=NULL)
                  {
                      parent1=ptr1;
                      ptr1=ptr1->lchild;
                  }
              }
              item1=ptr1->data;
              if(parent1==NULL)
              {
                  if(ptr1->rchild!=NULL)
                  {
                      ptr->rchild=ptr1->rchild;
                      free(ptr1);
                  }
                  else
                    ptr->rchild=NULL;
                    free(ptr1);
              }
              else
              {
                if(ptr1->rchild!=NULL)
                {
                    parent1->lchild=ptr1->rchild;
                    free(ptr1);
                }
                else
                {
                    parent1->lchild=NULL;
                    free(ptr1);
                }
              }
             ptr->data=item1;
           }
           else
           {
              if(parent->rchild==ptr)
              {
                  if(ptr->rchild!=NULL)
                    parent->rchild=ptr->rchild;
                  else
                    parent->rchild=ptr->lchild;
              }
              else
              {
                  if(parent->lchild==ptr)
                  {
                      if(ptr->lchild!=NULL)
                        parent->lchild=ptr->lchild;
                      else
                        parent->lchild=ptr->rchild;
                  }
              }
              free(ptr);
           }
        }
}
int get_height(tree *Root)
{
    int right=0,left=0;
   if(Root==NULL)
   {
       return;
   }
     left=get_height(Root->lchild)+1;
     right=get_height(Root->rchild)+1;
     if(left>right)
        return(left);
     else
        return(right);
}
void draw_Tree(tree *Root,int c,int h,int X,int Y)
{
    int i,y;
    y=Y+1+h*(h+1)/2 - c*(c+1)/2;
    gotoxy(X,y);
    printf("%d",Root->data);
    if(Root->rchild!=NULL)
    {
        for(i=1;i<=(c-1);i++)
        {
            gotoxy(X+i,y+i);
            printf("\\");
        }
        draw_Tree(Root->rchild,c-1,h,X+c,Y);
    }
    if(Root->lchild!=NULL)
    {
        for(i=1;i<=c-1;i++)
        {
            gotoxy(X-i,y+i);
            printf("/");
        }
        draw_Tree(Root->lchild,c-1,h,X-c,Y);
    }
}
void Inorder(tree *Root)
{
    if(Root!=NULL)
    {
        Inorder(Root->lchild);
        printf("%d ",Root->data);
        Inorder(Root->rchild);
    }
}
void preorder(tree *Root)
{
    if(Root!=NULL)
    {
        printf("%d ",Root->data);
        preorder(Root->lchild);
        preorder(Root->rchild);
    }
}
void postorder(tree *Root)
{
    if(Root!=NULL)
    {
        postorder(Root->lchild);
        postorder(Root->rchild);
        printf("%d ",Root->data);
    }
}
void search_tree(tree *Root)
{
    int flag=0;
    int item;
    printf("Enter the data which you want to search\n");
    scanf("%d",&item);
    tree *ptr;
    ptr=Root;
    while(ptr!=NULL && flag==0)
    {
        if(item<ptr->data)
        {
          ptr=ptr->lchild;
        }
        else if(item>ptr->data)
        {
           ptr=ptr->rchild;
        }
        else if(item==ptr->data)
        {
           flag=1;
        }
    }
    if(ptr==NULL)
      printf("Key not found in the tree\n");
    else
      printf("%d key is found in the tree\n",item);
}
void main()
{
    int n,h;
    tree *Root=NULL,*ptr;
    while(1)
    {
        printf("\n\n\n\n\n\n");
      printf("\t\t\t 1.insert value into tree\n");
      printf("\t\t\t 2.display the tree\n");
      printf("\t\t\t 3.Inorder traversal\n");
      printf("\t\t\t 4.preorder traversal\n");
      printf("\t\t\t 5.postorder traversal\n");
      printf("\t\t\t 6.search element in tree\n");
      printf("\t\t\t 7.Delete an element from a tree\n");
      printf("Enter your choice: ");
      scanf("%d",&n);
     switch(n)
     {
      case 1:
       ptr=createnode();
       if(Root==NULL)
       {
           Root=ptr;
       }
       else
        insertion(Root,ptr);
       break;
     case 2:
       printf("The tree is: ");
       h=get_height(Root);
       draw_Tree(Root,h,h,h*(h+1)/2,get_y_dir());
       break;
     case 3:
        Inorder(Root);
        break;
     case 4:
        preorder(Root);
        break;
     case 5:
        postorder(Root);
        break;
     case 6:
        search_tree(Root);
        break;
     case 7:
        del_node(Root);
        break;
     default:
        printf("You entered wrong choice\n");
        break;
    }
  }
}
