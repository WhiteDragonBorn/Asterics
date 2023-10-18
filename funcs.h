#pragma once
#pragma once
#include <string>

#include "TStack.h"

void moveUntil(TStack& stack_in, TStack& stack_out);
void evenTransform(TStack& stack, int asterics_count);
bool isSeparator(char ch, std::string seps);
void oddTransform(TStack& stack, TStack& stack_out, int asterics_count);
TStack transform_stack(TStack stack, int asterics_count);
void reversePrintStack(TStack stack);
