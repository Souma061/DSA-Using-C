/*2. Implement a stack using a linked list with the following operations Push, Pop, Peek, isEmpty and Display.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *next;
} node;

node *top = NULL;

int isEmpty()
{
  if (top == NULL)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void push(int data)
{
  node *newNode = (node *)malloc(sizeof(node));
  newNode->data = data;
  newNode->next = top;
  top = newNode;
}

void pop()
{
  if (isEmpty())
  {
    printf("Stack underflow. Cannot pop from an empty stack.\n");
    return;
  }
  node *temp = top;
  top = top->next;
  free(temp);
}

void peek()
{
  if (isEmpty())
  {
    printf("Stack is empty. No top element.\n");
    return;
  }
  printf("Top element: %d\n", top->data);
}


void display() {
  if(isEmpty()) {
    printf("Stack is empty. No elements to display.\n");
    return;
  }
  node *current = top;
printf("Stack elements: ");
while (current != NULL)
{
  printf("%d ", current->data);
  current = current->next;

}
printf("\n");

}


int main()
{

  int choice, data;
  while (1)
  {
    printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter data to push: ");
      scanf("%d", &data);
      push(data);
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
      exit(0);
    default:
      printf("Invalid choice. Please try again.\n");
    }
  }

  return 0;
}
