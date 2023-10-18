#include "funcs.h"

void moveUntil(TStack& stack_in, TStack& stack_out) {
  if (!stack_in.isEmpty()) {
    char temp;
    temp = stack_in.peek();
    while (temp != '*' && temp != '@') {
      stack_in.pop();
      stack_out.push(temp);
      temp = stack_in.peek();
    }
    if (temp == '*') stack_in.pop();
  }
}

void evenTransform(TStack& stack, int asterics_count) {
  char temp;
  temp = stack.peek();
  int ch_deleted = 0;
  while (temp != '*' && temp != '@' && ch_deleted < asterics_count) {
    stack.pop();
    temp = stack.peek();
    ch_deleted++;
  }
}

bool isSeparator(char ch, std::string seps) {
  for (auto& elem : seps)
    if (elem == ch) return true;
  return false;
}

void oddTransform(TStack& stack, int asterics_count) {
  std::string separators = "',;:-";
  int words_deleted = 0;

  char temp;
  temp = stack.peek();
  while (temp != '*' && temp != '@' && words_deleted < asterics_count) {
    stack.pop();
  }
}

TStack transform_stack(TStack stack, int asterics_count) {
  TStack stack_out;
  moveUntil(stack, stack_out);
  if (asterics_count % 2 == 0) {
    for (int i = 0; i < asterics_count; i++) {
      evenTransform(stack, asterics_count);
      moveUntil(stack, stack_out);
    }
  }

  // stack.print();
  return stack_out;
}