/*Now, you can try to write a generalized insertion and deletion algorithm/program. Which will just ask the position and insert/delete into/from that position. This position will be any number between 1 to N+1. N being the length of the existing LL.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *next;
} Node;

Node *head = NULL;

int length()
{
  int cnt = 0;
  Node *temp = head;
  while (temp != NULL)
  {
    cnt++;
    temp = temp->next;
  }
  return cnt;
}

void insert(int item, int pos)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = item;
  newNode->next = NULL;

  if (pos < 1)
  {
    printf("Invalid position\n");
    free(newNode);
    return;
  }
  if (pos == 1)
  {
    newNode->next = head;
    head = newNode;
    printf("Inserted %d at position %d\n", item, pos);
    return;
  }
  int len = length();
  if (pos > len + 1)
  {
    printf("Invalid position\n");
    free(newNode);
    return;
  }

  Node *temp = head;
  for (int i = 1; i < pos - 1 && temp != NULL; i++)
  {
    temp = temp->next;
  }
  if (temp == NULL)
  {
    printf("Position is not valid\n");
    free(newNode);
    return;
  }
  newNode->next = temp->next;
  temp->next = newNode;
  printf("Inserted %d at position %d\n", item, pos);
}

void delete(int pos)
{
  if (head == NULL)
  {
    printf("List is empty\n");
    return;
  }

  int len = length();

  if (pos < 1 || pos > len)
  {
    printf("Invalid position\n");
    return;
  }

  Node *temp = head;

  // Case 1: delete first node
  if (pos == 1)
  {
    head = temp->next;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
    return;
  }

  // Move to (pos - 1)
  for (int i = 1; i < pos - 1; i++)
  {
    temp = temp->next;
  }

  Node *toDelete = temp->next;
  temp->next = toDelete->next;

  printf("Deleted element: %d\n", toDelete->data);
  free(toDelete);
}

void reverse()
{
  Node *prev = NULL;
  Node *current = head;
  Node *next = NULL;

  while (current != NULL)
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  head = prev;
  printf("List reversed\n");
}

void search(int item)
{
  Node *temp = head;
  int pos = 1;
  while (temp != NULL)
  {
    if (temp->data == item)
    {
      printf("Element %d found at position %d\n", item, pos);
      return;
    }
    temp = temp->next;
    pos++;
  }
  printf("Element %d not found in the list\n", item);
}

void display()
{
  if (head == NULL)
  {
    printf("List is empty\n");
  }
  else
  {
    Node *temp = head;
    printf("List elements: ");
    while (temp != NULL)
    {
      printf("%d ", temp->data);
      temp = temp->next;
    }
    printf("\n");
  }
}
int main()
{
  int choice, item, pos;
  while (1)
  {
    printf("Enter 1 to insert, 2 to delete, 3 to display, 4 to reverse, 5 to search,6 to exit: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("Enter the item to insert: ");
      scanf("%d", &item);
      printf("Enter the position to insert: ");
      scanf("%d", &pos);
      insert(item, pos);
      break;
    case 5:
      printf("Enter the item to search: ");
      scanf("%d", &item);
      search(item);
      break;
    case 2:
      printf("Enter the position to delete: ");
      scanf("%d", &pos);
      delete(pos);
      break;
    case 3:
      display();
      break;
    case 4:
      reverse();
      break;
    case 6:
      printf("Exiting...\n");
      exit(0);
    default:
      printf("Invalid choice\n");
    }
  }
}
