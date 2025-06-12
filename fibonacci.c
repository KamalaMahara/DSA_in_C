#include <stdio.h>
#include <conio.h>
// recursive function to find the n fibonacci number
int fibonacci(n)
{

  if (n == 0)
    return 0; // base ccase
  else if (n == 1)
    return 1; // base case
  else
    return fibonacci(n - 1) + fibonacci(n - 2); // recursive case
}
int main()
{
  int n;
  printf("enter a number to find its fibonacci :");
  scanf("%d", &n);
  printf("fibonacci of %d is %d", n, fibonacci(n));
  return 0;
}