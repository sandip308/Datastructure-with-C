#include<stdio.h>
int main()
{
  int arr[20],i,j,n,temp;
  printf("Enter the size of the array\n");
  scanf("%d",&n);
  printf("Enter the array elements\n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);
  }
  for(i=1;i<n;i++)
  {
    temp=arr[i];
    for(j=i-1;j>=0&&temp<arr[j];j--)
    {
      arr[j+1]=arr[j];
    }
    arr[j+1]=temp;
  }
  printf("After insertion sort the elements are\n");
  for(i=0;i<n;i++)
  {
    printf("%d\n",arr[i]);
  }
  return 0;
}
