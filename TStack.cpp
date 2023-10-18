#include "TStack.h"

TStack::TStack() { top = nullptr; }

TStack::~TStack() { clear(); }

TStack::TStack(const TStack& other) {
  top = nullptr;
  TStack temp;
  Node* node = other.top;
  while (node != nullptr) {
    temp.push(node->data);
    node = node->next;
  }
  node = temp.top;
  while (node != nullptr) {
    push(node->data);
    node = node->next;
  }
  node = nullptr;
}

TStack& TStack::operator=(const TStack& other) {
  clear();
  TStack temp;
  Node* node = other.top;
  while (node != nullptr) {
    temp.push(node->data);
    node = node->next;
  }
  node = temp.top;
  while (node != nullptr) {
    push(node->data);
    node = node->next;
  }
  node = nullptr;
  return *this;
}

bool TStack::isEmpty() const { return top == nullptr; }

void TStack::push(const data_t& data) {
  Node* node = new Node;
  node->data = data;
  node->next = top;
  top = node;
}

void TStack::pop() {
  if (isEmpty()) {
    //std::cout << "Pop is empty" << std::endl;
    return;
  }
  Node* node = top;
  top = top->next;
  delete node;
  node = nullptr;
}

data_t TStack::peek() const {
  if (isEmpty()) {
    //std::cout << "Peek is empty" << std::endl;
    return '@';
  }
  return top->data;
}

void TStack::print() const {
  if (isEmpty()) {
    std::cout << "Stack is empty" << std::endl;
    return;
  }
  Node* node = top;
  while (node != nullptr) {
    std::cout << node->data << " ";
    node = node->next;
  }
  std::cout << std::endl;
}

void TStack::clear() {
  while (!isEmpty()) {
    pop();
  }
}