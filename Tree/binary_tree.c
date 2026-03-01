#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *left, *right;
} node;

node *create()
{
  int x;
  node *newNode = (node *)malloc(sizeof(node));
  printf("Enter data for node (or -1 to stop): ");
  scanf("%d", &x);
  if (x == -1)
  {
    free(newNode);
    return NULL;
  }
  newNode->data = x;
  printf("Enter left child of %d:\n", x);
  newNode->left = create();
  printf("Enter right child of %d:\n", x);
  newNode->right = create();
  return newNode;
}


