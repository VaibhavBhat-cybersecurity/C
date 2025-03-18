#include <stdio.h>
// Function to accept array input
void accept(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Enter a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}

// Function to display array elements
void display(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Function to merge two sorted halves of an array
void merge(int a[], int lb, int mid, int ub) {
    int i = lb, j = mid + 1, k = 0;
    int b[ub - lb + 1];  // Temporary array

    while (i <= mid && j <= ub) {
        if (a[i] <= a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }

    // Copy remaining elements of left subarray
    while (i <= mid) {
        b[k++] = a[i++];
    }

    // Copy remaining elements of right subarray
    while (j <= ub) {
        b[k++] = a[j++];
    }

    // Copy sorted elements back to original array
    for (i = lb, k = 0; i <= ub; i++, k++) {
        a[i] = b[k];
    }
}

// Function to implement merge sort
void merge_sort(int a[], int lb, int ub) {
    if (lb < ub) {
        int mid = (lb + ub) / 2;
        merge_sort(a, lb, mid);
        merge_sort(a, mid + 1, ub);
        merge(a, lb, mid, ub);
    }
}


int main() {
    int a[10], n;

    printf("Enter the number of elements you want in the array (max 10): ");
    scanf("%d", &n);

    if (n > 10 || n < 1) {
        printf("Invalid input! Please enter a number between 1 and 10.\n");
        return 1;
    }

    accept(a, n);

    printf("Entered elements are:\n");
    display(a, n);

    merge_sort(a, 0, n - 1);

    printf("Sorted elements are:\n");
    display(a, n);

    return 0;
}