#include<stdio.h>
void accept(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Enter the element at position %d: ",i+1);
        scanf("%d",&a[i]);
    }
}

void b_sort(int a[],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

int binary_search(int a[],int n,int key)
{
    int low=0,high=n-1,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==key)
            return mid;
        else if(a[mid]>key)
            high=mid-1;
        else
            low=mid+1;
    }
    return -1;
}

int main()
{
    int a[100],n,key,pos;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    accept(a,n);
    b_sort(a,n);
    printf("Enter the element to be searched: ");
    scanf("%d",&key);
    pos=binary_search(a,n,key);
    if(pos==-1)
        printf("Element not found\n");
    else
        printf("Element found at position %d\n",pos+1);
    return 0;
}