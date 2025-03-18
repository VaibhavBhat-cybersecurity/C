#include<stdio.h>

void accept(int a[10], int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("Enter a[%d]:", i);
        scanf("%d", &a[i]);
    }
}

void i_sort(int a[10], int n) {
    int t, i, j;
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(a[i] > a[j]) {
                // Swap the elements
                t = a[i];
                a[i] = a[j];
                a[j] = t;
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
    i_sort(a, n);
    printf("Sorted Elements are:\n");
    display(a, n);
    return 0;
}