#include<stdio.h>

int main() {
  int a[] = {64, 34, 25, 12, 22, 11, 90};
  int n = sizeof(a)/ sizeof(a[0]);
  int i, j, temp;

  for( i = 0; i < n - 1; i ++) {
    for( j = 0; j < n - i - 1; j ++) {
      if( a[j] > a[j + 1]) {
        temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    }
  }
  printf("Sorted array: \n");
  for( i = 0; i < n; i ++) {
    printf("%d ", a[i]);
  }
  return 0;

}

/*
for (i = 0; i < n - 1; i++) {
  int swapped = 0;

  for (j = 0; j < n - i - 1; j++) {
    if (a[j] > a[j + 1]) {
      temp = a[j];
      a[j] = a[j + 1];
      a[j + 1] = temp;
      swapped = 1;
    }
  }

  if (swapped == 0)
    break;
}
*/
// Best case time complexity: O(n) when the array is already sorted
// Average and Worst case time complexity: O(n^2)
