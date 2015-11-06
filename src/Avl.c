#include "Avl.h"
#include "Node.h"
#include "Rotation.h"
#include <stdio.h>
#include <stdlib.h>

int avlAdd(Node **root, Node *newNode){
  int i = 0;
  rotationDeterminator(&(*root));
  
  //avlAdd
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
        i = avlAdd(&((*root)->right),newNode);
        if(i==1)
          (*root)->balanceFactor ++;
      }
    }
  }
  
}

Node *avlRemove(Node **root, int data, int *heightChange){
  Node *removedNode;
  Node *replacer;
  rotationDeterminator(&(*root));
  // *heightChange = 0;

  
  //avlRemove
  //when the data that wanted to remove is smaller than the data in the node.
  if((*root)->data > data){
    if((*root)->left == NULL){ 
      printf("(*root)->left is NULL");
      return NULL;
    }
    else{
      if((*root)->left->data == data){
        removedNode = (*root)->left;
        if((*root)->left->left == NULL && (*root)->left->right == NULL)
          (*root)->left = NULL;
        
        else if((*root)->left->left!=NULL && (*root)->left->right == NULL)
          (*root)->left = (*root)->left->left;
        
        else if((*root)->left->left==NULL && (*root)->left->right != NULL)
          (*root)->left = (*root)->left->right;
        
        else{
          replacer = avlGetReplacer(&((*root)->left->right));
          (*root)->left->data = replacer->data;
        }
        removedNode->left = NULL;
        removedNode->right = NULL;
        (*root)->balanceFactor += 1;
        if((*root)->balanceFactor==0)
          (*heightChange) = 1;
        return removedNode;
      }
      else{
        removedNode = avlRemove(&((*root)->left), data, heightChange); 
        if((*heightChange) == 1)
          (*root)->balanceFactor ++;
        return removedNode;
      }
    }
  }
  
  //when the data that wanted to remove is larger than the data in the node.
  else if((*root)->data < data){
    if((*root)->right->data == data){
      removedNode = (*root)->right;
      if((*root)->right->left == NULL && (*root)->right->right == NULL)
        (*root)->right = NULL;
      
      else if((*root)->right->left!=NULL && (*root)->right->right == NULL)
        (*root)->right = (*root)->right->left;
      
      else if((*root)->right->left==NULL && (*root)->right->right != NULL)
        (*root)->right = (*root)->right->right;
      
      else{
        replacer = avlGetReplacer(&((*root)->right->right));
        (*root)->right->data = replacer->data;
      }
      (*root)->balanceFactor -= 1;
      if((*root)->balanceFactor==0)
        (*heightChange) = 1;
      return removedNode;
    }
    else{
      removedNode = avlRemove(&((*root)->right), data, heightChange);
      if((*heightChange) == 1)
        (*root)->balanceFactor --;
      return removedNode;
    }
  }
  
  //when the data that wanted to remove is larger than the data in the node.
  else{
    removedNode = (*root);
    if((*root)->left == NULL && (*root)->right == NULL)
      (*root) = NULL;
  
    else if((*root)->left!=NULL && (*root)->right == NULL)
      (*root) = (*root)->left;
  
    else if((*root)->left==NULL && (*root)->right != NULL)
      (*root) = (*root)->right;
    
    else{
      replacer = avlGetReplacer(&((*root)->right));
      (*root)->data = replacer->data;
    }
    
    removedNode->left = NULL;
    removedNode->right = NULL;
    return removedNode;
  }
}

Node *avlGetReplacer(Node **root){
  Node *replacer;
  if((*root)==NULL)
    return NULL;
  else{
    if((*root)->left==NULL){
      if((*root)->right!=NULL)
        (*root) = (*root)->right;
      return (*root);
    }
    else{
      replacer = avlGetReplacer(&(*root)->left);
      return replacer;
    }
  }
}

void rotationDeterminator(Node **root){
    //Rotation algorithm saved here.
  if((*root)->balanceFactor == 2){
    Node* rightNode = (*root)->right;
    Node* rightLeftNode = rightNode->left;
    
    //DOUBLE ROTATION case1
    if(rightNode->balanceFactor == -1 && rightLeftNode->balanceFactor == -1){
      rightLeftNode->balanceFactor = 0;
      rightNode->balanceFactor = 1;
      (*root)->balanceFactor = 0;
      rightLeftRotation(&(*root));
    }
    
    //DOUBLE ROTATION case2
    else if (rightNode->balanceFactor == -1 && rightLeftNode->balanceFactor == 0){
      rightLeftNode->balanceFactor = 0;
      rightNode->balanceFactor = 0;
      (*root)->balanceFactor = 0;
      rightLeftRotation(&(*root));
    }
    
    //DOUBLE ROTATION case3
    else if (rightNode->balanceFactor == -1 && rightLeftNode->balanceFactor == 1){
      rightLeftNode->balanceFactor = 0;
      rightNode->balanceFactor = 0;
      (*root)->balanceFactor = -1;
      rightLeftRotation(&(*root));
    }
    
    //SINGLE ROTATION case1
    else if (rightNode->balanceFactor == 0){
      rightNode->balanceFactor = -1;
      (*root)->balanceFactor = 1;
      leftRotation(&(*root));
    }
    
    //SINGLE ROTATION case2
    else if (rightNode->balanceFactor == 1){
      rightNode->balanceFactor = 0;
      (*root)->balanceFactor = 0;
      leftRotation(&(*root));
    }
  }
}
