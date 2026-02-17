/*Now, you can try to write a generalized insertion and deletion algorithm/program. Which will just ask the position and insert/delete into/from that position. This position will be any number between 1 to N+1. N being the length of the existing CLL.*/

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

  if (head == NULL)
    return 0;

  do
  {
    cnt++;
    temp = temp->next;
  } while (temp != head);

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
    if (head == NULL)
    {
      head = newNode;
      newNode->next = head;
    }
    else
    {
      Node *temp = head;
      while (temp->next != head)
      {
        temp = temp->next;
      }
      temp->next = newNode;
      newNode->next = head;
      head = newNode;
    }
  }
  else
  {
    int len = length();
    if (pos > len + 1)
    {
      printf("Invalid position\n");
      free(newNode);
      return;
    }
    Node *temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++)
    {
      temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
  }
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

  if (pos == 1)
  {
    if (head->next == head)
    {
      free(head);
      head = NULL;
    }
    else
    {
      Node *last = head;
      while (last->next != head)
        last = last->next;

      Node *toDelete = head;

      last->next = head->next;
      head = head->next;

      free(toDelete);
    }
  }
  else
  {
    Node *temp = head;
    for (int i = 1; i < pos - 1; i++)
      temp = temp->next;

    Node *toDelete = temp->next;
    temp->next = toDelete->next;

    free(toDelete);
  }

  printf("Deleted element at position %d\n", pos);
}

void reverse()
{
  if (head == NULL || head->next == head)
  {
    return;
  }
  Node *prev = NULL;
  Node *current = head;
  Node *next = NULL;
  Node *oldHead = head;

  do
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  } while (current != head);
  oldHead->next = prev;
  head = prev;
  printf("List reversed\n");
}

void search(int item)
{
  if (head == NULL)
  {
    printf("List is empty\n");
    return;
  }
  Node *temp = head;
  int pos = 1;
  do
  {
    if (temp->data == item)
    {
      printf("Element %d found at position %d\n", item, pos);
      return;
    }
    temp = temp->next;
    pos++;
  } while (temp != head);
  printf("Element %d not found in the list\n", item);
}

void display()
{
  if (head == NULL)
  {
    printf("List is empty\n");
    return;
  }
  Node *temp = head;
  printf("List: ");
  do
  {
    printf("%d ", temp->data);
    temp = temp->next;
  } while (temp != head);
  printf("\n");
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
      printf("Enter the item and position to insert: ");
      scanf("%d %d", &item, &pos);
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
