/*Perform Queue operations using Array and linked list implementation. */

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int arrQueue[MAX], frontA = -1, rearA = -1;
void ArrayEnqueue(int item)
{
  if (rearA == MAX - 1)
  {
    printf("Queue overflow\n");
    return;
  }
  else
  {
    if (frontA == -1)
    {
      frontA = 0;
    }
    arrQueue[++rearA] = item;
    printf("Enqueued element: %d\n", item);
  }
}

void ArrayDequeue()
{
  if (frontA == -1 || frontA > rearA)
  {
    printf("Queue underflow\n");
    return;
  }
  else
  {
    printf("Dequeued element: %d\n", arrQueue[frontA++]);
  }
  if (frontA > rearA)
  {
    frontA = rearA = -1;
  }
}

void ArrayDisplay()
{
  if (frontA == -1 || frontA > rearA)
  {
    printf("Queue is empty\n");
    return;
  }
  else
  {
    printf("Queue elements: ");
    for (int i = frontA; i <= rearA; i++)
    {
      printf("%d ", arrQueue[i]);
    }
    printf("\n");
  }
}

typedef struct Node
{
  int data;
  struct Node *next;
} Node;

Node *frontL = NULL, *rearL = NULL;

void LLEnqueue(int item)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = item;
  newNode->next = NULL;

  if (rearL == NULL)
  {
    frontL = rearL = newNode;
  }
  else
  {
    rearL->next = newNode;
    rearL = newNode;
  }
  printf("Enqueued element: %d\n", item);
}

void LLDequeue()
{
  if (frontL == NULL)
  {
    printf("Queue underflow\n");
    return;
  }
  else
  {
    Node *temp = frontL;
    printf("Dequed element: %d\n", temp->data);
    frontL = frontL->next;
    free(temp);
    if (frontL == NULL)
    {
      rearL = NULL;
    }
  }
}

void LLDisplay() {
  if(frontL == NULL) {
    printf("Queue is empty\n");
    return;
  } else {
    Node *temp = frontL;
    printf("Queue elements: ");
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
    printf("Enter 1 for Array Enqueue, 2 for Array Dequeue, 3 for Array Display, 4 for LL Enqueue, 5 for LL Dequeue, 6 for LL Display, 7 to exit: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("Enter the item to enqueue: ");
      scanf("%d", &item);
      ArrayEnqueue(item);
      break;
    case 2:
      ArrayDequeue();
      break;
    case 3:
      ArrayDisplay();
      break;
    case 4:
      printf("Enter the item to enqueue: ");
      scanf("%d", &item);
      LLEnqueue(item);
      break;
    case 5:
      LLDequeue();
      break;
    case 6:
      LLDisplay();
      break;
    case 7:
      printf("Exiting...\n");
      exit(0);
    default:
      printf("Invalid choice\n");
    }
  }
}
