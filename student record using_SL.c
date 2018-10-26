#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<dos.h>
typedef struct Node
{
    char name[20];
    int age;
    char dept[20];
    char ph_no[10];
    struct Node *link;
}node;
int count=0;
node *Header=NULL;
node* getnode()
{
    count++;
    node *ptr;
    ptr=(node*)malloc(sizeof(node));
    return(ptr);
}
void insert_front()
{
    node *ptr1,*ptr2;
    ptr1=getnode();
    printf("Enter the name of student\n");
    scanf("%s",&ptr1->name);
    fflush(stdin);
    printf("Enter the phone number of the student\n");
    scanf("%s",&ptr1->ph_no);
    fflush(stdin);
    printf("Enter the age of the student\n");
    scanf("%d",&ptr1->age);
    fflush(stdin);
    printf("Enter the Dept name\n");
    scanf("%s",&ptr1->dept);
    fflush(stdin);
    ptr1->link=NULL;
     if(Header==NULL)
     {
       Header=ptr1;
     }
     else
     {
       ptr2=Header;
       ptr1->link=ptr2;
       Header=ptr1;
     }
}
void delet_front()
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
void insert_end()
{
     node *ptr1, *t;
    ptr1=getnode();
    printf("Enter the name of student\n");
    scanf("%s",&ptr1->name);
    fflush(stdin);
    printf("Enter the phone number of the student\n");
    scanf("%s",&ptr1->ph_no);
    fflush(stdin);
    printf("Enter the age of the student\n");
    scanf("%d",&ptr1->age);
    fflush(stdin);
    printf("Enter the Dept name\n");
    scanf("%s",&ptr1->dept);
    fflush(stdin);
    ptr1->link=NULL;
    if(Header==NULL)
    Header=ptr1;
    else
    {
      t=Header;
	  while (t->link!=NULL)
	  	t=t->link;
		  t->link=ptr1;
	}
}
void delet_end()
{
    node *ptr, *ptr1;
	ptr=Header;
	if(ptr==NULL)
	{
		printf("Link is empty\n");
		exit(0);
	}
	else if(ptr->link==NULL)
    {
        free(ptr);
        Header=NULL;
    }
	else
	{
		while(ptr->link!=NULL)
		{
			ptr1=ptr;
			ptr=ptr->link;
		}
		ptr1->link=NULL;
		free(ptr);
	}
}
void status()
{
    printf("The node you are used in this program= %d\n",count);
    SYSTEMTIME today;
    GetSystemTime(&today);
    printf("You opened this program at=%d-%d-%d\n",today.wDay,today.wMonth,today.wYear);
    printf("You opened this program at : %s\n",__TIME__);
}
void view()
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
           printf("The name of the student is= %s\n",ptr3->name);
           printf("The age of the student is= %d\n",ptr3->age);
           printf("The Dept of the student is= %s\n",ptr3->dept);
           printf("The Ph No of this student is= %s\n",ptr3->ph_no);
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
       system("color 6");
       printf("\t\t\t1. to insert record in front\n");
       printf("\t\t\t2. to delete record from front\n");
       printf("\t\t\t3. to insert record in end\n");
       printf("\t\t\t4. to delete record from end\n");
       printf("\t\t\t5. to check the status\n");
       printf("\t\t\t6. to display record\n");
       printf("\t\t\t7. EXIT\n");
       printf("Enter your choice: ");
       scanf("%d",&n);
       switch(n)
       {
       case 1:
        insert_front();
        break;
       case 2:
        delet_front();
        break;
       case 3:
        insert_end();
        break;
       case 4:
        delet_end();
        break;
       case 5:
        status();
        break;
       case 6:
        view();
        break;
       case 7:
         exit(0);
        break;
       default :
        printf("You entered wrong choice\n");
       }
   }
}
