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

void insertAtEnd()
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
void deleteAtBeginning()
{
  Node *temp = head;
  if (head == NULL)
  {
    printf("List is empty\n");
    return;
  }
  head = head->next;
  head->prev = NULL;
  free(temp);
}
void deleteAtEnd()
{
  Node *temp = head;
  if (head == NULL)
  {
    printf("List is empty\n");
    return;
  }
  else
  {
    temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    free(temp);
  }
}
void deleteAtPosition()
{
  int pos, i = 1;
  Node *temp = head;

  if (head == NULL)
  {
    printf("List is empty\n");
    return;
  }

  printf("Enter position: ");
  scanf("%d", &pos);

  if (pos < 1)
  {
    printf("Invalid position\n");
    return;
  }

  if (pos == 1)
  {
    if (head == tail)
    {
      free(head);
      head = tail = NULL;
    }
    else
    {
      head = head->next;
      head->prev = NULL;
      free(temp);
    }
    return;
  }

  // move to desired position
  while (i < pos && temp != NULL)
  {
    temp = temp->next;
    i++;
  }

  if (temp == NULL)
  {
    printf("Position out of bounds\n");
    return;
  }

  // delete last node
  if (temp == tail)
  {
    tail = tail->prev;
    tail->next = NULL;
    free(temp);
  }
  else
  {
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
  }
}

void reverse()
{
  Node *current = head;
  Node *temp = NULL;

  if (head == NULL)
  {
    printf("List is empty\n");
    return;
  }

  while (current != NULL)
  {
    // Swap prev and next
    temp = current->prev;
    current->prev = current->next;
    current->next = temp;

    // Move forward (actually backward now)
    current = current->prev;
  }

  // Update head
  if (temp != NULL)
    head = temp->prev;
}

int main()
{
  int choice;

  create(); // create list once

  while (1)
  {
    printf("\n\n---- DOUBLY LINKED LIST MENU ----\n");
    printf("1. Display\n");
    printf("2. Insert at Beginning\n");
    printf("3. Insert at End\n");
    printf("4. Insert at Position\n");
    printf("5. Insert After Position\n");
    printf("6. Delete at Beginning\n");
    printf("7. Delete at End\n");
    printf("8. Delete at Position\n");
    printf("9. Reverse the List\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      display();
      break;

    case 2:
      insertAtBeginning();
      break;

    case 3:
      insertAtEnd();
      break;

    case 4:
      insertAtPosition();
      break;

    case 5:
      insertAfterPosition();
      break;

    case 6:
      deleteAtBeginning();
      break;

    case 7:
      deleteAtEnd();
      break;
    case 8:
      deleteAtPosition();
      break;

    case 0:
      printf("Exiting...\n");
      exit(0);
    case 9:
      reverse();
      break;

    default:
      printf("Invalid choice\n");
    }
  }

  return 0;
}

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
