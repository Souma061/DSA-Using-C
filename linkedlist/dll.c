#include<stdio.h>
#include<stdlib.h>


typedef struct Node {
  int data;
  struct Node *prev;
  struct Node *next;
} node;

node *head;
node *tail;

void createDll() {
  head = NULL;
  int choice = 1;
  while(choice) {
    node *newnode = (node *)malloc(sizeof(node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
    newnode->next = NULL;

    if(head == NULL) {
      head = tail = newnode;
    } else {
      tail->next = newnode;
      newnode->prev = tail;
      tail = newnode;
    }
    printf("Do you want to continue? (0/1)");
    scanf("%d", &choice);
  }
}



void insertAtBeg() {
  node *newnode = (node *)malloc(sizeof(node));
  printf("Enter data: ");
  scanf("%d", &newnode->data);
  newnode->prev = NULL;
  newnode->next = head;

  if(head != NULL) {
    head->prev = newnode;
  } else {
    tail = newnode;
  }
  head = newnode;
}


void insertAtEnd() {
  node *newNode = (node *)malloc(sizeof(node));
  printf("Enter data: ");
  scanf("%d", &newNode->data);
  newNode->prev = NULL;
  newNode->next = NULL;

  if(tail == NULL) {
    head = tail = newNode;
  } else {
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
  }
}


void inserAtPos() {
  int pos, i = 1;
  printf("Enter the position: ");
  scanf("%d", &pos);

  if(pos < 1) {
    printf("Invalid position\n");
    return;
  } else if(pos == 1) {
    insertAtBeg();
    return;

  }
  else {
    node *temp = head;
    node *newNode = (node *)malloc(sizeof(node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->prev = NULL;
    newNode->next = NULL;
    while(i < pos - 1 && temp!= NULL) {
      temp = temp->next;
      i++;
    }
    newNode->prev = temp;
    newNode->next = temp->next;
    temp->next = newNode;
    newNode->next->prev = newNode;
  }
}
