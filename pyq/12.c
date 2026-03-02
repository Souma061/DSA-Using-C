/*Write a C program that checks whether a string of parentheses is balanced or not using stack.
Input an expression in parentheses : {[])
Expected Output : The expression is not balanced.
Input an expression in parentheses : ((()))
Expected Output : The expression is balanced.*/

#include <stdio.h>

#define MAX 100

typedef struct
{
  char arr[MAX];
  int top;

} stack;

int isEmpty(stack *s)
{
  return s->top == -1;
}

int isFull(stack *s)
{
  return s->top == MAX - 1;
}
void initStack(stack *s)
{
  s->top = -1;
}

void push(stack *s, char c)
{
  if (isFull(s))
  {
    printf("Stack overflow. Cannot push %c\n", c);
    return;
  }
  s->top++;
  s->arr[s->top] = c;
}
/*top = -1
push '('
top becomes 0
arr[0] = '('*/

char pop(stack *s)
{
  if (isEmpty(s))
  {
    printf("Stack underflow. Cannot pop from an empty stack.\n");
    return '\0';
  }
  char temp = s->arr[s->top];
  s->top--;
  return temp;
}
/*Before pop:
top = 2
[ '(', '{', '[' ]

After pop:
top = 1*/

int isMatchingPairs(char open, char close)
{
  if (open == '(' && close == ')')
  {
    return 1;
  }
  if (open == '{' && close == '}')
  {
    return 1;
  }
  if (open == '[' && close == ']')
  {
    return 1;
  }
  return 0;
}

int isBalanced(char *expression)
{
  stack s;
  initStack(&s);

  for (int i = 0; expression[i] != '\0'; i++) {
    char ch = expression[i];
    if(ch == '(' || ch == '{' || ch == '[') {
      push(&s, ch);
    } else if(ch == ')' || ch == '}' || ch == ']') {
      if(isEmpty(&s)) {
        return 0;
      }
      char top = pop(&s);
      if(!isMatchingPairs(top, ch)) {
        return 0;
      }

    }
  }
  return isEmpty(&s);
}


int main() {
  char expression[MAX];
  printf("Input an expression in parentheses: ");
  scanf("%s", expression);

  if(isBalanced(expression)) {
    printf("The expression is balanced.\n");
  } else {
    printf("The expression is not balanced.\n");
  }

  return 0;
}
