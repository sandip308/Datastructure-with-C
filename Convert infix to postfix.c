#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define size 10
void push(int);
int pop();
int operat(char);
int precedence(char);
int item,top=-1;
int ar[size];
void push(int x)
{

	if(top>=size-1)
	{
		printf("the stack is full....overflow");
		exit(0);
	}
	else
	{
	 top=top+1;

	 ar[top]=x;
}
}

int pop()
{

	if(top<0)
	{
		printf("stack is empty..underflow");
		exit(0);
	}
	else
	{
		item=ar[top];
		top=top-1;
	}

	return item;
}
int operat(char s)
{
	if(s=='^'||s=='*'||s=='/'||s=='+'||s=='-')
	{
		return 1;
	}
	else
	return 0;
}
int precedence(char s)
{
	if(s=='^')
		return(3);
	else if(s=='*'||s=='/')
	    return (2);
	else if(s=='+'||s=='-')
	    return (1);
	else
	    return(0);
}
void InfixToPostfix(char infix_exp[], char postfix_exp[])
{
	int i, j;
	char item;
	char x;

	push('(');
	strcat(infix_exp,")");

	i=0;
	j=0;
	item=infix_exp[i];

	while(item != '\0')
	{
		if(item == '(')
		{
			push(item);
		}
		else if( isdigit(item) || isalpha(item))
		{
			postfix_exp[j] = item;
			j++;
		}
		else if(operat(item) == 1)
		{
			x=pop();
			while(operat(x) == 1 && precedence(x)>= precedence(item))
			{
				postfix_exp[j] = x;
				j++;
				x = pop();
			}
			push(x);


			push(item);
		}
		else if(item == ')')
		{
			x = pop();
			while(x != '(')
			{
				postfix_exp[j] = x;
				j++;
				x = pop();
			}
		}
		else
		{
			printf("\nInvalid infix Expression.\n");
			getchar();
			exit(1);
		}
		i++;


		item = infix_exp[i];
	}
	if(top>0)
	{
		printf("\nInvalid infix Expression.\n");
		getchar();
		exit(1);
	}
	if(top>0)
	{
		printf("\nInvalid infix Expression.\n");
		getchar();
		exit(1);
	}


	postfix_exp[j] = '\0';

}

int main()
{
	char infix[size], postfix[size];

	printf("\nEnter Infix expression : ");
	gets(infix);

	InfixToPostfix(infix,postfix);
	printf("Postfix Expression: ");
	puts(postfix);

	return 0;
}
