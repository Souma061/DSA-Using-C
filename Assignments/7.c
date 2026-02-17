/*. Perform Stack operations using Array implementation. */

#include<stdio.h>
#include<stdlib.h>

#define MAX 100
int stack[MAX];
int top = -1;
int isEmpty()
{
  return top == -1;
}

int isFull()
{
  return top == MAX - 1;
}
void push(int item) {
  if(isFull()) {
    printf("Stack overflow\n");
    return;
  } else {
    stack[++top] = item;
    printf("Pushed element: %d\n", item);
  }
}

void pop() {
  if(isEmpty()) {
    printf("Stack underflow\n");
    return;
  } else {
    printf("Popped element: %d\n", stack[top--]);
  }
}

void peek() {
  if(isEmpty()) {
    printf("Stack is empty\n");
  } else {
    printf("Top element: %d\n", stack[top]);
  }
}

void display() {
  if(isEmpty()  ) {
    printf("Stack is empty\n");
  } else {
    printf("Stack elements: ");
    for(int i = top; i >= 0; i--) {
      printf("%d ", stack[i]);
    }
    printf("\n");
  }
}

int main() {
  int choice, item;
  while (1){
    printf("Enter 1 to push, 2 to pop, 3 to peek, 4 to display, 5 to exit: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("Enter the item to push: ");
      scanf("%d", &item);
      push(item);
      break;
    case 2:
      pop();
      break;
    case 3:
      peek();
      break;
    case 4:
      display();
      break;
    case 5:
      printf("Exiting...\n");
      exit(0);
    default:
      printf("Invalid choice\n");
    }
  }
}
