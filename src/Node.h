#ifndef Node_H
#define Node_H

typedef struct Node_t Node;

struct Node_t{
  Node *left;
  Node *right;
  int weight;
  int data;
};

Node *createNode();

#endif // Node_H
