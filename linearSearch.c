#include <stdio.h>
// function to perform linear search
int linearSearch(int arr[], int n, int key)
{
  for (int i = 0; i < n; i++)
  {
    if (key == arr[i])
    {
      return i; // if key is found return the index
    }
  }
  return -1; // if key isnt found
}
int main()
{
  int arr[100], n, key, index;
  printf("enter the number of elements in the array:");
  scanf("%d", &n);
  printf("enter the elements of the array:\n");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
  printf("enter the key to be searched:");
  scanf("%d", &key);
  index = linearSearch(arr, n, key);
  if (index != -1)
  {
    printf("key found at index %d", index);
  }
  else
  {
    printf("key not found in the array");
  }
  return 0;
}
