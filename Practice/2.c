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
    printf("Invalid Position\n");
    free(newNode);
    return;
  }
  if (pos == 1)
  {
    newNode->next = head;
    head = newNode;
    printf("Insertred %d at position %d\n", item, pos);
    return;
  }
  int len = length();
  if (pos > len + 1)
  {
    printf("Invalid Position\n");
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
    printf("Invalid Position\n");
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
  if (pos == 1)
  {
    head = temp->next;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
    return;
  }
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
  Node *curre = head;
  Node *next = NULL;

  while (curre != NULL)
  {
    next = curre->next;
    curre->next = prev;
    prev = curre;
    curre = next;
  }
  head = prev;
  printf("List reeversed");
}

void search(int item)
{
  Node *temp = head;
  int pos = 1;
  while (temp != NULL)
  {
    if (temp->data == item)
    {
      printf("Element %d is foud at position %d", item, pos);
      return;
    }
    temp = temp->next;
    pos++;
  }
  printf("Element not found!");
}

void display()
{
  if (head == NULL)
  {
    printf("List emptyy");
  }
  else
  {
    Node *temp = head;
    printf("List elements: ");
    while (temp != NULL)
    {
      printf("%d ", temp->data);
    }
    printf("\n");
  }
}

int main()
{
  int item, pos, choice;
  while (1)
  {
    printf("Enter 1 to insert, 2 to delete, 3 to display, 4 to reverse, 5 to search,6 to exit: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("Enter the item to insert: ");
      scanf("%d", &item);
      printf("Enter the position: ");
      scanf("%d", &pos);
      insert(item, pos);
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

    case 5:
      printf("Enter the item to search: ");
      scanf("%d", &item);
      search(item);
      break;

    case 6:
      printf("Exiting...\n");

      exit(0);
    default:
      printf("Invalid choice\n");
    }
  }
}
