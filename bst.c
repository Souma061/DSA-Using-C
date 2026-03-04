#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
} node;

node *createNode(int data)
{
  node *newNode = (node *)malloc(sizeof(node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

node *insert(node *root, int data)
{
  if (root == NULL)
  {
    return createNode(data);
  }
  if (data < root->data)
  {
    root->left = insert(root->left, data);
  }
  else
  {
    root->right = insert(root->right, data);
  }
  return root;
}

void inorder(node *root)
// left->root->right
{
  if (root != NULL)
  {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

void preorder(node *root)
{
  // root, left, right
  if (root != NULL)
  {
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

void postorder(node *root)
{
  // left->right->root
  if (root != NULL)
  {
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
  }
}

node *search(node *root, int key)
{
  if (root == NULL || root->data == key)
  {
    return root;
  }

  if (key < root->data)
  {
    return search(root->left, key);
  }
  else
  {
    return search(root->right, key);
  }
}

node *findMin(node *root)
{
  while (root->left != NULL)
  {
    root = root->left;
  }
  return root;
}

node *deleteNode(node *root, int key)
{
  if (root == NULL)
  {
    return NULL;
  }
  if (key < root->data)
  {
    root->left = deleteNode(root->left, key);
  }
  else if (key > root->data)
  {
    root->right = deleteNode(root->right, key);
  }
  else
  {
    if (root->left == NULL)
    {
      node *temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL)
    {
      node *temp = root->left;
      free(root);
      return temp;
    }
    node *temp = findMin(root->right);
    root->data = temp->data;
    root->right = deleteNode(root->right, temp->data);
  }
  return root;
}

int findDepth(node *root, int key, int depth)
{
  if (root == NULL)
  {
    return -1;
  }
  if (root->data == key)
  {
    return depth;
  }
  if (key < root->data)
  {
    return findDepth(root->left, key, depth + 1);
  }
  else
  {
    return findDepth(root->right, key, depth + 1);
  }
}

int main()
{
  node *root = NULL;
  root = insert(root, 50);
  insert(root, 30);
  insert(root, 20);
  insert(root, 40);
  insert(root, 70);
  insert(root, 60);
  insert(root, 80);

  printf("Inorder traversal: ");
  inorder(root);
  printf("\nPreorder traversal: ");
  preorder(root);
  printf("\nPostorder traversal: ");
  postorder(root);
  printf("\n");
  root = deleteNode(root, 20);
  printf("Inorder traversal after deleting 20: ");
  inorder(root);
  int depth = findDepth(root, 40, 0);
  if (depth != -1)
  {
    printf("\nDepth of node with key 40: %d\n", depth);
  }
  else
  {
    printf("\nNode with key 40 not found in the BST.\n");
  }

  int key = 40;
  node *result = search(root, key);

  if (result != NULL)
  {
    printf("\nElement %d found in the BST.\n", key);
  }
  else
  {
    printf("\nElement %d not found in the BST.\n", key);
  }

  return 0;
}
