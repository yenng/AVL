#ifndef Avl_H
#define Avl_H
#include "Node.h"

int avlAdd(Node **root, Node *newNode);
Node *avlRemove(Node **root, int data, int *heightChange);
Node *avlGetReplacer(Node **root);
void rotationDeterminator(Node **root);
#endif // Avl_H
