#include "Avl.h"
#include "Node.h"

int avlAdd(Node *root, Node *newNode){
  Node *root1;
  if(root->balanceFactor == 0){
    if(root->right==NULL&&root->left==NULL){
      root->right = newNode;
      root->balanceFactor -= 1;
    }
    else{
      *root1 = root->right;
      avlAdd(&root1, &newNode);
    }
  }
  if(root->balanceFactor > 0){
    if(root->left==NULL){
      root->left = newNode;
      root->balanceFactor += 1;
    }
    else{
      *root1 = root->left;
      avlAdd(&root1, &newNode);      
    }
  }
  if(root->balanceFactor < 0){
    if(root->right==NULL){
      root->left = newNode;
      root->balanceFactor -= 1;
    }
    else{
      *root1 = root->right;
      avlAdd(&root1, &newNode);  
    }
  }

}

int avlRemove(Node *root, int data){

}