#include<stdio.h>
#include<string.h>
#define MAX 100
int isFull(int top)
{
	if(top==MAX-1)   
		return 1;	
	return 0;
}
int isEmpty(int top)
{
	if(top==-1)	
		return 1;
	return 0;
}

void push(char arr[],int *top,char c)
{
	if(isFull(*top))
	{
		printf("\nStack Overflow");
		return;
	}
    arr[++(*top)]=c;
}

void pop(char arr[],int *top)
{
	if(isEmpty(*top))
	{
		printf("\nStack Underflow");
		return;
	}
    arr[(*top)--];
}

char peek(char arr[],int top)
{
	if(isEmpty(top))
	{
		printf("\nStack Underflow");
		return '\0';
	}
    return arr[top];
}

void traverse(int arr[],int top)
{
	if(isEmpty(top))
	{
		printf("\nStack Underflow");
		return;
	}
	while(top>=0)
	{
		printf("%d " ,arr[top--]);

	}	
}
int isOperator(char c)
{
    if(c=='+' || c=='-'||c=='*'||c=='/'||c=='^')
        return 1;
    return 0;

}
int isrightassociative(char c)
{
    if(c=='^')
        return 1;
    return 0;

}
int tellprecedence(char c)
{
    if(c=='+' || c=='-')
        return 1;
    else if(c=='*' || c=='/')
        return 2;
    else if(c=='^')
        return 3;
    return -1;
}
int isopeningBracket(char c)
{
    if(c=='(' || c=='{' || c=='[' || c=='<')
        return 1;
    return 0;
}

int isclosingBracket(char c)
{
    if(c==')' || c=='}' || c==']' || c=='>')
        return 1;
    return 0;
}
//function to find difference between opening and closing bracket
int findAdd(char c)
{
    if(c==')')
        return 1;
    return 2;

}

//Function to Convert infix expression into Postfix

void infixtopostfix(char str[])
{
    int i=0,precedence,top=-1,curr=0,add=0;
    char stack[MAX];
    char result[MAX];
    for(i=0;i<strlen(str);i++)
    {
        if(isOperator(str[i]))              // If Operator (+,-,*,/,^) Found
        {
            precedence=tellprecedence(str[i]);
            if(isEmpty(top) || tellprecedence(stack[top])<precedence)       //if stack is empty or current operator is of higher precedence than top of stack
            {
                push(stack,&top,str[i]);
            }
            else
            {
                //if operator of less precedence or (equal precedence but left associative) than pop it
                while(!isEmpty(top) &&(tellprecedence(stack[top])>precedence) || ((tellprecedence(stack[top])==precedence) && !isrightassociative(str[i])))
                {
                    result[curr++]=peek(stack,top);
                    pop(stack,&top);
                }
                //push the current operator 
                push(stack,&top,str[i]);
            }
        }
        else if(isopeningBracket(str[i])) // if opening bracket found
        {
            push(stack,&top,str[i]);
        } 
        else if(isclosingBracket(str[i]))  // if closing bracket found then pop till its opening bracket 
        {
            add=findAdd(str[i]);            // to calculate ascci value (as () has difference of 1 and all other has difference of 2)
            while(!isEmpty(top) && peek(stack,top)!=str[i]-add)
            {
                result[curr++]=peek(stack,top);
                pop(stack,&top);
            }
            if(!isEmpty(top)) 
                pop(stack,&top);
            else        // if stack becomes empty without finding opening bracket it means expression is wrong
                    return ;                
        }
        else        // if operand then add into string
        {
            result[curr++]=str[i];
        }
    }
     while(!isEmpty(top))
    {
                    result[curr++]=peek(stack,top);
                    pop(stack,&top);
    }
    result[curr++]='\0';
   printf("Postfix Expression :: %s",result);
}

//Main Function

int main()
{
    char str[MAX];
    printf("\nEnter the String::\t");
    scanf("%s",&str);
    infixtopostfix(str);
  return 0;
}