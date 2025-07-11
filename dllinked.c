#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node
{
  int data;
  struct Node *prev;
  struct Node *next;
};

struct Node *head = NULL, *tail = NULL;

// Function to create the first node (initialization)
void createNode(int data)
{
  struct Node *start = (struct Node *)malloc(sizeof(struct Node));
  start->data = data;
  start->prev = NULL;
  start->next = NULL;
  head = tail = start;
}

// Function to add a node at the beginning
void addBegin(int val)
{
  struct Node *nnode = (struct Node *)malloc(sizeof(struct Node));
  nnode->data = val;
  nnode->prev = NULL;
  nnode->next = head;

  if (head != NULL)
    head->prev = nnode;
  else
    tail = nnode; // If the list was empty

  head = nnode;
}

// Function to add a node at the end
void addEnd(int val)
{
  struct Node *nnode = (struct Node *)malloc(sizeof(struct Node));
  nnode->data = val;
  nnode->next = NULL;
  nnode->prev = tail;

  if (tail != NULL)
    tail->next = nnode;
  else
    head = nnode; // If the list was empty

  tail = nnode;
}

// Function to print the list
void printList()
{
  struct Node *temp = head;
  while (temp != NULL)
  {
    printf("%d <-> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

// Driver code
int main()
{
  createNode(10); // List: 10
  addBegin(5);    // List: 5 <-> 10
  addEnd(20);     // List: 5 <-> 10 <-> 20
  addEnd(25);     // List: 5 <-> 10 <-> 20 <-> 25
  addBegin(2);    // List: 2 <-> 5 <-> 10 <-> 20 <-> 25

  printList();

  return 0;
}