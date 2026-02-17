#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *next;
} Node;

Node *head;

void create()
{
  head = NULL;
  Node *temp;
  int choice = 1;
  while (choice)
  {
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Enter Data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    if (head == NULL)
    {
      head = newNode;
      temp = head;
    }
    else
    {
      temp->next = newNode;
      temp = newNode;
    }
    printf("Do you want to continue (0/1): ");
    scanf("%d", &choice);
  }
}

void bubbleSort(Node *head)
{
  if (head == NULL)
  {
    return;
  }

  Node *ptr1, *ptr2 = NULL;
  int swapped;

  do
  {
    swapped = 0;
    ptr1 = head;

    while (ptr1->next != NULL)
    {
      ptr2 = ptr1->next;

      if (ptr1->data > ptr1->next->data)
      {
        int temp = ptr1->data;
        ptr1->data = ptr2->data;
        ptr2->data = temp;
        swapped = 1;
      }

      ptr1 = ptr1->next;
    }
    ptr2 = ptr1;
  } while (swapped);
}

void display()
{
  Node *temp = head;
  while (temp != NULL)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main()
{
  create();
  printf("Original list: ");
  display();
  bubbleSort(head);
  printf("Sorted list: ");
  display();
  return 0;
}



