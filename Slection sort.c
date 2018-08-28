#include<stdio.h>
int min (int ,int );
int  arr[15];
int main()
{
  int i,j,n,temp;
  printf("Enter a range of the array\n");
  scanf("%d",&n);
  printf("Enter the array elements\n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);
  }
  for(i=0;i<=n-2;i++)
  {
    j=min(i,n);
      temp=arr[i];
      arr[i]=arr[j];
      arr[j]=temp;
  }
  printf("After sorting the array elements are\n");
  for(i=0;i<n;i++)
  {
    printf("%d\n",arr[i]);
  }
}
int min (int k,int size)
{
  int minimum,minloc,p;
  minimum=arr[k];
  minloc=k;
  for(p=k+1;p<=size-1;p++)
  {
    if(minimum>arr[p])
    {
      minimum=arr[p];
      minloc=p;
    }
  }
  return minloc;
}
