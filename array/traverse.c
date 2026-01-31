#include <stdio.h>

int main()
{
  int n;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  int arr[n];
  int choice, pos, num;
  printf("Enter the elements:\n");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
  printf("Array elements are:\n");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
  printf("Choose insertion method:\n1. At the beginning\n2. At the end\n3. At any position\n");
  scanf("%d", &choice);
  switch (choice) {
    case 1:
      
  }
  // Enter an element in any position
//   int pos, num;
//   printf("Enter the number: ");
//   scanf("%d", &num);
//   printf("Enter the position: ");
//   scanf("%d", &pos);
//   if (pos <= 0 || pos > n + 1)
//   {
//     printf("Out of bounds\n");
//   }
//   else
//   {
//     for (int i = n - 1; i >= pos - 1; i--)
//     {
//       arr[i + 1] = arr[i];
//     }
//     arr[pos - 1] = num;
//     n++;
//     printf("Array after insertion:\n");
//     for (int i = 0; i < n; i++)
//     {
//       printf("%d ", arr[i]);
//     }
//     printf("\n");
//   }
//   return 0;
// }
