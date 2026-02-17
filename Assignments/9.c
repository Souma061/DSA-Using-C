/*. Write a program to reverse the order of the elements in the stack using additional stack. */

#include <stdio.h>
#define MAX 100

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

void push1(int x)
{
  stack1[++top1] = x;
}

int pop1()
{
  return stack1[top1--];
}

void push2(int x)
{
  stack2[++top2] = x;
}

int pop2()
{
  return stack2[top2--];
}

int isEmpty1()
{
  return top1 == -1;
}

int main()
{
  int n, item;
  printf("Enter the number of elements to push onto the stack: ");
  scanf("%d", &n);
  if (n > MAX)
  {
    printf("Number of elements exceeds stack capacity\n");
    return 1;
  }
  printf("Enter %d elements:\n", n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &item);
    push1(item);
  }
  printf("Original stack elements: ");
  for (int i = top1; i >= 0; i--)
  {
    printf("%d ", stack1[i]);
  }
  printf("\n");

  while (!isEmpty1())
  {
    push2(pop1());
  }

  printf("Reversed stack elements: ");
  while (top2 != -1)
  {
    printf("%d ", pop2());
  }

  printf("\n");
  return 0;
}
