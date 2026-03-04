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

node *head = NULL;

void createNode(int data)
{
  node *newNode = (node *)malloc(sizeof(node));

  if (newNode == NULL)
  {
    printf("Memory allocation failed\n");
    return;
  }

  newNode->data = data;
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
}

void display()
{
  node *temp = head;
  while (temp != NULL)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
}

void deleteMax()
{
  if (head == NULL)
  {
    printf("List is empty.\n");
    return;
  }

  int max = head->data;
  node *temp = head;

  while (temp != NULL)
  {
    if (temp->data > max)
    {
      max = temp->data;
    }
    temp = temp->next;
  }
  temp = head;
  node *prev = NULL;

  while (temp != NULL && temp->data != max)
  {
    prev = temp;
    temp = temp->next;
  }
  if (prev == NULL)
  {
    head = head->next;
  }
  else
  {
    prev->next = temp->next;
  }
  free(temp);
}

void deleteMin()
{
  if (head == NULL)
  {
    printf("List is empty.\n");
    return;
  }
  node *temp = head;
  int min = head->data;

  while (temp != NULL)
  {
    if (temp->data < min)
    {
      min = temp->data;
    }
    temp = temp->next;
  }

  temp = head;
  node *prev = NULL;

  while (temp != NULL && temp->data != min)
  {
    prev = temp;
    temp = temp->next;
  }

  if (prev == NULL)
  {
    head = head->next;
  }
  else
  {
    prev->next = temp->next;
  }
  free(temp);
}

void reverse()
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
  head = prev;
}

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    printf("Please provide command line arguments to initialize the linked list.\n");
    return 1;
  }
  for (int i = 1; i < argc; i++)
  {
    int data = atoi(argv[i]);
    createNode(data);
  }
  printf("Linked list content: ");
  display();
  printf("\nDeleting maximum value node...\n");
  deleteMax();
  printf("Linked list content after deletion: ");
  display();
  printf("\nDeleting minimum value node...\n");
  deleteMin();
  printf("Linked list content after deletion: ");
  display();

  printf("\nReversing the linked list...\n");
  reverse();
  printf("Linked list content after reversal: ");
  display();
  return 0;
}
