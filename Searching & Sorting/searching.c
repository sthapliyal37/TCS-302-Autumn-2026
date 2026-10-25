#include<stdio.h>
#include<stdlib.h>
void linear_search(int arr[],int n)
{
    int key,i;
    printf("\nEnter the Key to be searched::\t");
    scanf("%d",&key);

    for(i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
            printf("\nElement Found at Index %d",i);
            break;
        }
    }
    if(i==n)
        printf("\nElement is Not Present\n");


}

void binary_search(int arr[],int n)
{
    int key,flag=0;
    printf("\nEnter the Key to be searched::\t");
    scanf("%d",&key);
    int left=0,right=n-1,mid;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(arr[mid]==key)
        {
            flag=1;
            printf("\nElement Found at Index %d",mid);
            break;
        }
        else if(arr[mid]<key)
        {
            left=mid+1;
        }
        else{
            right=mid-1;
        }

    }
    if(!flag)
        printf("\nElement is Not Present\n");
}
int main()
{
    int *arr=NULL;
    int n,i;
    printf("\nEnter the size of Array::\t");
    scanf("%d",&n);

    arr=(int*)malloc(sizeof(int)*n);
    printf("\nEnter the array elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    //linear_search(arr,n);
    binary_search(arr,n);
    return 0;
}