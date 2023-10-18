#include "funcs.h"

void moveUntil(TStack& stack_in, TStack& stack_out) {
  char temp;
  temp = stack_in.peek();
  while (temp != '*' && temp != '@') {
    stack_in.pop();
    stack_out.push(temp);
    temp = stack_in.peek();
  }
  if (temp == '*') stack_in.pop();
}

TStack transform_stack(TStack stack, int asterics_count) {
  TStack stack_out;
  moveUntil(stack, stack_out);
  stack.print();
  return stack_out;
}