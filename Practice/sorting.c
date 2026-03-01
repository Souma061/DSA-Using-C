//insertion sort

#include<stdio.h>


void insertionort(int a[], int n) {
  int temp;
  for(int i = 1; i < n; i++) {
    temp = a[i];
    int j = i - 1;
    while(j >= 0 && a[j]> temp) {
      a[j + 1] = a[j];
      j--;
    }
    a[j+1] = temp;
  }
  printf("Sorted array: ");
  for(int i = 0;i < n;i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

int main() {
  int a[100], n;
  printf("Enter number of elements: ");
  scanf("%d", &n);
  printf("Enter elements: ");
  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  insertionort(a, n);
  return 0;
}
