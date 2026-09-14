#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node* createNode()
{
    int value;
    node *curr=(node*)malloc(sizeof(node));
    if(!curr)
    {
        printf("\nMemory Not Allocated\n");
        return curr;
    }
    else
    {
        printf("\nEnter the Value::\t");
        scanf("%d",&value);
        curr->data=value;
        curr->next=NULL;
    }
}
void insertionAtLeft(node **head)
{
    node *curr=createNode();
    if(curr==NULL)
        return;
    else
    {
        if(*head==NULL)
            *head=curr;
        else
        {
            curr->next=*head;
            *head=curr;
        }
    }
}

void insertionAtRight(node **head)
{
    node *curr=createNode(),*temp=NULL;
    if(curr==NULL)
        return;
    else
    {
        if(*head==NULL)
            *head=curr;
        else
        {
            temp=*head;
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=curr;
        }
    }
}

void insertatPosition(node **head)
{
    node *curr=createNode(),*temp=NULL;
    int position,i;
    if(curr==NULL)
        return;
  
    printf("\nEnter the Position at which you want to insert::\t");
    scanf("%d",&position);
    if(position==1)
    {
        if(*head==NULL)
        {
            *head=curr;
        }
        else
        {
            curr->next = *head;
            *head=curr;
        }
    }  
    else
    {
        temp=*head;
        i=1;
        while(temp!=NULL && i<position-1)
        {
            temp=temp->next;
            i++;
        }
        if(temp==NULL)
        {
            printf("\nInvalid Position\n");
            return;
        }
        curr->next=temp->next;
        temp->next=curr;
    }
}
node* deleteAtLeft(node *head)
{
    node *temp=NULL;
    if(head==NULL)
    {
        printf("\nLinked list is Empty\n");
        return head;
    }
    temp=head;
    head=head->next;
    temp->next=NULL;
    free(temp);
    temp=NULL;
    return head;
}
node* deleteAtRight(node *head)
{
    node *temp=NULL,*temp1=NULL;
    if(head==NULL || head->next==NULL)
        return NULL;
    temp=head;
    while(temp->next->next)
    {
        temp=temp->next;
    }
    temp1=temp->next;
    temp->next=NULL;
    free(temp1);
    temp1=NULL;
    return head;
}
node* deleteAtPosition(node *head)
{
    int position;
    node *temp=NULL;
    if(head==NULL)
        return NULL;
    printf("\nEnter the Position::\n");
    scanf("%d",&position);
    if(position==1)
        return head->next;
    position-=2;
    while(position && temp)
    {
        position--;
        temp=temp->next;
    }
    if(temp==NULL || temp->next==NULL)
    {
        printf("\nInvalid Position\n");
        return head;
    }
    temp->next=temp->next->next;
    return head;
}
void display(node *head)
{
    if(head==NULL)
    {
        printf("\nLinked list is Empty\n");
        return;
    }
        while(head)
    {
        printf("%d ",head->data);
        head=head->next;
    }
}
void displayReverse(node *head)
{
    if(head==NULL)
        return;
    displayReverse(head->next);
    printf("%d ",head->data);
}
node* reverse(node *head)
{
    node *current=NULL,*previous=NULL,*nxt=NULL;
    if(head==NULL)
        return NULL;
    current=head;
    while(current!=NULL)
    {
        nxt=current->next;
        current->next=previous;
        previous=current;
        current=nxt;
    }
    return previous;
}
int main()
{
    node *head=NULL;
    char ch;
    int choice;
    do
    {
        printf("\nEnter the Choice\n");
        printf("\n1:Insert at Left\n2:Insert at Right\n3:Insert at Given Position");
        printf("\n4:Delete at Left\n5:Delete at Right\n6:Delete at Given Position");
        printf("\n7:Display\n8:Reverse Print\n9:Reverse the LL");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insertionAtLeft(&head);
                    break;
            case 2: insertionAtRight(&head);
                    break;
            case 3: insertatPosition(&head);
                    break;
            case 4: head=deleteAtLeft(head);
                    break;
            case 5: head=deleteAtRight(head);
                    break;
            case 6: head=deleteAtPosition(head);
                    break;
            case 7: display(head);
                    break;
            case 8: displayReverse(head);
                    break;
            case 9: head=reverse(head);
                    break;
            default: printf("\nWrong Choice\n");
        }
        printf("\nDo you want to continue..Y or N");
        scanf(" %c",&ch);
    }while(ch=='Y' || ch=='y');
    return 0;
}