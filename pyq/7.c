/*Write a program in C to perform the following operations on an array of integers :
(a) Take Command line inputs to initialize the array.
(b) Display the content of the array using a function.
(c) Write a function to arrange the data in ascending order using Quick Sort Technique.*/


#include<stdio.h>


void display(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *a,int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[], int low,int high) {
  int pivot = arr[high];
  int i = low - 1;
  for(int j = low; j < high; j++) {
    if(arr[j] < pivot) {
      i++;
      swap(&arr[i],&arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return i + 1;
}

void quickSort(int arr[], int low, int high) {
  if(low < high) {
    int pivot = partition(arr, low, high);
    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);

  }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    display(arr, size);

    quickSort(arr, 0, size - 1);

    printf("Sorted array: ");
    display(arr, size);

    return 0;
}
