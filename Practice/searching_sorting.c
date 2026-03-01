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
      printf("Element found at index: %d\n", mid + 1);
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
      printf("Element found at index: %d\n", i + 1);
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
void merge(int a[], int l, int m, int r)
{
  int i = l, j = m + 1, k = 0;
  int temp[r - l + 1];

  while (i <= m && j <= r)
  {
    if (a[i] < a[j])
      temp[k++] = a[i++];
    else
      temp[k++] = a[j++];
  }

  while (i <= m)
    temp[k++] = a[i++];

  while (j <= r)
    temp[k++] = a[j++];

  // copy back
  for (int p = 0; p < k; p++)
    a[l + p] = temp[p];
}

void mergeSort(int a[], int l, int r)
{
  if (l < r)
  {
    int m = l + (r - l) / 2;
    mergeSort(a, l, m);     // left half
    mergeSort(a, m + 1, r); // right half
    merge(a, l, m, r);      // merging the two halves
  }
}
// Quick Sort

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int a[], int l, int r)
{
  int pivot = a[r];
  int i = l - 1;

  for (int j = l; j < r; j++)
  {
    if (a[j] < pivot)
    {
      i++;
      swap(&a[i], &a[j]);
    }
  }
  swap(&a[i + 1], &a[r]);
  return i + 1;
}

void quickSort(int a[], int l, int r)
{
  if (l < r)
  {
    int pivot = partition(a, l, r);
    quickSort(a, l, pivot - 1);
    quickSort(a, pivot + 1, r);
  }
}

int main()
{
  int a[100], n, key, choice;

  while (1)
  {
    printf("\n===== MENU =====\n");
    printf("1. Enter Array\n");
    printf("2. Binary Search\n");
    printf("3. Linear Search\n");
    printf("4. Bubble Sort\n");
    printf("5. Selection Sort\n");
    printf("6. Insertion Sort\n");
    printf("7. Merge Sort\n");
    printf("8. Quick Sort\n");
    printf("9. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter number of elements: ");
      scanf("%d", &n);
      printf("Enter elements: ");
      for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
      break;

    case 2:
      printf("Enter key: ");
      scanf("%d", &key);
      binarySearch(a, n, key);
      break;

    case 3:
      printf("Enter key: ");
      scanf("%d", &key);
      LinearSearch(a, n, key);
      break;

    case 4:
      bubbleSort(a, n);
      break;

    case 5:
      selectionSort(a, n);
      break;

    case 6:
      insertionSort(a, n);
      break;

    case 7:
      mergeSort(a, 0, n - 1);
      printf("Sorted Array: ");
      for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
      printf("\n");
      break;

    case 8:
      quickSort(a, 0, n - 1);
      printf("Sorted Array: ");
      for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
      printf("\n");
      break;

    case 9:
      printf("Exiting...\n");
      return 0;

    default:
      printf("Invalid choice!\n");
    }
  }
}
