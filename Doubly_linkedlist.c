#include <stdio.h>
#include <stdlib.h>

struct doubly_node {
    int data;
    struct doubly_node *prev;
    struct doubly_node *next;
};

struct doubly_node *head = NULL, *tail = NULL, *newnode;

// Function to add a node to the end
void addnode(int value) {
    newnode = (struct doubly_node*)malloc(sizeof(struct doubly_node));
    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = NULL;

    if (head == NULL) {
        head = tail = newnode;
    } else {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}

// Function to display the list
void display() {
    struct doubly_node *temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("List elements are:\n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to delete a node by value
void deleteNode(int value) {
    struct doubly_node *temp = head;

    while (temp != NULL) {
        if (temp->data == value) {
            if (temp == head && temp == tail) {
                head = tail = NULL;
            } else if (temp == head) {
                head = head->next;
                head->prev = NULL;
            } else if (temp == tail) {
                tail = tail->prev;
                tail->next = NULL;
            } else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }

            free(temp);
            printf("Node with value %d deleted.\n", value);
            return;
        }
        temp = temp->next;
    }

    printf("Value %d not found in the list.\n", value);
}

// Main function with menu
int main() {
    int choice, value;

    do {
        printf("\n----- Doubly Linked List Menu -----\n");
        printf("1. Add node\n");
        printf("2. Display list\n");
        printf("3. Delete node by value\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to add: ");
                scanf("%d", &value);
                addnode(value);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please enter 1–4.\n");
        }
    } while (choice != 4);

    return 0;
}
