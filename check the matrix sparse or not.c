#include<stdio.h>
int main()
{
  int row,col,i,j,n,count=0;
  int A[10][10];
  printf("Enter the row of matrix\n");
  scanf("%d",&row);
  printf("Enter the column of the matrix\n");
  scanf("%d",&col);
  printf("Enter the elements of the matrix\n");
  for(i=0;i<row;i++)
  {
    for(j=0;j<col;j++)
    {
       scanf("%d",&A[i][j]);
       if(A[i][j]==0)
       {
         count++;
       }
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
  if(count>((row*col)/2))
  {
   printf("The number of zero in this sparce matrix is=%d\n",count);
   printf("The number of non Zero elements are=%d\n",(row*col)-count);
   printf("\n\n");
   printf("The sparce matrix is=\n");
   for(i=0;i<row;i++)
   {
    for(j=0;j<col;j++)
    {
      if(A[i][j]!=0)
      {
        printf("%d %d %d ",(i+1),(j+1),A[i][j]);
      }
      printf("\n");
    }
  }
}
else
{
  printf("The number of Zero elements are=%d\n",count);
  printf("The number of non Zero elements are=%d\n",(row*col)-count);
  printf("So matrix is not sparce matrix\n");
}
}
