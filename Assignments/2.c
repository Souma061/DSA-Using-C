// Write a program to sort a list of elements.Give user the option to perform sorting using Insertion
//     sort,
//     Bubble sort or Selection sort.

#include <stdio.h>

void bubble_sort(int a[], int n)
{
  int i, j, temp;
  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n - i - 1; j++)
    {
      if (a[j] > a[j + 1])
      {
        temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    }
  }
  printf("Sorted array is: ");
  for (i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }
  printf("\n");
}

void selection_sort(int a[], int n)
{
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
  printf("Sorted array is: ");
  for (i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }
  printf("\n");
}

void insertion_sort(int a[], int n)
{
  int i, j, temp;
  for (i = 1; i < n; i++)
  {
    temp = a[i];
    j = i - 1;
    while (j >= 0 && a[j] > temp)
    {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = temp;
  }
  printf("Sorted array is: ");
  for (i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }
  printf("\n");
}

int main()
{
  int a[50], n, choice;

  printf("Enter the number of the Array Elements: ");
  scanf("%d", &n);
  printf("Enter the Array Elements:\n");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  while (1)
  {
    printf("Choose Sorting Method:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      bubble_sort(a, n);
      break;
    case 2:
      selection_sort(a, n);
      break;
    case 3:
      insertion_sort(a, n);
      break;
    case 4:
      return 0;
    default:
      printf("Invalid choice\n");
    }
  }
}
