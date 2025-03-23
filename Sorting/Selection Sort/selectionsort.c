#include<stdio.h>

void accept(int a[10], int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("Enter a[%d]:", i);
        scanf("%d", &a[i]);
    }
}

void selectionsort(int a[10],int n)
{
    int indexmin;
    for(int i=0;i<n;i++)
    {
        indexmin=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[indexmin])
            {
                indexmin=j;
                int t=a[i];
                a[i]=a[indexmin];
                a[indexmin]=t;
            }

        }

    }
}

void display(int a[10], int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

int main() {
    int a[10], n;
    printf("Enter the number of elements you want in the array: ");
    scanf("%d", &n);
    accept(a, n);
    printf("Entered Elements are:\n");
    display(a, n);
    selectionsort(a, n);
    printf("Sorted Elements are:\n");
    display(a, n);
    return 0;
}
