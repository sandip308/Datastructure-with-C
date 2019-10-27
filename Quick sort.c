#include<stdio.h>
int part(int A[],int L, int U)
{
    int x,j,i,temp1;
    x=A[U];
    i=L-1;
    for(j=L;j<=U-1;j++)
    {
        if(A[j]<=x)
        {
            i=i+1;
            temp1=A[j];
            A[j]=A[i];
            A[i]=temp1;
        }
    }
    temp1=A[U];
    A[U]=A[i+1];
    A[i+1]=temp1;
    return(i+1);
}
void quicksort(int A[],int L, int U)
{
    int q,i;
  if(L<U)
  {
      q=part(A,L,U);
      quicksort(A,L,q-1);
      quicksort(A,q+1,U);
  }
}
void main()
{
    int arr[20],n,i;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the array elements\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }
    quicksort(arr,1,n);
    printf("The sorted array is= ");
  for(i=1;i<=n;i++)
  {
  	printf("%d\t",arr[i]);
  }
}

