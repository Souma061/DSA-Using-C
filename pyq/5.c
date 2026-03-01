/*. Write a program to find the minimum element in a singly linked list. Implement a function that traverses
the list and returns the smallest value present.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *next;
} node;

node *head = NULL;

void create()
{
  node *temp;
  int choice = 1;
  while (choice)
  {
    node *newNode = (node *)malloc(sizeof(node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    if (head == NULL)
    {
      head = temp = newNode;
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

void findMinimum()
{
  if (head == NULL)
  {
    printf("List is empty\n");
    return;
  }

  int min = head->data;
  node *temp = head->next;

  while (temp != NULL)
  {
    if (temp->data < min)
    {
      min = temp->data;
    }
    temp = temp->next;
  }

  printf("Minimum element in the list: %d\n", min);
}


void maximum() {
  if(head == NULL) {
    printf("List is empty\n");
    return;
  }
  int max = head->data;
  node *temp = head->next;

  while(temp != NULL) {
    if(temp->data > max) {
      max = temp->data;
    }
    temp = temp->next;
  }
  printf("Maximum element in the list: %d\n", max);
}
int main()
{
  create();
  findMinimum();
  maximum();
  return 0;
}
