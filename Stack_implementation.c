#include <stdio.h>
#include <stdlib.h>
#define maxsize 10
int stack[maxsize];
int top=-1;
void push();
void pop();
void display();


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    int choice;
    do {
        printf(".....MENU FOR STACK IMPLEMENTATION.....\n");
        printf("\n1.PUSH \n2.POP \n3.DISPLAY \n4.EXIT\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 4);
    return 0;
}
void push() {
    int n;
    char continuePush = 'y';
    while (continuePush == 'y' || continuePush == 'Y') {
        if (top == maxsize - 1) {
            printf("Stack overflow!\n");
            break;
        } else {
            printf("Enter the element to push into stack: ");
            scanf("%d", &n);
            top++;
            stack[top] = n;
            printf("Element %d pushed into the stack.\n", n);
            printf("Do you want to push another element? (y/n): ");
            scanf(" %c", &continuePush);  // Note the space before %c
        }
    }
}
void display() {
    int i;
    if (top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("Elements in the stack are:\n");
        for (i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}
void pop() {
    int n;
    if (top == -1) {
        printf("Stack is empty!\n");
    } else {
        n = stack[top];
        top--;
        printf("Popped element: %d\n", n);
    }
}
