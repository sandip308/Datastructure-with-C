#include<stdio.h>
#include<stdlib.h>
int n,i,c;
int ptr[100],flag=0;
void create()
{
    int i;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    printf("Enter the array elements in array\n");
    for(i=0;i<n;i++)
    {
    	flag=1;
        scanf("%d",&ptr[i]);
    }
}
void display()
{
    if(flag==1)
 {
    int i;
    printf("The elements are=\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",ptr[i]);
    }
    printf("\n");
 }
 else
    {
        printf("First create the array elements\n");
        printf("\n\n");
    }
}
void insert()
{
	int pos,insim;
	if(n>=100)
	{
		printf("No space is available\n");

	}
	else
	{
    if(flag==1)
   {
    printf("Enter the number that you want to insert\n");
    scanf("%d",&insim);
    printf("Enter the position\n");
    scanf("%d",&pos);
    pos=pos-1;
    if(pos>n)
    {
    	printf("Give the position according to the size\n");
    	printf("\n\n");
	}
	else
  {
   for(i=n;i>pos;i--)
   {
       ptr[i]=ptr[i-1];
   }
    ptr[pos]=insim;
  printf("After inserting the elements are\n");
  for(i=0;i<=n;i++)
      printf("%d\n",ptr[i]);
       n++;
   }
}
    else
    {
        printf("please ...First create the array elements\n");
        printf("\n\n");
    }
 }
}
void delet()
{
	int pos;
    if(flag==1)
{
    n--;
    printf("Enter the position that you want to delete\n");
    scanf("%d",&pos);
    pos=pos-1;
    if(n<0)
    {
        printf("There is no term to be deleted\n");
        printf("\n\n");
    }
    else
   {
    for(i=pos;i<n;i++)
    {
       ptr[i]=ptr[i+1];
    }
    printf("After deleting the elements are :\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",ptr[i]);
    }
   }
}
else
{
    printf("Please... create the array elements\n");
    printf("\n\n");
}
}
int main()
{
    while(1)
    {
      printf("\t\t\t ..............MENU ITEMS..............\n");
      printf("\n\n");
      printf("\t\t\t Enter 1 to create N integer elements\n");
      printf("\t\t\t Enter 2 to display the array elements\n");
      printf("\t\t\t Enter 3 to insert an elements in particular position\n");
      printf("\t\t\t Enter 4 to delete an elements \n");
      printf("\t\t\t Enter 5 to exit\n");
      printf("\n\n");
      printf("Enter your choice :\n");
      scanf("%d",&c);
      switch(c)
      {
          case 1:
             create();
              break;
          case 2:
            display();
            break;
          case 3:
            insert();
            break;
          case 4:
            delet();
            break;
          case 5:
            exit(0);
            break;
          default:
            printf("You enter wrong number\n");
      }
    }

    return 0;
}

