#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *prev;
  struct Node *next;
} Node;

Node *head;
Node *tail;
// void create()
// {
//   head = NULL;
//   Node *temp;
//   int choice = 1;
//   while (choice)
//   {
//     Node *newNode = (Node *)malloc(sizeof(Node));
//     printf("Enter Data: ");
//     scanf("%d", &newNode->data);
//     newNode->prev = NULL;
//     newNode->next = NULL;
//     if (head == NULL)
//     {
//       head = newNode;
//       temp = head;
//     }
//     else
//     {
//       temp->next = newNode;
//       newNode->prev = temp;
//       temp = newNode;
//     }
//     printf("Do you want to continue (0/1): ");
//     scanf("%d", &choice);
//   }
// }

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
    newNode->prev = NULL;
    newNode->next = NULL;
    if (head == NULL)
    {
      head = tail = newNode;
    }
    else
    {
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
    }
    printf("Do you want to continue (0/1): ");
    scanf("%d", &choice);
  }
}
void display()
{
  Node *temp = head;
  while (temp != NULL)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
}

void insertAtBeginning()
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  printf("Enter Data: ");
  scanf("%d", &newNode->data);
  newNode->prev = NULL;
  newNode->next = head;

  if (head != NULL)
  {
    head->prev = newNode;
  }
  else
  {
    tail = newNode;
  }
  head = newNode;
}

void inserAtEnd()
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  printf("Enter data: ");
  scanf("%d", &newNode->data);
  newNode->prev = NULL;
  newNode->next = NULL;

  if (tail == NULL)
  {
    head = tail = newNode;
  }
  else
  {
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
  }
}

void insertAtPosition()
{
  int pos, i = 1;
  printf("Enter position: ");
  scanf("%d", &pos);
  if (pos < 1)
  {
    printf("Invalid position\n");
    return;
  }
  else if (pos == 1)
  {
    insertAtBeginning();
    return;
  }
  else
  {
    Node *newNode = (Node *)malloc(sizeof(Node));
    Node *temp = head;
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->prev = NULL;
    newNode->next = NULL;
    while (i < pos - 1 && temp != NULL)
    {
      temp = temp->next;
      i++;
    }
    if (temp == NULL)
    {
      printf("Position out of bounds\n");
      free(newNode);
      return;
    }
    else if (temp->next == NULL)
    {
      temp->next = newNode;
      newNode->prev = temp;
      tail = newNode;
      return;
    }
    else
    {
      newNode->prev = temp;
      newNode->next = temp->next;
      temp->next = newNode;
      newNode->next->prev = newNode;
    }
  }
}

void insertAfterPosition()
{
  int pos, i = 1;
  printf("Enter position: ");
  scanf("%d", &pos);
  if (pos < 1)
  {
    printf("Invalid position\n");
    return;
  }

  else
  {
    Node *newNode = (Node *)malloc(sizeof(Node));
    Node *temp = head;
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->prev = NULL;
    newNode->next = NULL;
    while (i < pos && temp != NULL)
    {
      temp = temp->next;
      i++;
    }
    if (temp == NULL)
    {
      printf("Position out of bounds\n");
      free(newNode);
      return;
    }
    else if (temp->next == NULL)
    {
      temp->next = newNode;
      newNode->prev = temp;
      tail = newNode;
      return;
    }
    else
    {
      newNode->prev = temp;
      newNode->next = temp->next;
      temp->next = newNode;
      newNode->next->prev = newNode;
    }
  }
}
int main()
{
  create();
  printf("Doubly Linked List: ");
  display();
  insertAtBeginning();
  printf("\nAfter Insertion at Beginning: ");
  display();
  inserAtEnd();
  printf("\nAfter Insertion at End: ");
  display();
  insertAtPosition();
  printf("\nAfter Insertion at Position: ");
  display();
  insertAfterPosition();
  printf("\nAfter Insertion after Position: ");
  display();
  return 0;
}
