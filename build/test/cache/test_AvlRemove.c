#include "Rotation.h"
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













void test_avlRemove(void){

  Node* x = &node10;

  int *heightChange;

  Node* removedNode = avlRemove(&x, 10, heightChange);

  if ((((x)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)52);;};

  UnityAssertEqualNumber((_U_SINT)((10)), (_U_SINT)((removedNode->data)), (((void *)0)), (_U_UINT)53, UNITY_DISPLAY_STYLE_INT);

}

void test_avlremove_left_node_from_tree(void){



  Node* node = malloc(sizeof(Node));

  int *heightChange;



 node = (Node*)createNode(0, 30);

  node->left = (Node*)createNode(0,20);

  node->right = (Node*)createNode(0,40);



 Node *removedNode = avlRemove(&node, 20, heightChange);



  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((node->balanceFactor)), (((void *)0)), (_U_UINT)76, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((node->data)), (((void *)0)), (_U_UINT)77, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((node->right->balanceFactor)), (((void *)0)), (_U_UINT)78, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((40)), (_U_SINT)((node->right->data)), (((void *)0)), (_U_UINT)79, UNITY_DISPLAY_STYLE_INT);

  if ((((node->left)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)80);;};

  UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)(((int)(removedNode->data))), (((void *)0)), (_U_UINT)81, UNITY_DISPLAY_STYLE_INT);

}

void test_avlremove_right_node_from_tree(void){



  Node* node = malloc(sizeof(Node));

  int *heightChange;



 node = (Node*)createNode(0, 30);

  node->left = (Node*)createNode(0,20);

  node->right = (Node*)createNode(0,40);



 Node *removedNode = avlRemove(&node, 40, heightChange);



  UnityAssertEqualNumber((_U_SINT)((-1)), (_U_SINT)((node->balanceFactor)), (((void *)0)), (_U_UINT)105, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((node->data)), (((void *)0)), (_U_UINT)106, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((node->left->balanceFactor)), (((void *)0)), (_U_UINT)107, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((node->left->data)), (((void *)0)), (_U_UINT)108, UNITY_DISPLAY_STYLE_INT);

  if ((((node->right)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)109);;};

  UnityAssertEqualNumber((_U_SINT)((40)), (_U_SINT)(((int)(removedNode->data))), (((void *)0)), (_U_UINT)110, UNITY_DISPLAY_STYLE_INT);

}



void test_avlremove_with_single_rotation(void){

  Node* node = &node30;

  int i = avlAdd(&node,&node50);

  i = avlAdd(&node,&node70);

  int *heightChange = 0;

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((node->balanceFactor)), (((void *)0)), (_U_UINT)118, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((node->data)), (((void *)0)), (_U_UINT)119, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((node->right->balanceFactor)), (((void *)0)), (_U_UINT)120, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((50)), (_U_SINT)((node->right->data)), (((void *)0)), (_U_UINT)121, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((node->right->right->balanceFactor)), (((void *)0)), (_U_UINT)122, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((70)), (_U_SINT)((node->right->right->data)), (((void *)0)), (_U_UINT)123, UNITY_DISPLAY_STYLE_INT);

  if ((((node->left)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)124);;};

 Node *removedNode = avlRemove(&node, 30, heightChange);





}
