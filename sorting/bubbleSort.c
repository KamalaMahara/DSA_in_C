#include <stdio.h>
// function to perform bubble sort
void bubblesort(int arr[], int n)
{
  int i, j, temp;
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}
int main()
{
  int arr[100], n, i;
  printf("enter the number of elements in the array:");
  scanf("%d", &n);
  printf("enter the elements of the array:\n");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
  bubblesort(arr, n);
  printf("the sorted array is:\n");
  for (i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
}