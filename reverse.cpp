#include <iostream>

using namespace std;

class Node
{
public:
  int data;
  Node *next;

  Node(int data)
  {
    this->data = data;
    this->next = NULL;
  }
};

int main()
{
  Node *head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);

  // Reverse the linked list
  Node *prev = NULL;
  Node *current = head;
  Node *next = NULL;

  while (current != NULL)
  {
    next = current->next; // Store the next node
    current->next = prev; // Reverse the current node's pointer
    prev = current;       // Move prev to the current node
    current = next;       // Move to the next node
  }
  head = prev; // Update head to the new front of the list

  // Print the reversed linked list
  current = head;
  while (current != NULL)
  {
    cout << current->data << " ";
    current = current->next;
  }
  cout << endl;

  return 0;
}
