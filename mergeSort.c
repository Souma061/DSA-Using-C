#include <stdio.h>

void merge(int arr[], int l, int m, int r)
{
  int i = l;
  int j = m + 1;
  int k = 0;
  int temp[r - l + 1];

  while (i <= m && j <= r)
  {
    if (arr[i] <= arr[j])
    {
      temp[k++] = arr[i++];
    }
    else
    {
      temp[k++] = arr[j++];
    }
  }
  while (i <= m)
  {
    temp[k++] = arr[i++];
  }
  while (j <= r)
  {
    temp[k++] = arr[j++];
  }
  for (i = l, k = 0; i <= r; i++, k++)
  {
    arr[i] = temp[k];
  }
}

void mergeSort(int arr[], int l, int r)
{
  if (l < r)
  {
    int mid = (l + r) / 2;

    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
  }
}

int main()
{
  int arr[] = {23, 12, 43, 5, 11, 56};
  int n = sizeof(arr) / sizeof(arr[0]);

  mergeSort(arr, 0, n - 1);
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}
