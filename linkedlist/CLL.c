#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
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
    // Node *newNode = (Node *)malloc(sizeof(Node));
    // printf("Enter data: ");
    // scanf("%d", &newNode->data);
    // newNode->next = NULL;
    // if (head == NULL)
    // {
    //   head = temp = newNode;
    //   temp->next = head;
    // }
    // else
    // {
    //   temp->next = newNode;
    //   temp = newNode;
    //   temp->next = head;
    // }
    // printf("Do you want to continue (0/1): ");
    // scanf("%d", &choice);
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
      printf("Memory allocation failed\n");
      exit(1);
    }
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    if (head == NULL)
    {
      head = tail = newNode;
    }
    else
    {
      tail->next = newNode;
      tail = newNode;
    }
    tail->next = head;
    printf("Do you want to continue (0/1): ");
    scanf("%d", &choice);
  }
}

void insertAtBeginning()
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL)
  {
    printf("Memory allocation failed\n");
    exit(1);
  }
  printf("Enter data: ");
  scanf("%d", &newNode->data);
  newNode->next = NULL;

  if (head == NULL)
  {
    head = tail = newNode;
    tail->next = head;
    return;
  }
  newNode->next = head;
  head = newNode;
  tail->next = head;
}

void deleteAtBeginning()
{
  if (head == NULL)
  {
    printf("List in Empty\n");
    return;
  }
  if (head == tail)
  {
    free(head);
    head = tail = NULL;
    return;
  }
  Node *temp = head;
  head = head->next;
  tail->next = head;
  free(temp);
}

void insertAtEnd()
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL)
  {
    printf("Memory allocation failed\n");
    exit(1);
  }
  printf("Enter data: ");
  scanf("%d", &newNode->data);
  newNode->next = NULL;

  if (head == NULL)
  {
    head = tail = newNode;
    tail->next = head;
    return;
  }
  newNode->next = head;
  tail->next = newNode;
  tail = newNode;
}

void deleteAtEnd()
{
  if (head == NULL)
  {
    printf("List is Empty\n");
    return;
  }

  if (head == tail)
  {
    free(head);
    head = tail = NULL;
    return;
  }

  Node *temp = head;

  while (temp->next != tail)
  {
    temp = temp->next;
  }

  temp->next = head;
  free(tail);
  tail = temp;
}

void insertAtPosition()
{
  int pos;
  printf("Enter position to insert: ");
  scanf("%d", &pos);
  if (pos <= 0)
  {
    printf("Invalid position\n");
    return;
  }

  if (pos == 1)
  {
    insertAtBeginning();
    return;
  }
  if (head == NULL)
  {
    printf("List is empty. Insert at position 1 only.\n");
    return;
  }

  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL)
  {
    printf("Memory allocation failed\n");
    exit(1);
  }
  printf("Enter data: ");
  scanf("%d", &newNode->data);
  newNode->next = NULL;

  Node *temp = head;
  for (int i = 1; i < pos - 1; i++)
  {
    if (temp->next == head)
    {
      printf("Position out of bounds\n");
      free(newNode);
      return;
    }
    temp = temp->next;
  }
  newNode->next = temp->next;
  temp->next = newNode;
  if (temp == tail)

  {
    tail = newNode;
  }
}

void deleteAtPosition()
{
  int pos;
  printf("Enter position to delete: ");
  scanf("%d", &pos);
  if (pos <= 0)
  {
    printf("Invalid position\n");
    return;
  }

  if (pos == 1)
  {
    deleteAtBeginning();
    return;
  }
  if (head == NULL)
  {
    printf("List is empty. Delete at position 1 only.\n");
    return;
  }
  Node *temp = head;
  for (int i = 1; i < pos - 1; i++)
  {
    if (temp->next == head)
    {
      printf("Position out of bounds\n");
      return;
    }
    temp = temp->next;
  }
  Node *toDelete = temp->next;
  if (toDelete == head)
  {
    printf("Position out of bounds\n");
    return;
  }
  temp->next = toDelete->next;
  if (toDelete == tail)
  {
    tail = temp;
  }
  free(toDelete);
}

void reverse() {
  if( head == NULL || head->next == head) {
    return;
  }
  Node *prev = tail;
  Node *current = head;
  Node *next;

  do{
    next = current->next;
    current->next = prev;

    prev = current;
    current = next;

  } while(current != head);
  tail = head;
  head = prev;
}
void display()
{
  Node *temp = head;
  if (head == NULL)
  {
    printf("List is empty\n");
    return;
  }

  do
  {
    printf("%d -> ", temp->data);
    temp = temp->next;
  } while (temp != head);
  printf("(head: %d)\n", head->data);
}

int main()
{

  int choice;

  create(); // create list once

  while (1)
  {
    printf("\n\n---- CIRCULAR LINKED LIST MENU ----\n");
    printf("1. Display\n");
    printf("2. Insert at Beginning\n");
    printf("3. Insert at End\n");
    printf("4. Insert at Position\n");
    printf("5. Delete at Beginning\n");
    printf("6. Delete at End\n");
    printf("7. Delete at Position\n");
    printf("8. Reverse the List\n");
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
      deleteAtBeginning();
      break;
    case 6:
      deleteAtEnd();
      break;
    case 8:
      reverse();
      break;
    case 0:
      printf("Exiting...\n");
      exit(0);

    default:
      printf("Invalid choice\n");
    }
  }
  return 0;
}
