#include <stdio.h>

int partition(int arr[], int l, int r);

void quickSort(int arr[], int l, int r)
{
  if (l < r)
  {
    int pivot = partition(arr, l, r);
    quickSort(arr, l, pivot - 1);
    quickSort(arr, pivot + 1, r);
  }
}

int partition(int arr[], int l, int r)
{

  int pivot = arr[l];
  int i = l;
  int j = r;

  while (i < j)
  {
    while (arr[i] <= pivot && i <= r - 1)
    {
      i++;
    }
    while (arr[j] > pivot && j >= l + 1)
    {
      j--;
    }
    if (i < j)
    {
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  int temp = arr[l];
  arr[l] = arr[j];
  arr[j] = temp;
  return j;
}

int main()
{
  int arr[] = {10, 7, 8, 9, 1, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  quickSort(arr, 0, n - 1);
  printf("Sorted array: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}
