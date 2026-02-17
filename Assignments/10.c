/*Write a program to reverse the order of the elements in the stack using additional Queue. */

#include<stdio.h>
# define MAX 100

int stack[MAX], queue[MAX];
int top = -1, front = 0, rear = -1;


void push(int x) {
  stack[++top] = x;
}
int pop() {
  return stack[top--];

}
int isEmpty() {
  return top == -1;
}

void enqueue(int x) {
  if(front == -1) {
    front = 0;
  }
  queue[++rear] = x;
}

int dequeue() {
  int x = queue[front++];
  if(front > rear) {
    front = rear = -1;
  }
  return x;
}

int isQueueEmpty() {
  return front == -1;
}

int main() {
  int n, item;
  printf("Enter the number of elements to push onto the stack: ");
  scanf("%d", &n);
  printf("Enter %d elements:\n", n);

  for(int i = 0; i<n;i++) {
    scanf("%d", &item);
    push(item);
  }
  printf("Original stack elements: ");
  for(int i = top; i >= 0; i--) {
    printf("%d ", stack[i]);

  }
  printf("\n");
  while(!isEmpty()) {
    enqueue(pop());
  }
  while(!isQueueEmpty()) {
    push(dequeue());
  }
  printf("Reversed stack elements: ");
  for(int i = top; i>=0;i--) {
    printf("%d ", stack[i]);
  }
  printf("\n");
  return 0;
}
