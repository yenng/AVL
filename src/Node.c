#include "Node.h"
#include <stdio.h>
#include <stdlib.h>

Node *createNode(int balanceFactor, int data){
  Node* node = malloc(sizeof(Node));
  
  node->balanceFactor = balanceFactor;
  node->data   = data;
  node->left   = NULL;
  node->right  = NULL;
  
  return (Node*)node;
}
