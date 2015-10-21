#include "Avl.h"
#include "Node.h"
#include "Rotation.h"
#include <stdio.h>
#include <stdlib.h>

int avlAdd(Node **root, Node *newNode){
  Node* subRoot;
  int i = 0;
  if(newNode != NULL){
    if((*root)->data > newNode->data){
      if((*root)->left == NULL){
        (*root)->left = newNode;
        (*root)->balanceFactor --;
        if((*root)->right == NULL)
          return 1;
        else 
          return 0;
      }
      else{
        // subRoot = (*root)->left;
        i = avlAdd(&((*root)->left),newNode);
        if(i==1)
          (*root)->balanceFactor --;
      }
    }
    else if((*root)->data < newNode->data){
      if((*root)->right == NULL){
        (*root)->right = newNode;
        (*root)->balanceFactor ++;
        if((*root)->left == NULL)
          return 1;
        else 
          return 0;
      }
      else{
        // subRoot = (*root)->right;
        i = avlAdd(&((*root)->right),newNode);
        if(i==1)
          (*root)->balanceFactor ++;
      }
    }
  }
  
  
  if((*root)->balanceFactor == 2){
    Node* rightNode = (*root)->right;
    Node* rightLeftNode = rightNode->left;
    if(rightNode->balanceFactor == -1 && rightLeftNode->balanceFactor == -1){
      rightLeftRotation(&(*root));
      rightLeftNode->balanceFactor = 0;
      rightNode->balanceFactor = 1;
      (*root)->balanceFactor = 0;
    }
    else if (rightNode->balanceFactor == -1 && rightLeftNode->balanceFactor == 0){
      rightLeftRotation(&(*root));
      rightLeftNode->balanceFactor = 0;
      rightNode->balanceFactor = 0;
      (*root)->balanceFactor = 0;
    }
    else if (rightNode->balanceFactor == -1 && rightLeftNode->balanceFactor == 1){
      rightLeftRotation(&(*root));
      rightLeftNode->balanceFactor = 0;
      rightNode->balanceFactor = 0;
      (*root)->balanceFactor = -1;
    }
    else if (rightNode->balanceFactor == 0 && rightLeftNode->balanceFactor == 1){
      rightLeftRotation(&(*root));
      rightLeftNode->balanceFactor = 0;
      rightNode->balanceFactor = 0;
      (*root)->balanceFactor = -1;
    }
    
  }
}

int avlRemove(Node *root, int data){

}