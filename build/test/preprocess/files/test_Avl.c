#include "Node.h"
#include "Avl.h"
#include "unity.h"


Node node10, node20, node30, node40, node50, node60, node70, node80, node90;

Node node100, node110, node120, node130, node140, node150, node160, node170;

Node node180, node190;



void resetNode(Node* node, int value){

  node->data = value;

  node->balanceFactor = 0;

  node->left = ((void *)0);

  node->right = ((void *)0);

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



void test_avlAdd_(void){

 avlAdd(&node10, &node20);

  UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((node10.right->data)), (((void *)0)), (_U_UINT)42, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((-1)), (_U_SINT)((node10.balanceFactor)), (((void *)0)), (_U_UINT)43, UNITY_DISPLAY_STYLE_INT);

}
