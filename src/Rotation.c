#include "Rotation.h"
#include "Node.h"

Node *rightRotation(Node *centerNode){
  Node *leftNode = centerNode->left;
  Node *leftRightNode = leftNode->right;
  
  leftNode->right = centerNode;
  centerNode->left = leftRightNode;
  
  return (Node*)leftNode;
}

Node *leftRotation(Node *centerNode){
  Node *rightNode = centerNode->right;
  Node *rightLeftNode = rightNode->left;
  
  rightNode->left = centerNode;
  centerNode->right = rightLeftNode;
  
  return (Node*)rightNode;
}

void *rightLeftRotation(Node **centerNode){
  Node *rightNode = (*centerNode)->right;
  Node *rightLeftNode = rightNode->left;
  
  (*centerNode)->right = rightLeftNode->left;
  rightLeftNode->left = (*centerNode);
  rightNode->left = rightLeftNode->right;
  rightLeftNode->right = rightNode;
  
  (*centerNode) = rightLeftNode;
}
