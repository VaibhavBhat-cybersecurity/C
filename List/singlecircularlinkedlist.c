#include<stdio.h>
#include<stdlib.h>

#define newNode (struct node *)malloc(sizeof(struct node)) // Changed macro name to avoid conflict

struct node {
    int data;
    struct node *next;
};

// Function to create a linked list
struct node* createList(struct node* H, int n) {
    int i;
    struct node *s;
    H = newNode; // Initialize the first node
    H->next = NULL;

    printf("Enter the data\n");
    scanf("%d", &H->data);
    s = H;

    for (i = 1; i < n; i++) {
        s->next = newNode; // Allocate memory for the next node
        s = s->next;
        printf("Enter the data\n");
        scanf("%d", &s->data);
    }

    s->next=H; // End of list
    return H;
}

// Function to display the linked list
void display(struct node *H) {
    struct node *s = H;
    do
    {
        printf("%d ", s->data);
        s = s->next;
        /* code */
    } while (s!=H);
    return H;

}
    

// Function to calculate the length of the linked list
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
struct node* insert(struct node *H, int x, int pos) {
    struct node *s, *t;
    int i;

    t = newNode;
    t->data = x;
    t->next = NULL;

    s = H;

    // Case 1: Insert at the beginning (position 1)
    if (pos == 1) {
        t->next = H;
        H = t;
    }
    else {
        // Traverse to the position where we want to insert
        for (i = 1; i < pos - 1 && s != NULL; i++) {
            s = s->next;
        }

        if (s == NULL) {
            printf("Invalid position\n");
        }
        else {
            t->next = s->next;
            s->next = t;
        }
    }
    return H;
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
        printf("5. Exit\n");
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
                }
                else {
                    printf("Enter the data to be inserted:\n");
                    scanf("%d", &x);
                    H = insert(H, x, pos); // Insert the new node
                }
                break;
            case 5:
                exit(0); // Exit the program
                break;
            default:
                printf("Please enter a correct choice\n");
        }
    }
    return 0;
}