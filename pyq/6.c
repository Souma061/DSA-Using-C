/*Write a program to implement a Doubly Linked List with a search function to find a number in the list
and return its position. Implement a function to reverse the doubly linked list.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *prev;
  struct Node *next;

} node;

node *head = NULL;

void create()
{
  node *temp = NULL;
  int choice = 1;
  while (choice)
  {
    node *newNode = (node *)malloc(sizeof(node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->prev = NULL;
    newNode->next = NULL;
    if (head == NULL)
    {
      head = temp = newNode;
    }
    else
    {
      temp->next = newNode;
      newNode->prev = temp;
      temp = newNode;
    }
    printf("Do you want to continue (0/1): ");
    scanf("%d", &choice);
  }
}

void search(int target)
{
  node *temp = head;
  int position = 1;
  while (temp != NULL)
  {
    if (temp->data == target)
    {
      printf("Element found at position: %d\n", position);
      return;
    }
    else
    {
      temp = temp->next;
      position++;
    }
  }
  printf("Element not found in the list.\n");
}

void reverse() {
  if(head == NULL || head->next == NULL) {
    return;
  }
  node *current = head;
  node *temp = NULL;
  while (current != NULL)
  {
    temp = current->prev;
    current->prev = current->next;
    current->next = temp;
    current = current->prev;
  }
  head = temp->prev;

}


int main()
{
  create();
  int target;
  printf("Enter the number to search: ");
  scanf("%d", &target);
  search(target);
  reverse();
  printf("Reversed list: ");
  node *temp = head;
  while (temp != NULL)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
  return 0;
}
