#include<stdio.h>
int main()
{
    int A[20][20],flag=0;
    int i,j,k,row,col;
    printf("Enter the row of the matrix\n");
    scanf("%d",&row);
    printf("Enter the column of the matrix\n");
    scanf("%d",&col);
    if(row==col)
    {
    printf("Enter the array elements\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    printf("The matrix is=\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%d\t",A[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(i>j&&A[i][j]!=0)
            {
                flag=1;
            }
        }
    }
      if(flag==1)
     {
         printf("The matrix is a not upper triangular matrix\n");
     }
    else
        printf("The matrix is a upper triangular matrix\n");
    }
    else
        printf("Please enter equal row and column size\n");
        return 0;
}
