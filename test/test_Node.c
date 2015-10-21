#include "unity.h"
#include "Node.h"
#include <stdio.h>
#include <stdlib.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_module_create_node(void)
{
  //declare variable.
  Node* node1 = malloc(sizeof(Node));
  //create a tree with 1 node.
	node1 = (Node*)createNode(1, 60);
  //test the tree.
  TEST_ASSERT_EQUAL(1,node1->weight);
  TEST_ASSERT_EQUAL(60,node1->data);
}

void test_create_node_tree_with_2_branches(void)
{
  //declare variable.
	Node* node1 = malloc(sizeof(Node));
  //create a tree with 3 nodes.
	node1 = (Node*)createNode(2, 60);
  node1->left = (Node*)createNode(1,50);
  node1->right = (Node*)createNode(1,70);
  //test the tree.
  TEST_ASSERT_EQUAL(60,node1->data);
  TEST_ASSERT_EQUAL(50,node1->left->data);
  TEST_ASSERT_EQUAL(70,node1->right->data);
}

void test_create_tree_for_double_rotation(void){
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
  //test the tree.
  TEST_ASSERT_EQUAL(30,node1->data);
  TEST_ASSERT_EQUAL(20,node1->left->data);
  TEST_ASSERT_EQUAL(10,node1->left->left->data);
  TEST_ASSERT_EQUAL(80,node1->right->data);
  TEST_ASSERT_EQUAL(50,nodeBranch1->data);
  TEST_ASSERT_EQUAL(100,nodeBranch2->data);
  TEST_ASSERT_EQUAL(40,nodeBranch1->left->data);
  TEST_ASSERT_EQUAL(60,nodeBranch1->right->data);
  TEST_ASSERT_EQUAL(70,nodeBranch1->right->right->data);
  TEST_ASSERT_EQUAL(90,nodeBranch2->left->data);
}