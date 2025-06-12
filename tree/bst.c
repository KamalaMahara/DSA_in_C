#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the BST
struct node
{
  int data;
  struct node *left, *right;
};

// Function prototypes
void display(struct node *);
struct node *insert(struct node *, int);
struct node *deleteNode(struct node *, int);
struct node *findMin(struct node *);

int main()
{
  struct node *tree = NULL;
  int choice, insertItem, deleteItem;
  char ch;

  do
  {
    printf("\nBinary Search Tree Application\n");
    printf("Menu:\n");
    printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("\nEnter data to insert: ");
      scanf("%d", &insertItem);
      tree = insert(tree, insertItem);
      break;
    case 2:
      if (tree == NULL)
      {
        printf("\nThe tree is empty.\n");
      }
      else
      {
        printf("\nEnter data to delete: ");
        scanf("%d", &deleteItem);
        tree = deleteNode(tree, deleteItem);
      }
      break;
    case 3:
      if (tree == NULL)
      {
        printf("\nThe tree is empty.\n");
      }
      else
      {
        printf("\nTree elements: ");
        display(tree);
        printf("\n");
      }
      break;
    case 4:
      exit(0);
    default:
      printf("\nInvalid choice! Try again.\n");
    }

    printf("\nDo you want to continue? (y/n): ");
    while (getchar() != '\n')
      ; // Flush input buffer
    scanf("%c", &ch);
  } while (ch == 'y');

  return 0;
}

// Insert a node into BST
struct node *insert(struct node *root, int value)
{
  if (root == NULL)
  {
    root = (struct node *)malloc(sizeof(struct node));
    root->data = value;
    root->left = root->right = NULL;
    return root;
  }

  if (value < root->data)
  {
    root->left = insert(root->left, value);
  }
  else
  {
    root->right = insert(root->right, value);
  }

  return root;
}

// Find the minimum value node
struct node *findMin(struct node *root)
{
  while (root->left != NULL)
  {
    root = root->left;
  }
  return root;
}

// Delete a node from BST
struct node *deleteNode(struct node *root, int value)
{
  if (root == NULL)
    return root;

  if (value < root->data)
  {
    root->left = deleteNode(root->left, value);
  }
  else if (value > root->data)
  {
    root->right = deleteNode(root->right, value);
  }
  else
  {
    // Node found
    if (root->left == NULL)
    {
      struct node *temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL)
    {
      struct node *temp = root->left;
      free(root);
      return temp;
    }

    // Node with two children
    struct node *temp = findMin(root->right);
    root->data = temp->data;
    root->right = deleteNode(root->right, temp->data);
  }

  return root;
}

// Display tree elements in-order
void display(struct node *root)
{
  if (root == NULL)
    return;
  display(root->left);
  printf("%d ", root->data);
  display(root->right);
}