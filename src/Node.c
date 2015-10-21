#include "Node.h"
#include <stdio.h>
#include <stdlib.h>

Node *createNode(int balanceFactor, int data){
  Node* node = malloc(sizeof(Node)*3);
  
  node->balanceFactor = balanceFactor;
  node->data   = data;
  
  return (Node*)node;
}
