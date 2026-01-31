#include <stdio.h>

int main()
{
  int a[] = {4, 2, 5, 6, 1, 7, 3};
  int n = sizeof(a) / sizeof(a[0]);
  int i, j, min, pos, temp;

  for (i = 0; i < n - 1; i++)
  {
    min = a[i];
    pos = i;

    for (j = i + 1; j < n; j++)
    {
      if (a[j] < min)
      {
        min = a[j];
        pos = j;
      }
    }

    temp = a[i];
    a[i] = a[pos];
    a[pos] = temp;
  }

  printf("Sorted array:\n");
  for (i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }

  return 0;
}
