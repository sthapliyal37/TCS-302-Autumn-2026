#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void bubble_sort(int *arr,int n)
{
    int i,j;
    int flag=0;
    int count=0;
    for(i=0;i<n-1;i++)
    {
        flag=0;
        for(j=0;j<n-i-1;j++)
        {
            count++;
            if(arr[j+1]<arr[j])
            {
                
                flag=1;
                swap(&arr[j+1],&arr[j]);
            }
        }
        if(!flag)
            break;
    }
    printf("\nTotal Iterations::%d",count);
}
void selection_sort(int *arr,int n)
{
    int curr_index=0,minimum_index=0,inner_loop=0;
    for(curr_index=0;curr_index<n-1;curr_index++)
    {
        minimum_index=curr_index;
        for(inner_loop=curr_index+1;inner_loop<n;inner_loop++)
        {
            if(arr[minimum_index]>arr[inner_loop])
            {
                minimum_index=inner_loop;
            }
        }
        if(curr_index!=minimum_index)
            swap(&arr[curr_index],&arr[minimum_index]);
    }
}

void insertion_sort(int *arr,int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        j=i;
        temp=arr[i];
        while(j>0 && arr[j-1]>temp)
        {
            arr[j]=arr[j-1];
            j--;
        }
        arr[j]=temp;
    }
}
int partition(int *arr,int low,int high)
{
    int pivot=arr[high];
    int i=low-1;           
    int j;
    for(j=low;j<high;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);   
    return i+1;
}

void quick_sort_rec(int *arr,int low,int high)
{
    if(low<high)
    {
        int p=partition(arr,low,high);
        quick_sort_rec(arr,low,p-1);
        quick_sort_rec(arr,p+1,high);
    }
}

void quick_sort(int *arr,int n)
{
    quick_sort_rec(arr,0,n-1);
}

void merge(int *arr,int *tmp,int left,int mid,int right)
{
    int i=left,j=mid+1,k=left;
    while(i<=mid && j<=right)
    {
        if(arr[i]<=arr[j])          
            tmp[k++]=arr[i++];
        else
            tmp[k++]=arr[j++];
    }
    while(i<=mid)
        tmp[k++]=arr[i++];
    while(j<=right)
        tmp[k++]=arr[j++];
    for(k=left;k<=right;k++)
        arr[k]=tmp[k];
}

void merge_sort_rec(int *arr,int *tmp,int left,int right)
{
    int mid;
    if(left>=right)
        return;
    mid=left+(right-left)/2;        
    merge_sort_rec(arr,tmp,left,mid);
    merge_sort_rec(arr,tmp,mid+1,right);
    merge(arr,tmp,left,mid,right);
}

void merge_sort(int *arr,int n)
{
    int *tmp;
    if(n<2)
        return;
    tmp=(int *)malloc(n*sizeof(int));   
    if(tmp==NULL)
    {
        fprintf(stderr,"merge_sort: out of memory\n");
        return;
    }
    merge_sort_rec(arr,tmp,0,n-1);
    free(tmp);
}



int main()
{
    int *arr=NULL,n,i;
    printf("\nEnter the Size of Array::\t");
    scanf("%d",&n);
    arr=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    bubble_sort(arr,n);
    printf("\n After Sorting::");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    return 0;
}