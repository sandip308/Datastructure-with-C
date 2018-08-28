#include<stdio.h>
char str[100],ptr[100],rep[100];
int flag=0;
void pattern(char str[],char ptr[])
{
	int i,j,k;
	int len1=0,len2=0;
	for(i=0;str[i]!='\0';i++)
	{
		len1++;
	}
	for(j=0;ptr[j]!='\0';j++)
	{
		len2++;
	}
	for(i=0;str[i+len2-1]!='\0';i++)
	{
		k=i;
		for(j=0;j<=len2-1;j++)
		{
			if(str[k]!=ptr[j])
			{
				break;
			}
			k++;
		}
		if(j==len2)
		{
			flag=1;
			j=0;
			printf("Element found at=%d\n",i+1);
		}
	}
   if(flag==1)
   {
   	printf("Search successfull\n");
   }
   else
   printf("Search unsuccessfull\n");	
}
void replace()
{
	int i=0,j=0,k,flag=0,len2=0;
	int len1=0;
	printf("Enter the replace string\n");
	gets(rep);
	for(i=0;str[i]!='\0';i++)
	{
		len1++;
	}
	for(j=0;ptr[j]!='\0';j++)
	{
		len2++;
	}
     for(i=0;str[i+len2-1]!='\0';i++)
     {
     	k=i;
     	for(j=0;j<len2;j++)
     	{
     		if(str[k]!=ptr[j])
     		{
     			break;
			 }
			 k++;
		 }
		 if(j==len2)
		 {
		 	j=0;
		 	while(ptr[j]!='\0'||rep[j]!='\0')
		 	{
		 		str[i]=rep[j];
		 		i++;
		 		j++;
			 }
			 flag=1;
		 }
		 j=0;
	 }
	 printf("The string is= %s",str);
	}
	/*for(i=0;str[i]!='\0';i++)
	{
		k=i;
		while(str[k]==ptr[j])
		{
		   if(str[k]==ptr[j])
		   {
		   	  str[k]=rep[j];
		   	  k++;
		   	  j++;
		   }
		   else
		    j=0;	
		    if(rep[j]=='\0')
		     {
		     	j=0;
		     }
   	}
		 
	}
	printf("After replaceing the string is =%s",str);*/
//}
main()
{
	int index;
	printf("Enter a string\n");
	gets(str);
	printf("Enter a pattern string\n");
	gets(ptr);
	pattern(str,ptr);
	/*if(index==-1)
	{
		printf("No match found\n");
	}
	else
	{
		printf("Match found at index no=%d\n",index);
	}*/
	replace();
}
