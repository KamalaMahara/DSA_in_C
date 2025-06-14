#include <stdio.h>
// function to perform merge sort
void mergesort(int arr[], int first, int last)
{
  int mid;
  if (first < last)
  {
    mid = (first + last) / 2;
    mergesort(arr, first, mid);    // sort the first  half
    mergesort(arr, mid + 1, last); // sort the last half
    merge(arr, first, mid, last);  // merge the two halves
  }
}
// function to merge the two halves
void merge(int arr[], int first, int mid, int last)
{
  int i, j, k, temp[100];
  i = first;
  j = mid + 1;
  k = first;
  while (i <= mid && j <= last) // while both the halves have elements
  {
    if (arr[i] <= arr[j])
    {
      temp[k] = arr[i];
      i++;
    }
    else
    {
      temp[k] = arr[j];
      j++;
    }
    k++;
  }
  while (i <= mid)
  {
    temp[k] = arr[i];
    i++;
    k++;
  }
  while (j <= last)
  {
    temp[k] = arr[j];
    j++;
    k++;
  }
  for (i = first; i <= last; i++)
  {
    arr[i] = temp[i];
  }
}
int main()
{
  int arr[100], n, i;
  printf("enter the number of elements in the array:");
  scanf("%d", &n);
  printf("enter the elemets of the array:\n");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
  mergesort(arr, 0, n - 1);
  printf("the sorted array is :\n");
  for (i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  return 0;
}