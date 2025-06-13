#include <stdio.h>
// function to perform insertion sort
void insertionSort(int arr[], int n)
{
  int i, j, key;
  for (i = 1; i < n; i++)
  {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
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
  insertionSort(arr, n);
  printf("sorted array is :\n");
  for (i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}