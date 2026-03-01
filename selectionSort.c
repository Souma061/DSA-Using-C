#include <stdio.h>

void selectionSort(int arr[], int n)
{
  int mainIndex, temp;
  for (int i = 0; i < n - 1; i++)
  {
    mainIndex = i;
    for (int j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[mainIndex])
      {
        mainIndex = j;
      }
    }
    temp = arr[i];
    arr[i] = arr[mainIndex];
    arr[mainIndex] = temp;
  }
  printf("Sorted array: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main()
{
  int arr[100], n;
  printf("Enter number of elements: ");
  scanf("%d", &n);
  printf("Enter elements: ");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
  selectionSort(arr, n);
  return 0;
}
