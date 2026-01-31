#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

void insertAtBeginning(struct Node **head_ref, int new_data)
{
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

void inserAtEnd(struct Node **head_ref, int new_data)
{
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  struct Node *temp = *head_ref;
  new_node->data = new_data;
  new_node->next = NULL;
  if (*head_ref == NULL)
  {
    *head_ref = new_node;
    return;
  }
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = new_node;
}

void inserAtAnyPosition(struct Node **head_ref, int pos, int new_data)
{
  if (pos < 0)
  {
    printf("Position cannot be negative\n");
    return;
  }
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  struct Node *temp = *head_ref;
  new_node->data = new_data;

  if (pos == 0)
  {
    new_node->next = *head_ref;
    *head_ref = new_node;
    return;
  }
  for (int i = 0; i < pos - 1 && temp != NULL; i++)
  {
    temp = temp->next;
  }
  if (temp == NULL)
  {
    printf("The previous node is null\n");
    free(new_node);
    return;
  }
  new_node->next = temp->next;
  temp->next = new_node;
}

void deleteAtBeginning(struct Node **head_ref)
{
  if (*head_ref == NULL)
  {
    printf("List is empty\n");
    return;
  }
  struct Node *temp = *head_ref;
  *head_ref = (*head_ref)->next;
  temp->next = NULL;
  free(temp);
}

void deleteAtEnd(struct Node **head_ref)
{
  if (*head_ref == NULL)
  {
    printf("List is empty\n");
    return;
  }
  if((*head_ref)->next == NULL) {
    free(*head_ref);
    *head_ref = NULL;
    return;
  }
  struct Node *temp = *head_ref;
  while(temp->next->next != NULL) {
    temp = temp->next;
  }
  free(temp->next);
  temp->next = NULL;
  
}

void deleteAtPosition(struct Node **head_ref, int pos)
{
  if (*head_ref == NULL)
  {
    printf("List is empty\n");
    return;
  }
  struct Node *temp = *head_ref;
  if (pos < 0)
  {
    printf("Position cannot be negative\n");
    return;
  }

  if (pos == 0)
  {
    *head_ref = (*head_ref)->next;
    temp->next = NULL;
    free(temp);
    return;
  }
  for (int i = 0; i < pos - 1 && temp != NULL; i++)
  {
    temp = temp->next;
  }
  if (temp == NULL || temp->next == NULL)
  {
    printf("Position is invalid\n");
    return;
  }
  struct Node *toDelete = temp->next;
  temp->next = toDelete->next;
  toDelete->next = NULL;
  free(toDelete);
}

int main()
{
  int choice;
  struct Node *first, *second, *third, *temp;
  first = (struct Node *)malloc(sizeof(struct Node));
  second = (struct Node *)malloc(sizeof(struct Node));
  third = (struct Node *)malloc(sizeof(struct Node));

  first->data = 10;
  first->next = second;

  second->data = 20;
  second->next = third;

  third->data = 30;
  third->next = NULL;

  while (1)
  {
    printf("1. Insert at beginning\n");
    printf("2. Insert at end\n");
    printf("3. Insert at position\n");
    printf("4. Delete at beginning\n");
    printf("5. Delete at end\n");
    printf("6. Delete at position\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
      int data;
      printf("ENter the data to be inserted: ");
      scanf("%d", &data);
      insertAtBeginning(&first, data);
      break;
    }
    case 2:
    {
      int data;
      printf("Enter the data to be inserted: ");
      scanf("%d", &data);
      inserAtEnd(&first, data);
      break;
    }
    case 3:
    {
      int data, pos;
      printf("Enter the position to insert the node: ");
      scanf("%d", &pos);
      printf("Enter the data to be inserted: ");
      scanf("%d", &data);
      inserAtAnyPosition(&first, pos, data);
      break;
    }
    case 4:
    {
      deleteAtBeginning(&first);
      break;
    }

    case 5:
    {
      deleteAtEnd(&first);
      break;
    }
    case 6:
    {
      int pos;
      printf("Enter the position to delete the node: ");
      scanf("%d", &pos);
      deleteAtPosition(&first, pos);
      break;
    }
    case 7:
    {
      exit(0);
    }
    }

    temp = first;
    while (temp != NULL)
    {
      printf("%d -> ", temp->data);
      temp = temp->next;
    }
    printf("NULL\n");
  }
  return 0;
}
