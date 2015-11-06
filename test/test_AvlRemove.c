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

/*        avlRemove
            (10)
  (10)      ==>       NULL     
                    removedNode = (10)
*/
void test_avlRemove(void){
  Node* x = &node10;
  int *heightChange;
  Node* removedNode = avlRemove(&x, 10, heightChange);
  TEST_ASSERT_NULL(x); 
  TEST_ASSERT_EQUAL(10,removedNode->data);
}


/*        avlRemove
            (20)
  (30)      ==>       (30)  
  /  \                   \
(20)(40)                (40)
                    
   removedNode = (20)
*/
void test_avlremove_left_node_from_tree(void){
  //declare variable.
  Node* node = malloc(sizeof(Node));
  int *heightChange;
  //create a complicated tree.
	node = (Node*)createNode(0, 30);
  node->left = (Node*)createNode(0,20);
  node->right = (Node*)createNode(0,40);
  //create a tree with 3 nodes.
	Node *removedNode = avlRemove(&node, 20, heightChange);
  
  TEST_ASSERT_EQUAL(1,node->balanceFactor);
  TEST_ASSERT_EQUAL(30,node->data);
  TEST_ASSERT_EQUAL(0,node->right->balanceFactor);
  TEST_ASSERT_EQUAL(40,node->right->data); 
  TEST_ASSERT_NULL(node->left); 
  TEST_ASSERT_EQUAL(20,(int)(removedNode->data)); 
}


/*        avlRemove
            (40)
  (30)      ==>       (30)  
  /  \                / 
(20)(40)            (20)
                    
   removedNode = (40)
*/

void test_avlremove_right_node_from_tree(void){
  //declare variable.
  Node* node = malloc(sizeof(Node));
  int *heightChange;
  //create a complicated tree.
	node = (Node*)createNode(0, 30);
  node->left = (Node*)createNode(0,20);
  node->right = (Node*)createNode(0,40);
  //create a tree with 3 nodes.
	Node *removedNode = avlRemove(&node, 40, heightChange);
  
  TEST_ASSERT_EQUAL(-1,node->balanceFactor);
  TEST_ASSERT_EQUAL(30,node->data);
  TEST_ASSERT_EQUAL(0,node->left->balanceFactor);
  TEST_ASSERT_EQUAL(20,node->left->data); 
  TEST_ASSERT_NULL(node->right); 
  TEST_ASSERT_EQUAL(40,(int)(removedNode->data)); 
}

void test_avlremove_with_single_rotation(void){
  Node* node = &node30;
  int i = avlAdd(&node,&node50);
  i = avlAdd(&node,&node70);
  int *heightChange = 0;
  TEST_ASSERT_EQUAL(2,node->balanceFactor);
  TEST_ASSERT_EQUAL(30,node->data);
  TEST_ASSERT_EQUAL(1,node->right->balanceFactor);
  TEST_ASSERT_EQUAL(50,node->right->data); 
  TEST_ASSERT_EQUAL(0,node->right->right->balanceFactor);
  TEST_ASSERT_EQUAL(70,node->right->right->data); 
  TEST_ASSERT_NULL(node->left);
	Node *removedNode = avlRemove(&node, 30, heightChange);
  
  
}






