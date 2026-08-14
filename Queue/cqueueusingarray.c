#include<stdio.h>
#define MAX 5

int isFull(int rear,int front)
{
    if((rear+1)%MAX==front)
        return 1;
    return 0;
}
int isEmpty(int front)
{
    if(front==-1)
        return 1;
    return 0;
}
void enqueue(int queue[MAX],int *rear,int front)
{
    if(isFull(*rear,front))
    {
        printf("\nQueue is Full\n");
        return;
    }
    printf("\nEnter the Element to be inserted::\t");
    *rear=(*rear+1)%MAX;
    scanf("%d",&(queue[*rear]));
}
void dequeue(int queue[MAX],int *front,int *rear)
{
    if(isEmpty(*front))
    {
        printf("\nQueue is Empty\n");
        return;
    }
    if(*front==*rear)
    {
        printf("\nElement Deleted:: %d\t",queue[*front]);
        *front=*rear=-1;
        return;
    }   
    printf("\nElement Deleted:: %d\t",queue[*front]);
    *front=(*front+1)%MAX;
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
    while(front!=rear)
    {
        printf("%d ",queue[front]);
                front=(front+1)%MAX;
    }
    printf("%d ",queue[front]);
        
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
            case 1: enqueue(queue,&rear,front);
                    if(front==-1 && rear>-1)
                        front=rear;
                    break;
            case 2: dequeue(queue,&front,&rear);
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
            case 6: if(isFull(rear,front))
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