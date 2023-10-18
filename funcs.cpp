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

void oddTransform(TStack& stack, TStack& stack_out, int asterics_count) {
  std::string separators = "',;:-";
  int words_deleted = 0;

  char temp;
  temp = stack.peek();

  int ind_word = 0;
  while (temp != '*' && temp != '@' && words_deleted < asterics_count) {
    if (isSeparator(temp, separators)) {
      if (ind_word == 0) {
        stack_out.push(temp);
        stack.pop();
      } else {
        words_deleted++;
        stack_out.push(temp);
        stack.pop();
        ind_word = 0;
      }
    } else {
      stack.pop();
      ind_word++;
      temp = stack.peek();
    }
  }
}

TStack transform_stack(TStack stack, int asterics_count) {
  TStack stack_out;
  moveUntil(stack, stack_out);
  for (int i = 0; i < asterics_count; i++) {
    if (asterics_count % 2 == 0) {
      evenTransform(stack, asterics_count);
    } else {
      oddTransform(stack, stack_out, asterics_count);
    }
    moveUntil(stack, stack_out);
  }

  return stack_out;
}

void reversePrintStack(TStack stack) {
  if (stack.isEmpty()) return;

  char temp = stack.peek();

  stack.pop();

  reversePrintStack(stack);

  std::cout << temp << " ";

  stack.push(temp);
}
