#include<stdio.h>
void accept(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void display(int *a,int n)
{
    int i;
    for (i=0;i<n;i++)
    {
        printf("%d",*(a+i));
    }
    printf("\n");
}
int main()
{
    int arr1[10],arr2[10],arr3[10],n,i;
    printf("How many elements you would like to have in the array?: ");
    scanf("%d",&n);
    printf("Enter elements of first array: ");
    accept(arr1,n);
    printf("Enter elements of second array: ");
    accept(arr2,n);
    for(i=0;i<n;i++)
    {
        arr3[i]=arr1[i]+arr2[i];  
    }
    printf("Elements of 1st array: ");
    display(arr1,n);
    printf("Elements of 2nd array: ");
    display(arr2,n);
    printf("Elements of 3rd array: ");
    display(arr3,n);
    return 0;
}