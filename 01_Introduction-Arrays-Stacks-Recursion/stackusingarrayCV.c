#include<stdio.h>
#define MAX 5

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

int push(int stack[MAX],int top)
{
    if(isFull(top))
    {
        printf("\nStack is Full\n");
        return top;
    }
    printf("\nEnter the Element::\t");
    scanf("%d",&stack[++top]);
    return top;
}
int pop(int stack[MAX],int top)
{
    if(isEmpty(top))
    {
        printf("\nStack is Empty\n");
        return top;
    }
    printf("\nElement Deleted %d\n",stack[top--]);
    return top;
}
void peek(int stack[MAX],int top)
{
      if(isEmpty(top))
    {
        printf("\nStack is Empty\n");
        return ;
    }
    printf("\nElement at Top %d\n",stack[top]);
}
void display(int stack[MAX],int top)
{
     if(isEmpty(top))
    {
        printf("\nStack is Empty\n");
        return ;
    }
    while(top>=0)
        printf("%d ",stack[top--]);
}




int main()
{
    int stack[MAX],top=-1,choice;
    char ch;
    do{
        printf("\nEnter your Choice\n");
        printf("\n1::Push\n2::Pop\n3::Peek\n4::Display\n5::isEmpty\n6::isFull");
        scanf("%d",&choice);   
        switch(choice)
        {
            case 1: top=push(stack,top);
                    break;
            case 2: top=pop(stack,top);
                    break;
            case 3: peek(stack,top);
                    break;
            case 4: display(stack,top);
                    break;
            case 5: if(isEmpty(top))
                        printf("\nStack is Empty\n");
                    else
                        printf("\nStack is Not Empty\n");
                    break;
            case 6: if(isFull(top))
                        printf("\nStack is FUll\n");
                    else
                        printf("\nStack is Not Full\n");
                    break;
            default: printf("\nWrong Choice\n");
        } 

        printf("\nDo You want to Continue.. Y or N::\t");
        scanf(" %c",&ch);
    }while(ch=='y' || ch=='Y');

    return 0;
}