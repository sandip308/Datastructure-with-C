#include<stdio.h>
int main()
{
    int i,n,key;
    int arr[50],flag=0,loc=0;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    printf("Enter the array elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the element that you want to search\n");
    scanf("%d",&key);
    for(i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
            flag=1;
            loc=i;
            break;
        }
    }
    if(flag==1)
    {
        printf("Key is found\n");
        printf("Location of the key is=%d",i+1);
    }
    else
        printf("Key is not found\n");

}
