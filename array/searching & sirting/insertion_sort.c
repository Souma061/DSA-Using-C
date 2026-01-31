#include <stdio.h>

int main()
{
  int a[] = {5, 4, 10, 1, 6, 2};
  int n = sizeof(a) / sizeof(a[0]);

  int temp;
  for (int i = 1; i < n; i++)
  {
    temp = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > temp)
    {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = temp;
  }
  printf("Sorted array: \n");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }
  return 0;
}
