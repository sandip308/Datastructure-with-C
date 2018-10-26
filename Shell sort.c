#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void main()
{
    int l,n,h,p;
    int i,j,k,temp;
    int A[30];
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the array elements\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&A[i]);
    }
    l=ceil(log2(((2*n)/3)+1)/log2(3)-1);
    h=((pow(3,l)-1)/2);
    p=h;
    while(p>0)
    {
        j=p;
        while(j<n)
        {
            j=j+1;
            k=j-p;
            while(k>0)
            {
                if(A[k]>A[k+p])
                {
                    temp=A[k];
                    A[k]=A[k+p];
                    A[k+p]=temp;
                    k=k-p;
                }
                else
                    k=0;
            }
        }
        p=(p-1)/3;
    }
    printf("After sorting the elements are=\n");
    for(i=1;i<=n;i++)
    {
        printf("%d\n",A[i]);
    }
}
