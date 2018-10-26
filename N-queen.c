#include<stdio.h>
#include<math.h>
 
int b[20],count;
 
int main()
{
 int n,i,j;
 void Nqueen(int row,int n);
 printf("\n\nEnter number of Queens:");
 scanf("%d",&n);
 Nqueen(1,n);
 return 0;
}
void print(int n)
{
 int i,j;
 printf("\n\nSolution %d:\n\n",++count);
 
 for(i=1;i<=n;++i)
  printf("\t%d",i);
 
 for(i=1;i<=n;++i)
 {
  printf("\n\n%d",i);
  for(j=1;j<=n;++j) 
  {
   if(b[i]==j)
    printf("\tQ"); 
   else
    printf("\t-"); 
  }
 }
}
int place(int row,int col)
{
 int i;
 for(i=1;i<=row-1;++i)
 {
  
  if(b[i]==col)
   return 0;
  else
   if(abs(b[i]-col)==abs(i-row))
    return 0;
 }
 
 return 1; 
}
 
void Nqueen(int row,int n)
{
 int col;
 for(col=1;col<=n;++col)
 {
  if(place(row,col))
  {
   b[row]=col; 
   if(row==n) 
    print(n); 
   else 
    Nqueen(row+1,n);
  }
 }
}
