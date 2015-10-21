#include "Avl.h"
#include "Node.h"
#include <stdio.h>
#include <stdlib.h>

int avlAdd(Node **root, Node *newNode){
  Node *subRoot;
  int i;
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
      subRoot = (*root)->left;
      i = avlAdd(&subRoot,newNode);
      if(i==1)
        (*root)->balanceFactor --;
    }
  }
  if((*root)->data < newNode->data){
    if((*root)->right == NULL){
      (*root)->right = newNode;
      (*root)->balanceFactor ++;
      if((*root)->left == NULL)
        return 1;
      else 
        return 0;
    }
    else{
      subRoot = (*root)->left;
      i = avlAdd(&subRoot,newNode);
      if(i==1)
        (*root)->balanceFactor ++;
    }
  }
}

int avlRemove(Node *root, int data){

}