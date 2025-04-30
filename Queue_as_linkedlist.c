#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *next;
};

// Global pointers to the front and rear of the queue
struct node *front = NULL;
struct node *rear = NULL;

// Function to enqueue (insert)
void enqueue(int value) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        // Queue is empty
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d enqueued to queue\n", value);
}

// Function to dequeue (delete)
void dequeue() {
    if (front == NULL) {
        printf("Queue is empty. Can't dequeue\n");
        return;
    }
    struct node *temp = front;
    printf("Dequeued element is %d\n", temp->data);
    front = front->next;
    free(temp);

    if (front == NULL) {
        // Queue became empty after deletion
        rear = NULL;
    }
}

// Function to display the queue
void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct node *temp = front;
    printf("Queue elements:\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

// Main function
int main() {
    int choice, value;
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
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
