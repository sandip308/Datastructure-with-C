#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,j,n,temp,mid=0;
    int arr[50];
    int key,h,l,flag=0;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    printf("Enter the array elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the number that you want to search\n");
    scanf("%d",&key);
     for(i=0;i<n;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
    printf("After sorting the array elements are\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }
    h=n-1;
    l=0;
    while((l<=h)&&(flag==0))
    {
        mid=(l+(h-l)*(key-arr[l])/(arr[h]-arr[l]));
        if(arr[mid]==key)
        {
            flag=1;
        }
        else if(arr[mid]>key)
        {
            h=mid-1;
            flag=0;
        }
        else if(arr[mid]<key)
        {
            l=mid+1;
            flag=0;
        }
    }
    if(flag==1)
    {
        printf("Key search successful\n");
        printf("The position of the key is=%d",mid+1);
    }
    else
    {
        printf("Key not found\n");
    }
    return(0);
}
