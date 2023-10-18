#include <fstream>

#include "TStack.h"
#include "funcs.h"

int main() {
  std::ifstream fin("input.txt");
  TStack stack_in, stack_out;
  int ast_cnt = 0;
  char temp;
  bool check = false;
  while (fin) {
    fin.get(temp);

    if (check) break;  // почему 2 точки делает?
    if (temp == '.') check = true;
    if (temp == '*') ast_cnt++;

    stack_in.push(temp);
  }

  stack_out = transform_stack(stack_in, ast_cnt);
  stack_out.print();
  reversePrintStack(stack_out);

  fin.close();
}
