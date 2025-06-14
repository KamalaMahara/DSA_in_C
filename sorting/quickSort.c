#include <stdio.h>
// functioin to perform quick sort
void quicksort(int arr[], int first, int last)
{
  int down, up, pivot, temp;
  if (first < last)
  {
    pivot = first;
    down = first + 1;
    up = last;
    while (down <= up)
    {
      while (arr[down] <= arr[pivot] && down <= last)
      {
        down++;
      }
      while (arr[up] > arr[pivot] && up >= first + 1)
      {
        up--;
      }
      if (down < up)
      {
        temp = arr[down];
        arr[down] = arr[up];
        arr[up] = temp;
      }
    }
    temp = arr[pivot];
    arr[pivot] = arr[up];
    arr[up] = temp;
    quicksort(arr, first, up - 1);
    quicksort(arr, up + 1, last);
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
  quicksort(arr, 0, n - 1);
  printf("the sorted array is:\n");
  for (i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  return 0;
}
