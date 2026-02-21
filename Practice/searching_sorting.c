#include <stdio.h>

// Binary Search
void binarySearch(int a[], int n, int key)
{
  int low = 0, high = n - 1, mid;

  while (low <= high)
  {
    mid = (low + high) / 2;
    if (a[mid] == key)
    {
      printf("Element found at index: %d\n", mid);
      return;
    }
    else if (a[mid] < key)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  printf("Element not found\n");
}
// Linear Search
void LinearSearch(int a[], int n, int key)
{
  for (int i = 0; i < n; i++)
  {
    if (a[i] == key)
    {
      printf("Element found at index: %d\n", i);
      return;
    }
  }
}
// bubble sort
void bubbleSort(int a[], int n)
{
  int temp;

  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (a[j] > a[j + 1])
      {
        temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    }
  }
  printf("\nSorted Array is: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }
  printf("\n");
}

// Selection sort
void selectionSort(int a[], int n)
{
  int mainIndex, temp;
  for (int i = 0; i < n - 1; i++)
  {
    mainIndex = i;
    for (int j = i + 1; j < n; j++)
    {
      if (a[j] < a[mainIndex])
      {
        mainIndex = j;
      }
    }
    temp = a[i];
    a[i] = a[mainIndex];
    a[mainIndex] = temp;
  }
  printf("\nSorted Array is: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }
  printf("\n");
}
// Insertion Sort
void insertionSort(int a[], int n)
{
  int key;
  int i, j;
  for (i = 1; i < n; i++)
  {
    key = a[i];
    j = i - 1;
    while (j >= 0 && a[j] > key)
    {
      a[j + 1] = a[j];
      j = j - 1;
    }
    a[j + 1] = key;
  }
  printf("\nSorted Array is: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }
  printf("\n");
}
// Merge Sort
void merge(int a[], int l,int m,int r) {

}
void mergeSort(int a[], int l, int r) {
  if(l < r) {
    int m = l + (r - l) / 2;
    mergeSort(a, l , m); // left half
    mergeSort(a, m + 1, r); // right half
    merge(a, l, m, r); // merging the two halves
  }
}
// Quick Sort
