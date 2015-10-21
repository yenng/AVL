#include "unity.h"
#include "Avl.h"
#include "Node.h"
#include <stdio.h>
#include <stdlib.h>

Node  node10, node20, node30, node40, node50, node60, node70, node80, node90;
Node  node100, node110, node120, node130, node140, node150, node160, node170;
Node  node180, node190;

void resetNode(Node* node, int value){
  node->data = value;
  node->balanceFactor = 0;
  node->left = NULL;
  node->right = NULL;
}

void setUp(void){
  resetNode(&node10, 10);
  resetNode(&node20, 20);
  resetNode(&node30, 30);
  resetNode(&node40, 40);
  resetNode(&node50, 50);
  resetNode(&node60, 60);
  resetNode(&node70, 70);
  resetNode(&node80, 80);
  resetNode(&node90, 90);
  resetNode(&node100, 100);
  resetNode(&node110, 110);
  resetNode(&node120, 120);
  resetNode(&node130, 130);
  resetNode(&node140, 140);
  resetNode(&node150, 150);
  resetNode(&node160, 160);
  resetNode(&node170, 170);
  resetNode(&node180, 180);
  resetNode(&node190, 190);
}

void tearDown(void){}

void test_avlAdd(void){
  Node* x = &node10;
	int i;
  i = avlAdd(&x, &node20);
  
  TEST_ASSERT_EQUAL(20,x->right->data);
}
void test_avlAdd_node_to_tree_with_1_branch(void)
{
  //declare variable.
	Node* node1 = malloc(sizeof(Node));
  // Node* x = &node1;
  //create a tree with 3 nodes.
	node1 = (Node*)createNode(1, 60);
  node1->left = (Node*)createNode(0,50);
  // int i = avlAdd(&node1, &node20);
}
