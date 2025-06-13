#include <stdio.h>

// Function to perform selection sort
void selectionSort(int arr[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    int min = i;
    for (int j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[min])
      {
        min = j;
      }
    }
    // Swap the found minimum element with the first element
    int temp = arr[i];
    arr[i] = arr[min];
    arr[min] = temp;
  }
}

int main()
{
  int arr[100], n;

  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);

  printf("Enter the elements in the array:\n");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  selectionSort(arr, n);

  printf("Sorted array:\n");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }

  return 0;
}