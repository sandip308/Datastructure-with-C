#include<stdio.h>
int main()
{
    int A[50][50],B[50][50];
    int i,j,row,col;
    printf("Enter the size of the row\n");
    scanf("%d",&row);
    printf("Enter the size of the column\n");
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
    printf("The transpose matrix is=\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
           B[j][i]=A[i][j];
        }
    }
    for(i=0;i<col;i++)
    {
        for(j=0;j<row;j++)
        {
           printf("%d\t",B[i][j]);
        }
        printf("\n");
    }
       for(i=0;i<row;i++)
      {
        for(j=0;j<row;j++)
        {
            if(A[i][j]!=B[i][j])
                break;
        }
        if(j!=row)
        {
            break;
        }
      }
      if(i==row)
      {
          printf("The matrix is a symmetric matrix\n");
      }
      else
        printf("The matrix is not a symmetric matrix\n");
    }
    else
        printf("Enter same row and column\n");
}
