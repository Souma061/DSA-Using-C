// #include <stdio.h>
// #define SIZE 5

// int queue[SIZE];
// int front = -1, rear = -1;

// int isEmpty() {
//   return ( front == -1 || front > rear);
// }

// int isFull() {
//   return (rear == SIZE -1);
// }

// void enqueue(int x) {
//   if(isFull()) {
//     printf("STOp\n");
//     return;
//   }
//   if(front = -1) {
//     front = 0;
//     queue[++rear] = x;
//   }

// }

// void dequeue() {
//   if(isEmpty()) {
//     printf("Underflow");
//     return;
//   }
//   printf("\nDeleted: %d\n", queue[front++]);
// }

// void peek() {
//     if(isEmpty()) {
//       printf("empty");
//     } else {
//       printf("Front element: %d", queue[front]);
//     }
// }

// int main()
// {
//   enqueue(10);
//   enqueue(20);
//   enqueue(30);
//   peek();
//   dequeue();
//   peek();
//   return 0;
// }


#include<stdio.h>

int main() {
  int m = 5;
  int n = 10;
  printf("%d\n", m*n);

  for(int  i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      printf("Hello\n");
    }
  }
  return 0;
}
