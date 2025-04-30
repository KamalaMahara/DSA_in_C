#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *address;
};

// Global pointer to the top of the stack
struct node *top = NULL;

// Function to push an element onto the stack
void push(int value) {
    struct node *nnode = (struct node*)malloc(sizeof(struct node));
    if (nnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    nnode->data = value;
    nnode->address = top;  // New node points to current top
    top = nnode;           // Update top to the new node
    printf("%d pushed to stack\n", value);
}

// Function to pop an element from the stack
void pop() {
    if (top == NULL) {
        printf("Stack is empty. Can't pop\n");
        return;
    }
    struct node *temp = top;
    printf("Popped element is %d\n", temp->data);
    top = top->address;  // Move top pointer to next node
    free(temp);          // Free memory
}

// Function to display the stack
void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct node *temp = top;
    printf("Stack elements:\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->address;
    }
}

// Main function
int main() {
    int choice, value;
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be pushed: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
