#include <stdio.h>

int main()
{
  int a[50], n;
  int item, l, u, mid;

  printf("Enter the number of array elements: ");
  scanf("%d", &n);
  printf("Enter the array elements in sorted order:\n");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  printf("Enter the item to search: ");
  scanf("%d", &item);
  l = 0;
  u = n - 1;
  while (l < u)
  {
    mid = (l + u) / 2;
    if (a[mid] == item)
    {

      printf("Item found at position %d\n", mid + 1);
      break;
    }
    else if (a[mid] < item)
    {
      l = mid + 1;
    }
    else
    {
      u = mid - 1;
    }
  }

  return 0;
}
