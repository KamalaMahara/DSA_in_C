#include <stdio.h>
// function to perform binary search
int binarySearch(int arr[], int first_index, int last_index, int key)
{
  if (first_index == last_index)
  {
    if (key == arr[first_index])
    {
      return first_index;
    }
    else
    {
      return "error";
    }
  }
  else
  {
    int mid = first_index + last_index / 2;
    if (key == arr[mid])
    {
      return mid;
    }
    else if (key < arr[mid])
    {
      return binarySearch(arr, first_index, mid - 1, key);
    }
    else
    {
      return binarySearch(arr, mid + 1, last_index, key);
    }
  }
}
int main()
{
  int arr[100], n, key, i;
  printf("enter the number of elements in the array:");
  scanf("%d", &n);
  printf("enter the elements of the array in sorted order:\n");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
  printf("enter th element to be searched:");
  scanf("%d", &key);
  int result = binarySearch(arr, 0, n - 1, key);
  if (result == "error")
  {
    printf("element not found\n");
  }
  else
  {
    printf("elements found at index %d \n", result);
  }
  return 0;
}
