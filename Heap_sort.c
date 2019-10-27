#include<stdio.h>
void MAX_HEAP(int arr[],int i,int n)
{
    int largest;
    int temp;
    int l = 2*i;
    int r = 2*i + 1;
    if (l <= n && arr[i] < arr[l])
    {
        largest = l;
    }
    else
    {
        largest = i;
    }
    if (r <= n && arr[r] > arr[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        MAX_HEAP(arr,largest,n);
    }
}
void Build_MAX_HEAP(int arr[],int n)
{
    int i;
    for(i = n/2; i>=1; i--)
    {
        MAX_HEAP(arr,i,n);
    }
}
void Heap_sort(int arr[],int n)
{
    int i,temp;
    Build_MAX_HEAP(arr,n);
    for (i = n; i >= 2; i--)
    {
        temp = arr[1];
        arr[1] = arr[i];
        arr[i] = temp;
        n = n-1;
        MAX_HEAP(arr,1,n);
    }
}
int main()
{
    int arr[20],n,i;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the array elements: ");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }
    Heap_sort(arr,n);
    printf("The sorted array is:= ");
   for(i=1;i<=n;i++)
   {
  	 printf("%d\t",arr[i]);
   }
}