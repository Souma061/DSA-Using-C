/*Write a menu driven program in C to perform the following operations in a Stack using linked list with
the node structure {Roll, Name, Next}.
(a) Push
(b) Pop
(c) Display
(d) Reverse.*/



#include<stdio.h>
#include<stdlib.h>


typedef struct Node {
  int data;
  struct Node *next;
} node;

node *top = NULL;

int isEmpty() {
  if(top == NULL) {
    return 1;
  } else {
    return 0;
  }
}


void push(int data) {
  node *newNode = (node *)malloc(sizeof(node));
  newNode->data = data;
  newNode->next = top;
  top = newNode;

}

void pop() {
  if(isEmpty()) {
    printf("Stack underflow. Cannot pop from an empty stack.\n");
    return;
  }
  node *temp = top;
  top = top->next;
  free(temp);
}

void reverse() {
  node *prev = NULL;
  node *current = top;
  node *next = NULL;

  while(current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  top = prev;
}


void display() {
  if(isEmpty()) {
    printf("Stack is empty. No elements to display.\n");
    return;
  }
  node *current = top;
  printf("Stack elements: ");
  while(current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

int main() {
  int choice, data;
  while(1) {
    printf("Menu:\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display\n");
    printf("4. Reverse\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("Enter data to push: ");
        scanf("%d", &data);
        push(data);
        break;
      case 2:
        pop();
        break;
      case 3:
        display();
        break;
      case 4:
        reverse();
        break;
      case 5:
        exit(0);
      default:
        printf("Invalid choice. Please try again.\n");
    }
  }
}
