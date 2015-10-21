#include "Rotation.h"
#include "Node.h"

Node *rightRotation(Node *centerNode){
  Node *leftNode = centerNode->left;
  Node *rightNode = leftNode->right;
  
  leftNode->right = centerNode;
  centerNode->left = rightNode;
  
  return (Node*)leftNode;
}

Node *leftRotation(Node *centerNode){
  Node *rightNode = centerNode->right;
  Node *leftNode = rightNode->left;
  
  rightNode->left = centerNode;
  centerNode->right = leftNode;
  
  return (Node*)rightNode;
}

Node *rightLeftRotation(Node *centerNode){
  Node *rightNode = centerNode->right;
  Node *leftNode = rightNode->left;
  
  leftNode->left = centerNode;
  leftNode->right = rightNode;
  rightNode->left = leftNode->right;
  centerNode->right = leftNode->left;
  
  return (Node*)leftNode;
}
