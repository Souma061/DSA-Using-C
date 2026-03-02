/*Write a menu driven program in C to perform the following operations in a queue using the concept of
circular array. Assume the contents are integer.
(a) Insert
(b) Delete
(c) Display.*/

// circular array is a data structure that uses a single, fixed-size array as if it were connected end-to-end. It is also known as a circular buffer or ring buffer. In a circular array, the last position is connected back to the first position, creating a circular structure. This allows for efficient use of memory and enables the implementation of queues and other data structures without the need for dynamic memory allocation. The circular array can be used to implement a queue by keeping track of the front and rear indices, allowing for efficient insertion and deletion operations.

#include <stdio.h>

#define SIZE 10
int queue[SIZE];
int front = -1;
int rear = -1;

int isFull()
{
  return (rear + 1) % SIZE == front;
}

int isEmpty()
{
  return front == -1;
}

void insert(int value)
{
  if (isFull())
  {
    printf("Queue is full. Cannot insert %d\n", value);
    return;
  }
  if (isEmpty())
  {
    front = rear = 0;
  }
  else
  {
    rear = (rear + 1) % SIZE;
  }
  queue[rear] = value;
  printf("Inserted %d into the queue.\n", value);
}

void delete()
{
  if (isEmpty())
  {
    printf("Queue is empty. Cannot delete.\n");
    return;
  }
  printf("Deleted %d from the queue.\n", queue[front]);
  if (front == rear)
  {
    front = rear = -1;
  }
  else
  {
    front = (front + 1) % SIZE;
  }
}

void display()
{
  if (isEmpty())
  {
    printf("Queue is empty. No elements to display.\n");
    return;
  }
  printf("Queue elements: ");
  int i = front;
  while (1)
  {
    printf("%d ", queue[i]);
    if (i == rear)
    {
      break;
    }
    i = (i + 1) % SIZE;
  }
}


int main()
{
  int choice, value;
  while (1)
  {
    printf("\nMenu:\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter the value to insert: ");
      scanf("%d", &value);
      insert(value);
      break;
    case 2:
      delete();
      break;
    case 3:
      display();
      break;
    case 4:
      printf("Exiting...\n");
      return 0;
    default:
      printf("Invalid choice. Please try again.\n");
    }
  }
}
