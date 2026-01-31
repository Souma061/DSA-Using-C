#include<stdio.h>

int main() {
  int a[50], n,i,j,flag = 0, item;

  printf("Enter the number of the array elements:");
  scanf("%d", &n);
  printf("Enter the array elements:\n");
  for(i = 0; i < n; i ++) {
    scanf("%d" , &a[i]);
  }
  printf("Enter the item to be searched:");
  scanf("%d", &item);

  for(i = 0; i < n; i ++) {
    if(a[i] == item) {
      flag = 1;
      printf("Item found at position %d\n", i + 1);
      break;
    }

  }
  if(flag == 0) {
    printf("Item not found\n");
  }
  return 0;
}
