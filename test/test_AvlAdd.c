#include "unity.h"
#include "Avl.h"
#include "Node.h"
#include "Rotation.h"
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
  
  TEST_ASSERT_EQUAL(10,x->data);
  TEST_ASSERT_EQUAL(1,x->balanceFactor);
  TEST_ASSERT_EQUAL(20,x->right->data);
  TEST_ASSERT_EQUAL(0,x->right->balanceFactor);
}
void test_avlAdd_twice(void){
  Node* x = &node30;
	int i;
  i = avlAdd(&x, &node20);
  i = avlAdd(&x, &node40);
  
  TEST_ASSERT_EQUAL(30,x->data);
  TEST_ASSERT_EQUAL(0,x->balanceFactor);
  TEST_ASSERT_EQUAL(20,x->left->data);
  TEST_ASSERT_EQUAL(0,x->left->balanceFactor);
  TEST_ASSERT_EQUAL(40,x->right->data);
  TEST_ASSERT_EQUAL(0,x->right->balanceFactor);
}

void test_create_a_large_tree_by_using_avlAdd(void){
  Node* tree = &node30;
  int i = avlAdd(&tree,&node20);
  i = avlAdd(&tree,&node50);
  i = avlAdd(&tree,&node10);
  i = avlAdd(&tree,&node40);
  i = avlAdd(&tree,&node80);
  i = avlAdd(&tree,&node60);
  i = avlAdd(&tree,&node100);
  
  TEST_ASSERT_EQUAL(30,tree->data);
  TEST_ASSERT_EQUAL(0,tree->balanceFactor);
  TEST_ASSERT_EQUAL(20,tree->left->data);
  TEST_ASSERT_EQUAL(-1,tree->left->balanceFactor);
  TEST_ASSERT_EQUAL(10,tree->left->left->data);
  TEST_ASSERT_EQUAL(0,tree->left->left->balanceFactor);
  TEST_ASSERT_EQUAL(50,tree->right->data);
  TEST_ASSERT_EQUAL(1,tree->right->balanceFactor);
  TEST_ASSERT_EQUAL(80,tree->right->right->data);
  TEST_ASSERT_EQUAL(0,tree->right->right->balanceFactor);
  TEST_ASSERT_EQUAL(40,tree->right->left->data);
  TEST_ASSERT_EQUAL(0,tree->right->left->balanceFactor);
  TEST_ASSERT_EQUAL(100,tree->right->right->right->data);
  TEST_ASSERT_EQUAL(0,tree->right->right->right->balanceFactor);
  TEST_ASSERT_EQUAL(60,tree->right->right->left->data);
  TEST_ASSERT_EQUAL(0,tree->right->right->left->balanceFactor);
  
  
}
void test_avlAdd_node_to_tree_with_1_branch(void){
  //declare variable.
  Node* node = malloc(sizeof(Node));
  //create a complicated tree.
	node = (Node*)createNode(-1, 30);
  node->left = (Node*)createNode(0,20);
  //create a tree with 3 nodes.
	int i;
  i = avlAdd(&node, &node40);
  
  TEST_ASSERT_EQUAL(0,node->balanceFactor);
  TEST_ASSERT_EQUAL(30,node->data);
  TEST_ASSERT_EQUAL(0,node->left->balanceFactor);
  TEST_ASSERT_EQUAL(20,node->left->data);
  TEST_ASSERT_EQUAL(0,node->right->balanceFactor);
  TEST_ASSERT_EQUAL(40,node->right->data);
}

void test_single_rotation_with_avlAdd(void){
  //declare variable.
  Node* node = malloc(sizeof(Node));
  //create a complicated tree.
	node = (Node*)createNode(2, 30);
  node->right = (Node*)createNode(1,40);
  node->right->right = (Node*)createNode(0,50);
  
  int i = avlAdd(&node, NULL);
  
  TEST_ASSERT_EQUAL(0,node->balanceFactor);
  TEST_ASSERT_EQUAL(40,node->data);
  TEST_ASSERT_EQUAL(0,node->left->balanceFactor);
  TEST_ASSERT_EQUAL(30,node->left->data);
  TEST_ASSERT_EQUAL(0,node->right->balanceFactor);
  TEST_ASSERT_EQUAL(50,node->right->data);
}

void test_single_rotation_with_avlAdd_and_add_node(void){
  //declare variable.
  Node* node = malloc(sizeof(Node));
  //create a complicated tree.
	node = (Node*)createNode(2, 30);
  node->right = (Node*)createNode(1,40);
  node->right->right = (Node*)createNode(0,50);
  
  int i = avlAdd(&node, &node20);
  
  TEST_ASSERT_EQUAL(-1,node->balanceFactor);
  TEST_ASSERT_EQUAL(40,node->data);
  TEST_ASSERT_EQUAL(-1,node->left->balanceFactor);
  TEST_ASSERT_EQUAL(30,node->left->data);
  TEST_ASSERT_EQUAL(0,node->left->left->balanceFactor);
  TEST_ASSERT_EQUAL(20,node->left->left->data);
  TEST_ASSERT_EQUAL(0,node->right->balanceFactor);
  TEST_ASSERT_EQUAL(50,node->right->data);
}

void test_add_a_node_and_double_rotation_the_tree_by_using_avlAdd_function(void){
  //declare variable.
  Node* node1 = malloc(sizeof(Node));
  //create a complicated tree.
	node1 = (Node*)createNode(2, 30);
  node1->left = (Node*)createNode(-1,20);
  node1->left->left = (Node*)createNode(0,10);
  node1->right = (Node*)createNode(-1,80);
  node1->right->left = (Node*)createNode(1,50);
  node1->right->right = (Node*)createNode(-1,100);
  
  //declare variable to prevent complicated term.
  Node* nodeBranch1 = node1->right->left;
  Node* nodeBranch2 = node1->right->right;
  
  //continue build the tree.
  nodeBranch1->left = (Node*)createNode(0,40);
  nodeBranch1->right = (Node*)createNode(1,60);
  nodeBranch1->right->right = (Node*)createNode(0,70);
  nodeBranch2->left = (Node*)createNode(0,90);
  int i;
  i = avlAdd(&node1, &node110);
  nodeBranch1 = node1->right->left;
  nodeBranch2 = node1->right->right;
  Node* nodeBranch3 = node1->left->left;
  
  //test the tree after rotation.  
  TEST_ASSERT_EQUAL(50,node1->data);
  TEST_ASSERT_EQUAL(0,node1->balanceFactor);
  TEST_ASSERT_EQUAL(30,node1->left->data);
  TEST_ASSERT_EQUAL(-1,node1->left->balanceFactor);
  TEST_ASSERT_EQUAL(20,node1->left->left->data);
  TEST_ASSERT_EQUAL(-1,node1->left->left->balanceFactor);
  TEST_ASSERT_EQUAL(40,node1->left->right->data);
  TEST_ASSERT_EQUAL(0,node1->left->right->balanceFactor);
  TEST_ASSERT_EQUAL(80,node1->right->data);
  TEST_ASSERT_EQUAL(0,node1->right->balanceFactor);
  TEST_ASSERT_EQUAL(60,nodeBranch1->data);
  TEST_ASSERT_EQUAL(1,nodeBranch1->balanceFactor);
  TEST_ASSERT_EQUAL(100,nodeBranch2->data);
  TEST_ASSERT_EQUAL(0,nodeBranch2->balanceFactor);
  TEST_ASSERT_EQUAL(70,nodeBranch1->right->data);
  TEST_ASSERT_EQUAL(0,nodeBranch1->right->balanceFactor);
  TEST_ASSERT_EQUAL(90,nodeBranch2->left->data);
  TEST_ASSERT_EQUAL(0,nodeBranch2->left->balanceFactor);
  TEST_ASSERT_EQUAL(10,nodeBranch3->left->data);
  TEST_ASSERT_EQUAL(0,nodeBranch3->left->balanceFactor);
  TEST_ASSERT_EQUAL(110,nodeBranch2->right->data);
  TEST_ASSERT_EQUAL(0,nodeBranch2->right->balanceFactor);
}

void test_double_rotation_the_tree_by_using_avlAdd_function(void){
  //declare variable.
  Node* node1 = malloc(sizeof(Node));
  //create a complicated tree.
	node1 = (Node*)createNode(2, 30);
  node1->left = (Node*)createNode(-1,20);
  node1->left->left = (Node*)createNode(0,10);
  node1->right = (Node*)createNode(-1,80);
  node1->right->left = (Node*)createNode(1,50);
  node1->right->right = (Node*)createNode(-1,100);
  
  //declare variable to prevent complicated term.
  Node* nodeBranch1 = node1->right->left;
  Node* nodeBranch2 = node1->right->right;
  
  //continue build the tree.
  nodeBranch1->left = (Node*)createNode(0,40);
  nodeBranch1->right = (Node*)createNode(1,60);
  nodeBranch1->right->right = (Node*)createNode(0,70);
  nodeBranch2->left = (Node*)createNode(0,90);
  int i;
  i = avlAdd(&node1, NULL);
  nodeBranch1 = node1->right->left;
  nodeBranch2 = node1->right->right;
  Node* nodeBranch3 = node1->left->left;
  
  //test the tree after rotation.
  TEST_ASSERT_EQUAL(50,node1->data);
  TEST_ASSERT_EQUAL(0,node1->balanceFactor);
  TEST_ASSERT_EQUAL(30,node1->left->data);
  TEST_ASSERT_EQUAL(-1,node1->left->balanceFactor);
  TEST_ASSERT_EQUAL(20,node1->left->left->data);
  TEST_ASSERT_EQUAL(-1,node1->left->left->balanceFactor);
  TEST_ASSERT_EQUAL(40,node1->left->right->data);
  TEST_ASSERT_EQUAL(0,node1->left->right->balanceFactor);
  TEST_ASSERT_EQUAL(80,node1->right->data);
  TEST_ASSERT_EQUAL(0,node1->right->balanceFactor);
  TEST_ASSERT_EQUAL(60,nodeBranch1->data);
  TEST_ASSERT_EQUAL(1,nodeBranch1->balanceFactor);
  TEST_ASSERT_EQUAL(100,nodeBranch2->data);
  TEST_ASSERT_EQUAL(-1,nodeBranch2->balanceFactor);
  TEST_ASSERT_EQUAL(70,nodeBranch1->right->data);
  TEST_ASSERT_EQUAL(0,nodeBranch1->right->balanceFactor);
  TEST_ASSERT_EQUAL(90,nodeBranch2->left->data);
  TEST_ASSERT_EQUAL(0,nodeBranch2->left->balanceFactor);
  TEST_ASSERT_EQUAL(10,nodeBranch3->left->data);
  TEST_ASSERT_EQUAL(0,nodeBranch3->left->balanceFactor);
}
