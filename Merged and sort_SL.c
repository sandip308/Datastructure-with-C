#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *link;
}s1;
s1 *head1,*head2;
void create1()
{
	int i,n;
	s1 *p;
	printf("For the first linked list ---->\n");
	printf("Enter the number of node = ");
	scanf("%d",&n);
	printf("Enter the data = ");
	p=(s1 *)malloc(sizeof(s1));
	p->link=NULL;
	head1=p;
	scanf("%d",&p->data);
	for(i=0;i<n-1;i++)
	{
		p->link=(s1 *)malloc(sizeof(s1));
		printf("Enter the data = ");
		scanf("%d",&p->link->data);
		p=p->link;
	}
	p->link=NULL;
}
void create2()
{
	int i,n;
	s1 *p1;
	printf("For the second linked list ---->\n");
	printf("Enter the number of node = ");
	scanf("%d",&n);
	printf("Enter the data = ");
	p1=(s1 *)malloc(sizeof(s1));
	p1->link=NULL;
	head2=p1;
	scanf("%d",&p1->data);
	for(i=0;i<n-1;i++)
	{
		p1->link=(s1 *)malloc(sizeof(s1));
		printf("Enter the data = ");
		scanf("%d",&p1->link->data);
		p1=p1->link;
	}
	p1->link=NULL;
}

void display1()
{
	s1 *ptr;
	if(head1==NULL)
	{
		printf("Empty");
	}
	else
	{
		printf("The linked list is = ");
		ptr=head1;
		while(ptr!=NULL)
		{
			printf("%d  ",ptr->data);
			ptr=ptr->link;
		}
	}
	printf("\n");
}
void display2()
{
	s1 *ptr;
	if(head2==NULL)
	{
		printf("Empty");
	}
	else
	{
		printf("The linked list is = ");
		ptr=head2;
		while(ptr!=NULL)
		{
			printf("%d  ",ptr->data);
			ptr=ptr->link;
		}
	}
	printf("\n");
}
void sort1()
{
	s1 *ptr,*ptr1=NULL;
	ptr=head1;
	for(;ptr->link!=NULL;ptr=ptr->link)
	{
		for(ptr1=ptr->link;ptr1!=NULL;ptr1=ptr1->link)
		{
			if(ptr->data>ptr1->data)
			{
				int temp=ptr->data;
				ptr->data=ptr1->data;
				ptr1->data=temp;
			}
		}
	}
}
void sort2()
{
	s1 *ptr,*ptr1=NULL;
	ptr=head2;
	for(;ptr->link!=NULL;ptr=ptr->link)
	{
		for(ptr1=ptr->link;ptr1!=NULL;ptr1=ptr1->link)
		{
			if(ptr->data>ptr1->data)
			{
				int temp=ptr->data;
				ptr->data=ptr1->data;
				ptr1->data=temp;
			}
		}
	}
}
void merge()
{
	s1 *ptr1;
	ptr1=head1;
	if(head1==NULL)
		printf("Linked list empty");
	while(ptr1->link!=NULL)
	{
		ptr1=ptr1->link;
	}
	ptr1->link=head2;
}
main()
{
	create1();
	create2();
	display1();
	display2();
	merge();
	sort1();
	display1();
}
