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
  head = 0;
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
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    if(head == NULL) {
      head = tail = newNode;

    } else {
      tail->next = newNode;
      tail = newNode;
    }
    tail->next = head;
    printf("Do you want to continue (0/1): ");
    scanf("%d", &choice);
  }
}

void display() {
  Node *temp = head;
  if(head == NULL) {
    printf("List is empty\n");
    return;
  }

  do {
    printf("%d -> ", temp->data);
    temp = temp->next;
  } while (temp != head);
  printf("(head: %d)\n", head->data);
}

int main() {

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

    switch(choice) {
      case 1:
        display();
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
