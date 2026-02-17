#include<stdio.h>


void Binary_Search(int a[], int n, int item) {
  int l = 0, u = n - 1, mid;
  while(l <= u) {
    mid = (l + u) / 2;
    if(a[mid] == item) {
      printf("Item found at position %d\n", mid + 1);
      return;
    } else if(a[mid] < item) {
      l = mid + 1;
    } else {
      u = mid - 1;
    }
  }
  printf("Item not found\n");
}

void linear_search(int a[], int n, int item) {
  for(int i = 0; i < n; i++) {
    if(a[i] == item) {
      printf("Item found at position %d\n", i + 1);
      return;
    }
  }
  printf("Item not found\n");
}
int main() {
  int a[50], n, item, choice;

  printf("Enter the number of the array elements:");
  scanf("%d", &n);
  printf("Enter the array elements in sorted order:\n");
  for(int i = 0; i < n; i ++) {
    scanf("%d" , &a[i]);
  }
  printf("Enter the item to be searched:");
  scanf("%d", &item);

  printf("Enter 1 for Binary Search, 2 for Linear Search: ");
  scanf("%d", &choice);

  if(choice == 1) {
    Binary_Search(a, n, item);
  } else if(choice == 2) {
    linear_search(a, n, item);
  } else {
    printf("Invalid choice\n");
  }

  return 0;
}
