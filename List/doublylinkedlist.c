#include <stdio.h>
#include <stdlib.h>
#define newnode (struct node *)malloc(sizeof(struct node))

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

struct node *create(struct node *H, int n) {
    int i;
    struct node *s, *temp;
    H = newnode;
    printf("Enter data: ");
    scanf("%d", &H->data);
    H->next = NULL;
    H->prev = NULL;
    s = H;

    for (i = 1; i < n; i++) {
        temp = newnode;
        printf("Enter data: ");
        scanf("%d", &temp->data);
        temp->next = NULL;
        temp->prev = s;
        s->next = temp;
        s = temp;
    }
    printf("Doubly Linked List created successfully!\n");
    return H;
}

void displayForward(struct node *H) {
    struct node *s = H;
    printf("Forward: ");
    while (s != NULL) {
        printf("%d ", s->data);
        if (s->next == NULL) break;
        s = s->next;
    }
    printf("\n");
}

void displayReverse(struct node *H) {
    struct node *s = H;
    if (!s) {
        printf("List is empty!\n");
        return;
    }

    while (s->next != NULL)
        s = s->next;

    printf("Reverse: ");
    while (s != NULL) {
        printf("%d ", s->data);
        s = s->prev;
    }
    printf("\n");
}

int length(struct node *H) {
    struct node *s = H;
    int l = 0;
    while (s != NULL) {
        l++;
        s = s->next;
    }
    return l;
}

void delete(struct node **H, int pos) {
    struct node *t, *s = *H;
    int l = length(*H);
    int i;

    if (pos < 1 || pos > l) {
        printf("Invalid position!\n");
        return;
    }

    if (pos == 1) {
        t = *H;
        *H = (*H)->next;
        if (*H != NULL) {
            (*H)->prev = NULL;
        }
        free(t);
        return;
    }

    if (pos == l) {
        for (i = 1; i < pos - 1; i++) {
            s = s->next;
        }
        t = s->next;
        s->next = NULL;
        free(t);
        return;
    }

    for (i = 1; i < pos - 1; i++) {
        s = s->next;
    }
    t = s->next;
    s->next = t->next;
    if (t->next != NULL) {
        t->next->prev = s;
    }
    free(t);
}

int main() {
    int choice, n, pos;
    struct node *H = NULL;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Doubly Linked List\n");
        printf("2. Display Forward\n");
        printf("3. Display Reverse\n");
        printf("4. Find Length\n");
        printf("5. Delete\n");
        printf("6. Insert\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("How many elements do you want? ");
                scanf("%d", &n);
                H = create(H, n);
                break;
            case 2:
                displayForward(H);
                break;
            case 3:
                displayReverse(H);
                break;
            case 4:
                printf("Length of the list: %d\n", length(H));
                break;
            case 5:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                delete(&H, pos);
                break;
            case 6:
                // Insert function implementation goes here
                break;
            case 7:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}