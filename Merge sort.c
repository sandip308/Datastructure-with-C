#include<stdio.h>
#include<stdlib.h>
void merge_sort(int A[],int L,int U)
{
    int q;
    if(L<U)
    {
      q=((L+U)/2);
      merge_sort(A,L,q);
      merge_sort(A,q+1,U);
      merge(A,L,q,U);
    }
}
void merge(int A[],int L,int q,int U)
{
    int n1,n2,i,j,k;
    int C[20],D[20];
    n1=(q-L+1);
    n2=U-q;
    C[n1+1];
    D[n2+1];
    for(i=1;i<=n1;i++)
    {
        C[i]=A[L+i-1];
    }
    for(j=1;j<=n2;j++)
    {
        D[j]=A[q+j];
    }
    
    C[i]=987562;
    D[j]=965472;
    i=1;
    j=1;
    
    for(k=L;k<=U;k++)
    {
        if(C[i]<=D[j])
        {
            A[k]=C[i];
            i++;
        }
        else
        {
            A[k]=D[j];
            j++;
        }
    }
}

void main()
{
    int n,arr[20],i;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    printf("Enter the array elements\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }
    merge_sort(arr,1,n);
    printf("After sorting the elements are:\n");
    for(i=1;i<=n;i++)
    {
        printf("%d\n",arr[i]);
    }

}
