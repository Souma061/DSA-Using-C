/*Write a program in C to perform the following operations in a singly linked list with the node structure
{Data, Next}.
(a) Take Command line inputs to initialize the linked list.
(b) Display the content of the linked list using a function.
(c) Write a function to delete the maximum value node from the linked list.
(d) Write a function to reverse the linked list.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *next;
} node;

node *initializeLL(node *head, int value)
{
  node *newNode = (node *)malloc(sizeof(node));
  newNode->data = value;
  newNode->next = NULL;

  if (head == NULL)
  {
    head = newNode;
  }
  else
  {
    node *temp = head;
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = newNode;
  }
  return head;
}

void display(node *head)
{
  node *temp = head;
  printf("Linked List: ");
  while (temp != NULL)
  {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

node *deleteMax(node *head)
{
  if (head == NULL)
  {
    printf("Linked list is empty.\n");
    return head;
  }
  node *temp = head;
  node *maxNode = head;
  node *prev = NULL;
  node *preMax = NULL;

  while (temp != NULL)
  {
    if (temp->data > maxNode->data)
    {
      maxNode = temp;
      preMax = prev;
    }
    prev = temp;
    temp = temp->next;
  }
  if (preMax == NULL)
  {
    head = head->next;
  }
  else
  {
    preMax->next = maxNode->next;
  }
  free(maxNode);

  return head;
}

node *reverse(node *head)
{
  node *prev = NULL;
  node *current = head;
  node *next = NULL;

  while (current != NULL)
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  return prev;
}

int main(int argc, char *argv[])
{
  node *head = NULL;
  for (int i = 1; i < argc; i++)
  {
    int value = atoi(argv[i]);
    head = initializeLL(head, value);
  }
  display(head);

  head = deleteMax(head);
  printf("After deleting max value node:\n");
  display(head);

  head = reverse(head);
  printf("After reversing the linked list:\n");
  display(head);

  return 0;
}
