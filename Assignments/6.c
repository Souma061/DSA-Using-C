// Perform Stack operations using Linked List implementation.


#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;


Node *top = NULL;


void pop() {
  if(top == NULL) {
    printf("Strack underflow\n");
    return;
  } else {
    Node *temp = top;
    printf("Popped element: %d\n", temp->data);
    top = top->next;
    free(temp);
  }
}

void push(int item) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = item;
  newNode->next = top;
  top = newNode;
  printf("Pushed element: %d\n", item);


}

void peek() {
  if(top == NULL) {
    printf("Stack is empty\n");
  } else {
    printf("Top element: %d\n", top->data);
  }
}

void display() {
  if(top == NULL) {
    printf("Stack is empty\n");
  } else {
    Node *temp = top;
    printf("Stack elements: ");
    while(temp != NULL) {
      printf("%d ", temp->data);
      temp = temp->next;
    }
    printf("\n");
  }
}


int main() {
  int choice, item;
  while (1)
  {
    printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
    printf("Enter your choice: ");
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
      return 0;

    default:
      printf("Invalid choice\n");
    }
  }

  return 0;
}
