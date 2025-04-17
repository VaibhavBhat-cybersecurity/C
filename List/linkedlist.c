#include <stdio.h>
#include <stdlib.h>
#define newnode (struct node *)malloc(sizeof(struct node))

struct node
{
    int data;
    struct node *next;
};

struct node *createlist(struct node *H, int n)
{
    struct node *s;
    int i;
    H = newnode;
    H->next = NULL;
    printf("Enter the data: ");
    scanf("%d", &H->data);
    s = H;

    for (i = 1; i < n; i++)
    {
        s->next = newnode;
        s = s->next;
        printf("Enter the data: ");
        scanf("%d", &s->data);
    }
    s->next = NULL;
    return H;
}

void display(struct node *H)
{
    struct node *s = H;
    while (s != NULL)
    {
        printf("%d\t", s->data);
        s = s->next;
    }
    printf("\n");
}

int length(struct node *H)
{
    int l = 0;
    struct node *s = H;
    while (s != NULL)
    {
        l++;
        s = s->next;
    }
    return l;
}

struct node *insert(struct node *H, int x, int pos)
{
    struct node *s, *t;
    t = newnode;
    t->data = x;
    t->next = NULL;
    s = H;

    if (pos == 1)
    {
        t->next = H;
        H = t;
    }
    else
    {
        for (int i = 1; i < pos - 1 && s != NULL; i++)
        {
            s = s->next;
        }
        if (s == NULL)
        {
            printf("Invalid position\n");
            free(t); // Important: Free the allocated memory if insertion fails
        }
        else
        {
            t->next = s->next;
            s->next = t;
        }
    }
    return H;
}

struct node *deletenode(struct node *H, int pos)
{
    int i;
    struct node *s, *t;
    s = H;

    if (H == NULL)
    {
        printf("List is empty!\n"); // Corrected printf format
        return H;
    }

    if (pos == 1)
    {
        H = H->next;
        free(s);
        return H;
    }
    else
    {
        for (i = 1; i < pos - 1 && s != NULL && s->next != NULL; i++) // Added s != NULL check
        {
            s = s->next;
        }

        if (s == NULL || s->next == NULL) // Corrected condition and added s == NULL check
        {
            printf("Invalid position\n"); // Corrected printf format
            return H;
        }
        else
        {
            t = s->next;
            s->next = t->next;
            free(t);
        }
    }
    return H;
}

struct node *erase(struct node *H)
{
    struct node *s = H;
    while (s != NULL)
    {
        struct node *temp = s;
        s = s->next;
        free(temp);
    }
    return NULL;
}

int main()
{
    struct node *H = NULL;
    int choice, n, pos, l, x;
    while (1)
    {
        printf("Menu\n");
        printf("1.Create\n");
        printf("2.Display\n");
        printf("3.Length\n");
        printf("4.Insert\n");
        printf("5.Delete\n"); // Added Delete option
        printf("6.Erase List\n"); // Added Erase List option
        printf("7.Exit\n");     // Corrected Exit option number
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the number of elements you want in the linked list:\n");
            scanf("%d", &n);
            H = createlist(H, n); // Create the linked list
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
            if (pos < 1 || pos > l + 1)
            {
                printf("Invalid position\n");
            }
            else
            {
                printf("Enter the data to be inserted:\n");
                scanf("%d", &x);
                H = insert(H, x, pos); // Insert the new node
            }
            break;
        case 5: // Delete node
            printf("Enter the position of the node to delete:\n");
            scanf("%d", &pos);
            l = length(H);
            if (pos < 1 || pos > l)
            {
                printf("Invalid position\n");
            }
            else
            {
                H = deletenode(H, pos);
            }
            break;
        case 6: // Erase list
            H = erase(H);
            printf("List erased successfully!\n");
            break;
        case 7:
            exit(0); // Exit the program
            break;
        default:
            printf("Please enter a correct choice\n");
        }
    }
    return 0;
}
