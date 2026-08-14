#include<stdio.h>
#define MAX 10

int isFull(int rear)
{
    if(rear==MAX-1)
        return 1;
    return 0;
}
int isEmpty(int front)
{
    if(front==-1)
        return 1;
    return 0;
}
void enqueue(int queue[MAX],int *rear)
{
    if(isFull(*rear))
    {
        printf("\nQueue is Full\n");
        return;
    }
    printf("\nEnter the Element to be inserted::\t");
    scanf("%d",&(queue[++(*rear)]));
}
void dequeue(int queue[MAX],int *front)
{
    if(isEmpty(*front))
    {
        printf("\nQueue is Empty\n");
        return;
    }
    printf("\nElement Deleted:: %d\t",queue[(*front)++]);
}
void peek(int queue[],int front)
{
    if(isEmpty(front))
    {
        printf("\nQueue is Empty\n");
        return;
    }
    printf("\nElement at Front:: %d\t",queue[front]);
}
void display(int queue[],int rear,int front)
{
    if(isEmpty(front))
    {
        printf("\nQueue is Empty\n");
        return;
    }
    while(front<=rear)
        printf("%d ",queue[front++]);
}
int main()
{
    int queue[MAX],front=-1,rear=-1,choice;
    char ch;
    do{
        printf("\nSelect the Task:: 1::Enqueue\n2::Dequeue\n3::Peek\n4::Display\n5::isEmpty\n6::isFull");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: enqueue(queue,&rear);
                    if(front==-1 && rear>-1)
                        front=rear;
                    break;
            case 2: dequeue(queue,&front);
                    if(front>rear)
                        front=rear=-1;
                    break;
            case 3: peek(queue,front);
                    break;
            case 4: display(queue,rear,front);
                    break;
            case 5: if(isEmpty(front))
                        printf("\nQueue is Empty\n");
                    else
                        printf("\nQueue is Not Empty\n");
                    break;
            case 6: if(isFull(rear))
                        printf("\nQueue is Full\n");
                    else
                        printf("\nQueue is Not full\n");
                    break;
            default: printf("\nWrong Choice\n");
        }
        printf("\nDo you want to continue.. Y or N");
        scanf(" %c",&ch);
    }while(ch=='y' || ch=='Y');


}