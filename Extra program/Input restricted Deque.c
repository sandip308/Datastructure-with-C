#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define size 5
int left=-1;
int right=-1;
int A[size];
void insert_Right(int x)
{
  if((left==right+1)||(right==size-1) )
	{
		if(left !=0 && right ==size-1)
		{
			right=0;
			A[right]=x;
		}
		else
		printf("Dequeue is full\n");
	}
	else if(left=-1&& right==-1)
	{
		left=0;
		right=0;
		A[right]=x;
	}
	else
	{
		right++;
		A[right]=x;
	}
}
int delete_Right()
{
  int delet;
  if(right==-1)
  {
    printf("Deque is empty\n");
    exit(0);
  }
  delet=A[right];
  if(left==right)
  {
    left=-1;
    right=-1;
  }
  else
  {
    if(right==0)
    {
      right=size-1;
    }
    else
    {
      right=right-1;
    }
  }
  return(delet);
}
int delete_left()
{
  int delet;
  if(left==-1)
  {
    printf("Deque is empty\n");
    exit(0);
  }
  delet=A[left];
  if(left==right)
  {
    left=-1;
    right=-1;
  }
  else
  {
    if(left==size-1)
    {
       left=0;
    }
    else
    {
       left=left+1;
    }
  }
  return(delet);
}
void display()
{
  int l,R;
  l=left;
  R=right;
  if(l==-1)
  {
    printf("Deque is empty\n");
    exit(0);
  }
  if(l<=R)
  {
    while(l<=R)
    {
      printf("%d\n",A[l]);
      l++;
    }
  }
    else
    {
      while(l==size-1)
      {
        printf("%d\n",A[l]);
        l++;
      }
      l=0;
      while(l<=R)
      {
        printf("%d\n",A[l]);
        l++;
      }
    }
}
void main()
{
  int n,p;
  int m,s;
  while(1)
  {
    printf("Enter 1. to insert right\n");
    printf("Enter 2. to delete right\n");
    printf("Enter 3. to delete left\n");
    printf("Enter 4. to display\n");
    printf("Enter 5. to exit\n");
    printf("Enter your choice : ");
    scanf("%d",&n);
    switch (n) {
      case 1:
      printf("Enter the value to be insert_Right\n");
      scanf("%d",&p);
      insert_Right(p);
      break;
      case 2:
        m=delete_Right();
        printf("The deleted element is= %d\n",m);
        break;
        case 3:
        s=delete_left();
        printf("The deleted element is=%d\n",s);
        break;
        case 4:
        display();
        break;
        case 5:
        exit(0);
        break;
        default:
        printf("You enter wrong choice\n");
    }
  }
}
