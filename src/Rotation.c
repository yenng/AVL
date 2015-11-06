#include "Rotation.h"
#include "Node.h"

void *rightRotation(Node **centerNode){
  Node *leftNode = (*centerNode)->left;
  Node *leftRightNode = leftNode->right;
  
  leftNode->right = (*centerNode);
  (*centerNode)->left = leftRightNode;
  
  (*centerNode) = leftNode;
}

void *leftRotation(Node **centerNode){
  Node *rightNode = (*centerNode)->right;
  Node *rightLeftNode = rightNode->left;
  
  rightNode->left = (*centerNode);
  (*centerNode)->right = rightLeftNode;
  
  (*centerNode) = rightNode;
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
