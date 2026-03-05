#include<stdio.h>


void insertionSort(int arr[], int n) {
  int key, i, j;

  for (int i = 1; i < n;i++) {
    key = arr[i];
    j = i - 1;

    while(j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
  printf("Sorted array: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}
