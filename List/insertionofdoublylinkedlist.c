#include <stdio.h>
#include <stdlib.h>

#define NEW_NODE (struct node *)malloc(sizeof(struct node))

struct node {
    struct node *previous;
    int data;
    struct node *next;
};

// Function to create a doubly linked list
struct node *createList(struct node *H, int n) {
    struct node *S;
    H = NEW_NODE;
    if (H == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    H->next = NULL;
    H->previous = NULL;
    scanf("%d", &H->data);
    S = H;
    for (int i = 0; i < n - 1; i++) { // Corrected loop condition
        S->next = NEW_NODE;
        if (S->next == NULL) {
            printf("Memory allocation failed\n");
            return H; // Or handle the error appropriately
        }
        S->next->previous = S;
        S = S->next;
        scanf("%d", &S->data);
    }
    S->next = NULL; // End of list
    return H;
}

// Function to display the doubly linked list
void display(struct node *H) {
    struct node *s = H;
    printf("Linked list:\n");
    while (s != NULL) {
        printf("%d\t", s->data);
        s = s->next;
    }
    printf("\n");
}

// Function to display the doubly linked list in reverse
void revdisplay(struct node *H) {
    struct node *s = H;

    if(H == NULL) return;

    while (s->next != NULL) {
        s = s->next;
    }

    printf("Reversed Linked list:\n");
    while (s != NULL) {
        printf("%d\t", s->data);
        s = s->previous;
    }
    printf("\n");
}

// Function to calculate the length of the doubly linked list
int length(struct node *H) {
    struct node *s = H;
    int l = 0; // Initialize length to 0
    while (s != NULL) {
        l++;
        s = s->next;
    }
    return l;
}

// Function to insert a new node at a specified position
struct node *insert(struct node *H, int x, int pos) {
    struct node *s, *t;
    int i;

    t = NEW_NODE;
    if (t == NULL) {
        printf("Memory allocation failed\n");
        return H;
    }
    t->data = x;
    t->next = NULL;
    t->previous = NULL;

    if (H == NULL && pos == 1) {
        return t;
    }

    s = H;

    // Case 1: Insert at the beginning (position 1)
    if (pos == 1) {
        t->next = H;
        if(H != NULL) H->previous = t;
        H = t;
        return H;
    } else {
        // Traverse to the position where we want to insert
        for (i = 1; i < pos - 1 && s != NULL; i++) {
            s = s->next;
        }

        if (s == NULL) {
            printf("Invalid position\n");
            free(t);
            return H;
        } else {
            t->next = s->next;
            t->previous = s;
            if (s->next != NULL) {
                s->next->previous = t;
            }
            s->next = t;

            return H;
        }
    }
}

int main() {
    int n, ch, l, x, pos;
    struct node *H = NULL;

    while (1) {
        printf("Menu\n");
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Length\n");
        printf("4. Insert\n");
        printf("5. Revdisplay\n");
        printf("6. Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the number of elements you want in the linked list:\n");
                scanf("%d", &n);
                H = createList(H, n); // Create the linked list
                break;
            case 2:
                display(H); // Display the linked list
                break;
            case 3:
                l = length(H);
                printf("The length of the linked list is %d\n", l); // Display the length
                break;
            case 4:
                printf("Enter the position where you want to insert:\n");
                scanf("%d", &pos);
                l = length(H);
                if (pos < 1 || pos > l + 1) {
                    printf("Invalid position\n");
                } else {
                    printf("Enter the data to be inserted:\n");
                    scanf("%d", &x);
                    H = insert(H, x, pos); // Insert the new node
                }
                break;
            case 5:
                revdisplay(H);
                break;
            case 6:
                exit(0); // Exit the program
                break;
            default:
                printf("Please enter a correct choice\n");
        }
    }
    return 0;
}