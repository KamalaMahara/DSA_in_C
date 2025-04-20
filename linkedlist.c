#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *address;
};

struct node *start = NULL;

void create();
void display();
void insert_on_first();
void insert_on_last();
void insert_on_middle();
void delete_from_first();
void delete_from_last();
void delete_from_middle();

int main() {
    int choice;
    while (1) {
        printf("\nLinked List Menu:\n");
        printf("1. Create\n");
        printf("2. Insert at First\n");
        printf("3. Insert at Last\n");
        printf("4. Insert at Middle (any position)\n");
        printf("5. Delete from First\n");
        printf("6. Delete from Last\n");
        printf("7. Delete from Middle\n");
        printf("8. Display\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: create(); break;
            case 2: insert_on_first(); break;
            case 3: insert_on_last(); break;
            case 4: insert_on_middle(); break;
            case 5: delete_from_first(); break;
            case 6: delete_from_last(); break;
            case 7: delete_from_middle(); break;
            case 8: display(); break;
            case 9: 
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
}

void create() {
    struct node *nnode, *temp;
    int n;
    char ch;

    printf("Enter the element: ");
    scanf("%d", &n);

    start = (struct node*) malloc(sizeof(struct node));
    start->data = n;
    start->address = NULL;
    temp = start;

    printf("Do you want to continue to create new nodes (y/n)? ");
    scanf(" %c", &ch);

    while (ch == 'Y' || ch == 'y') {
        printf("Enter the new element: ");
        scanf("%d", &n);

        nnode = (struct node*) malloc(sizeof(struct node));
        nnode->data = n;
        nnode->address = NULL;
        temp->address = nnode;
        temp = nnode;

        printf("Do you want to continue to create new nodes (y/n)? ");
        scanf(" %c", &ch);
    }
    printf("Linked List created successfully!\n");
}

void display() {
    struct node *temp;
    if (start == NULL) {
        printf("Linked List is empty.\n");
        return;
    }
    temp = start;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->address;
    }
    printf("NULL\n");
}

void insert_on_first() {
    struct node *nnode;
    int n;
    printf("Enter the element to insert at first: ");
    scanf("%d", &n);

    nnode = (struct node*) malloc(sizeof(struct node));
    nnode->data = n;
    nnode->address = start;
    start = nnode;

    printf("Element inserted at first.\n");
}

void insert_on_last() {
    struct node *nnode, *temp;
    int n;
    printf("Enter the element to insert at last: ");
    scanf("%d", &n);

    nnode = (struct node*) malloc(sizeof(struct node));
    nnode->data = n;
    nnode->address = NULL;

    if (start == NULL) {
        start = nnode;
    } else {
        temp = start;
        while (temp->address != NULL) {
            temp = temp->address;
        }
        temp->address = nnode;
    }

    printf("Element inserted at last.\n");
}

void insert_on_middle() {
    struct node *nnode, *temp;
    int n, pos, i = 1;

    if (start == NULL) {
        printf("Linked List is empty. Create it first.\n");
        return;
    }

    printf("Enter the position to insert the element: ");
    scanf("%d", &pos);
    printf("Enter the element: ");
    scanf("%d", &n);

    nnode = (struct node*) malloc(sizeof(struct node));
    nnode->data = n;

    temp = start;
    if (pos == 1) {
        nnode->address = start;
        start = nnode;
    } else {
        while (i < pos - 1 && temp != NULL) {
            temp = temp->address;
            i++;
        }
        if (temp == NULL) {
            printf("Position out of range.\n");
            free(nnode);
            return;
        }
        nnode->address = temp->address;
        temp->address = nnode;
    }

    printf("Element inserted at position %d.\n", pos);
}

void delete_from_first() {
    struct node *temp;
    if (start == NULL) {
        printf("Linked List is empty.\n");
        return;
    }
    temp = start;
    start = start->address;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

void delete_from_last() {
    struct node *temp, *prev;
    if (start == NULL) {
        printf("Linked List is empty.\n");
        return;
    }

    temp = start;
    if (temp->address == NULL) {
        printf("Deleted element: %d\n", temp->data);
        free(temp);
        start = NULL;
    } else {
        while (temp->address != NULL) {
            prev = temp;
            temp = temp->address;
        }
        prev->address = NULL;
        printf("Deleted element: %d\n", temp->data);
        free(temp);
    }
}

void delete_from_middle() {
    struct node *temp, *prev;
    int pos, i = 1;
    if (start == NULL) {
        printf("Linked List is empty.\n");
        return;
    }

    printf("Enter the position to delete the element: ");
    scanf("%d", &pos);

    if (pos == 1) {
        temp = start;
        start = start->address;
        printf("Deleted element: %d\n", temp->data);
        free(temp);
    } else {
        temp = start;
        while (i < pos && temp != NULL) {
            prev = temp;
            temp = temp->address;
            i++;
        }
        if (temp == NULL) {
            printf("Position out of range.\n");
            return;
        }
        prev->address = temp->address;
        printf("Deleted element: %d\n", temp->data);
        free(temp);
    }
}
