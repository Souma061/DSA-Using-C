/*
Write a menu driven program in C to perform the following functions on an array given as input by the
user :

(a) Print the 2nd largest number without sorting.
(b) Display the array in reverse order.
(c) Count the number of odd-elements present in even-valued array index.
*/

#include <stdio.h>
#include <limits.h>
void second_largest(int arr[], int n)
{
  if (n < 2)
  {
    printf("The second largest number cannot be found as the array has less than 2 elements.\n");
    return;
  }
  int largest = INT_MIN;
  int second_largest = INT_MIN;

  for (int i = 0; i < n; i++)
  {
    if (arr[i] > largest)
    {
      second_largest = largest;
      largest = arr[i];
    }
    else if (arr[i] > second_largest && arr[i] != largest)
    {
      second_largest = arr[i];
    }
  }
  if (second_largest == INT_MIN)
  {
    printf("There is no second largest number in the array.\n");
  }
  else
  {
    printf("The second largest number is: %d\n", second_largest);
  }
}


void reverse_array(int arr[],int n) {
  for(int i = n - 1; i >= 0; i--) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
