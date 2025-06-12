#include <stdio.h>
#include <conio.h>
// recursive function to find the factorial of a number
int factorial(int n)
{
  if (n == 0)
    return 1; // base caase
  else
    return n * factorial(n - 1); // recursive case (where the function factorial calls itself again and again until it reaches its base case)
}
int main()
{
  int n;
  printf("enter a number to find its factorial :");
  scanf("%d", &n);
  printf("factorial of %d is %d", n, factorial(n));
  return 0;
}