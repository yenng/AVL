#include "unity.h"
#include "Rotation.h"
#include "Node.h"
#include <stdio.h>
#include <stdlib.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_right_rotate_node_tree_with_2_branches(void)
{
  //create the tree with 3 nodes
	Node* node1 = malloc(sizeof(Node));
	node1 = (Node*)createNode(2, 70);
  node1->left = (Node*)createNode(1,50);
  node1->left->right = (Node*)createNode(1,60);
  //rotate the tree to right
  rightRotation(&node1);
  //test start here
  TEST_ASSERT_EQUAL(50,node1->data);
  TEST_ASSERT_EQUAL(70,node1->right->data);
  TEST_ASSERT_EQUAL(60,node1->right->left->data);
}

void test_left_rotate_node_tree_with_2_branches(void)
{
  //create the tree with 3 nodes
	Node* node1 = malloc(sizeof(Node));
	node1 = (Node*)createNode(2, 50);
  node1->right = (Node*)createNode(1,70);
  node1->right->left = (Node*)createNode(1,60);
  //rotate the tree to left
  leftRotation(&node1);
  //test start here
  TEST_ASSERT_EQUAL(70,node1->data);
  TEST_ASSERT_EQUAL(50,node1->left->data);
  TEST_ASSERT_EQUAL(60,node1->left->right->data);
}

void test_double_rotation_the_tree(void){
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
  
  rightLeftRotation(&node1);
  nodeBranch1 = node1->right->left;
  nodeBranch2 = node1->right->right;
  Node* nodeBranch3 = node1->left->left;
  
  //test the tree after rotation.
  TEST_ASSERT_EQUAL(50,node1->data);
  TEST_ASSERT_EQUAL(30,node1->left->data);
  TEST_ASSERT_EQUAL(20,node1->left->left->data);
  TEST_ASSERT_EQUAL(40,node1->left->right->data);
  TEST_ASSERT_EQUAL(80,node1->right->data);
  TEST_ASSERT_EQUAL(60,nodeBranch1->data);
  TEST_ASSERT_EQUAL(100,nodeBranch2->data);
  TEST_ASSERT_EQUAL(70,nodeBranch1->right->data);
  TEST_ASSERT_EQUAL(90,nodeBranch2->left->data);
  TEST_ASSERT_EQUAL(10,nodeBranch3->left->data);
}

