#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *prev;
  struct Node *next;
} Node;

Node *head;

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
  Node *tail;
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





int main() {
  create();
  printf("Doubly Linked List: ");
  display();
  return 0;
}
