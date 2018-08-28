#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node *link;
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
    printf("Enter a element\n");
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
void insert_pos(int key)
{
	node *temp, *t;
	int X;
	temp=(node*)malloc(sizeof(node));
	printf("Enter the new node data\n");
	scanf("%d",&X);
	temp->link=NULL;
	if(temp==NULL)
	{
		printf("Insufficient memory\n");
		exit(0);
	}
	else
	{
		t=Header;
		while(t->data!=key && t->link!=NULL)
		{
			t=t->link;
		}
		if(t->data==key)
		{
			temp->link=t->link;
			t->link=temp;
			temp->data =X;
		}
		else
		printf("Key is not found\n");
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
    int n,key;
    while(1)
    {
        printf("\t\t 1. to insert few elements\n");
        printf("\t\t 2. to enter key after which the node to be insert\n");
        printf("\t\t 3. to display\n");
        printf("\t\t 4. to exit\n");
        printf("Enter your choice\t");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            insert_item();
            break;
        case 2:
            printf("Enter the key\n");
            scanf("%d",&key);
            insert_pos(key);
            break;
        case 3:
            display();
            break;
        default:
            printf("You entered wrong choice\n");
            break;
        }
    }
    return 0;
}
