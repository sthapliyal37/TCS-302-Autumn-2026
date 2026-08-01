#include<stdio.h>
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

void push(int arr[],int *top)
{
	if(isFull(*top))
	{
		printf("\nStack Overflow");
		return;
	}
	printf("\nEnter the Element you want to push::\t");
	scanf("%d",&arr[(*top)++]);
}

void pop(int arr[],int *top)
{
	if(isEmpty(*top))
	{
		printf("\nStack Underflow");
		return;
	}
	printf("\nElement %d deleted from the Stack",arr[(*top)--]);
}

void peek(int arr[],int top)
{
	if(isEmpty(top))
	{
		printf("\nStack Underflow");
		return;
	}
	printf("\nElement %d is at the Top of the Stack",arr[top]);
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
		printf("%d " ,top--);

	}	
}

int main()
{
	int stack[MAX],top=-1,choice;
	char ch;
	do{
		printf("\nEnter the Stack Operation::\n1::Push\n2::Pop\n3::Peek\n4::isFull\n5::\nisEmpty\n6::Traverse\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: push(stack,&top);
				break;
			case 2: pop(stack,&top);
				break;
			case 3: peek(stack,top);
				break;
			case 4: isFull(top);
				break;
			case 5: isEmpty(top);
				break;
			case 6: traverse(stack,top);
				break;
			default: printf("\nWrong Choice");
		}
			printf("\nDo you want to continue.. Y or N");
			scanf("%c",&ch);
		
	}while(ch=='y'||ch=='Y');
	return 0;
}