#include "funcs.h"

TStack transform_stack(TStack stack, int asterics_count) {
  TStack stack_out;
  char temp;
  temp = stack.peek();
  while (temp != '*' && stack.peek() != '@') {
    stack_out.push(temp);
    stack.pop();
    temp = stack.peek();
  }
  return stack_out;
}