#include<stdio.h>
#include<stdlib.h>
#define maxsize 10
int circularq[maxsize];
int front=-1;
int rear=-1;

void enqueue();
void dequeue();
void display();

int main()
{
    int choice;
    while(1)
    {
         printf("\n1.Enqueue()\n2.Dequeue()\n3.Display()\n4.Exit()\n");
         printf("Enter your choice:");
         scanf("%d", &choice);
         switch(choice)
         {
             case 1:
                 enqueue();
                 break;
             case 2:
                 dequeue();
                 break;
             case 3:
                 display();
                 break;
             case 4:
                 exit(0);
                 break;
             default:
                 printf("Invalid choice\n");
                 break;
         }
    }
}

void enqueue()
{
    int n;
    if((rear + 1) % maxsize == front)
    {
        printf("Queue is overflow\n");
    }
    else
    {
        printf("Enter the element to be inserted in queue\n");
        scanf("%d", &n);
        if(front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
            circularq[rear] = n; // Fix added here
        }
        else
        {
            rear = (rear + 1) % maxsize;
            circularq[rear] = n;
        }
        printf("Inserted %d \n", n); // Fix semicolon
    }
}

void dequeue()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is underflow \n");
    }
    else if(front == rear)
    {
        printf("Deleted element is %d \n", circularq[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("Deleted element is %d \n", circularq[front]);
        front = (front + 1) % maxsize;
    }
}

void display()
{
    int i;
    if(rear == -1 && front == -1)
    {
        printf("Queue is empty \n");
    }
    else
    {
        printf("Queue elements are:\n");
        for(i = front; i != rear; i = (i + 1) % maxsize)
        {
            printf("%d ", circularq[i]); // Add space for clarity
        }
        printf("%d ", circularq[i]); // Last element
    }
}