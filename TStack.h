#pragma once
#include <iostream>

typedef char data_t;

class TStack {
  struct Node {
    data_t data;
    Node* next;
  };

  Node* top;

 public:
  TStack();
  ~TStack();
  TStack(const TStack& other);
  TStack& operator=(const TStack& other);
  void push(const data_t& data);
  void pop();
  data_t peek() const;
  bool isEmpty() const;
  void print() const;
  void clear();
};
