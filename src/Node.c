#include "Node.h"
#include <stdio.h>
#include <stdlib.h>

Node *createNode(int weight, int data){
  Node* node = malloc(sizeof(Node)*3);
  
  node->weight = weight;
  node->data   = data;
  
  return (Node*)node;
}
