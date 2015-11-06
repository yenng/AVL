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



void test_avlAdd(void){

  Node* x = &node10;

 int i;

  i = avlAdd(&x, &node20);



  UnityAssertEqualNumber((_U_SINT)((10)), (_U_SINT)((x->data)), (((void *)0)), (_U_UINT)48, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((x->balanceFactor)), (((void *)0)), (_U_UINT)49, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((x->right->data)), (((void *)0)), (_U_UINT)50, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((x->right->balanceFactor)), (((void *)0)), (_U_UINT)51, UNITY_DISPLAY_STYLE_INT);

}

void test_avlAdd_twice(void){

  Node* x = &node30;

 int i;

  i = avlAdd(&x, &node20);

  i = avlAdd(&x, &node40);



  UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((x->data)), (((void *)0)), (_U_UINT)59, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((x->balanceFactor)), (((void *)0)), (_U_UINT)60, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((x->left->data)), (((void *)0)), (_U_UINT)61, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((x->left->balanceFactor)), (((void *)0)), (_U_UINT)62, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((40)), (_U_SINT)((x->right->data)), (((void *)0)), (_U_UINT)63, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((x->right->balanceFactor)), (((void *)0)), (_U_UINT)64, UNITY_DISPLAY_STYLE_INT);

}



void test_avlAdd_node_to_tree_with_1_branch(void){



  Node* node = malloc(sizeof(Node));



 node = (Node*)createNode(-1, 30);

  node->left = (Node*)createNode(0,20);



 int i;

  i = avlAdd(&node, &node40);



  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((node->balanceFactor)), (((void *)0)), (_U_UINT)77, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((node->data)), (((void *)0)), (_U_UINT)78, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((node->left->balanceFactor)), (((void *)0)), (_U_UINT)79, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((node->left->data)), (((void *)0)), (_U_UINT)80, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((node->right->balanceFactor)), (((void *)0)), (_U_UINT)81, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((40)), (_U_SINT)((node->right->data)), (((void *)0)), (_U_UINT)82, UNITY_DISPLAY_STYLE_INT);

}



void test_single_rotation_with_avlAdd(void){



  Node* node = malloc(sizeof(Node));



 node = (Node*)createNode(2, 30);

  node->right = (Node*)createNode(1,40);

  node->right->right = (Node*)createNode(0,50);



  int i = avlAdd(&node, ((void *)0));



  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((node->balanceFactor)), (((void *)0)), (_U_UINT)95, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((40)), (_U_SINT)((node->data)), (((void *)0)), (_U_UINT)96, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((node->left->balanceFactor)), (((void *)0)), (_U_UINT)97, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((node->left->data)), (((void *)0)), (_U_UINT)98, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((node->right->balanceFactor)), (((void *)0)), (_U_UINT)99, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((50)), (_U_SINT)((node->right->data)), (((void *)0)), (_U_UINT)100, UNITY_DISPLAY_STYLE_INT);

}



void test_single_rotation_with_avlAdd_and_add_node(void){



  Node* node = malloc(sizeof(Node));



 node = (Node*)createNode(2, 30);

  node->right = (Node*)createNode(1,40);

  node->right->right = (Node*)createNode(0,50);



  int i = avlAdd(&node, &node20);



  UnityAssertEqualNumber((_U_SINT)((-1)), (_U_SINT)((node->balanceFactor)), (((void *)0)), (_U_UINT)113, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((40)), (_U_SINT)((node->data)), (((void *)0)), (_U_UINT)114, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((-1)), (_U_SINT)((node->left->balanceFactor)), (((void *)0)), (_U_UINT)115, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((node->left->data)), (((void *)0)), (_U_UINT)116, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((node->left->left->balanceFactor)), (((void *)0)), (_U_UINT)117, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((node->left->left->data)), (((void *)0)), (_U_UINT)118, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((node->right->balanceFactor)), (((void *)0)), (_U_UINT)119, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((50)), (_U_SINT)((node->right->data)), (((void *)0)), (_U_UINT)120, UNITY_DISPLAY_STYLE_INT);

}



void test_add_a_node_and_double_rotation_the_tree_by_using_avlAdd_function(void){



  Node* node1 = malloc(sizeof(Node));



 node1 = (Node*)createNode(2, 30);

  node1->left = (Node*)createNode(-1,20);

  node1->left->left = (Node*)createNode(0,10);

  node1->right = (Node*)createNode(-1,80);

  node1->right->left = (Node*)createNode(1,50);

  node1->right->right = (Node*)createNode(-1,100);





  Node* nodeBranch1 = node1->right->left;

  Node* nodeBranch2 = node1->right->right;





  nodeBranch1->left = (Node*)createNode(0,40);

  nodeBranch1->right = (Node*)createNode(1,60);

  nodeBranch1->right->right = (Node*)createNode(0,70);

  nodeBranch2->left = (Node*)createNode(0,90);

  int i;

  i = avlAdd(&node1, &node110);

  nodeBranch1 = node1->right->left;

  nodeBranch2 = node1->right->right;

  Node* nodeBranch3 = node1->left->left;





  UnityAssertEqualNumber((_U_SINT)((50)), (_U_SINT)((node1->data)), (((void *)0)), (_U_UINT)150, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((node1->balanceFactor)), (((void *)0)), (_U_UINT)151, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((node1->left->data)), (((void *)0)), (_U_UINT)152, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((-1)), (_U_SINT)((node1->left->balanceFactor)), (((void *)0)), (_U_UINT)153, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((node1->left->left->data)), (((void *)0)), (_U_UINT)154, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((-1)), (_U_SINT)((node1->left->left->balanceFactor)), (((void *)0)), (_U_UINT)155, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((40)), (_U_SINT)((node1->left->right->data)), (((void *)0)), (_U_UINT)156, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((node1->left->right->balanceFactor)), (((void *)0)), (_U_UINT)157, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((80)), (_U_SINT)((node1->right->data)), (((void *)0)), (_U_UINT)158, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((node1->right->balanceFactor)), (((void *)0)), (_U_UINT)159, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((60)), (_U_SINT)((nodeBranch1->data)), (((void *)0)), (_U_UINT)160, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((nodeBranch1->balanceFactor)), (((void *)0)), (_U_UINT)161, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((100)), (_U_SINT)((nodeBranch2->data)), (((void *)0)), (_U_UINT)162, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((nodeBranch2->balanceFactor)), (((void *)0)), (_U_UINT)163, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((70)), (_U_SINT)((nodeBranch1->right->data)), (((void *)0)), (_U_UINT)164, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((nodeBranch1->right->balanceFactor)), (((void *)0)), (_U_UINT)165, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((90)), (_U_SINT)((nodeBranch2->left->data)), (((void *)0)), (_U_UINT)166, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((nodeBranch2->left->balanceFactor)), (((void *)0)), (_U_UINT)167, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((10)), (_U_SINT)((nodeBranch3->left->data)), (((void *)0)), (_U_UINT)168, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((nodeBranch3->left->balanceFactor)), (((void *)0)), (_U_UINT)169, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((110)), (_U_SINT)((nodeBranch2->right->data)), (((void *)0)), (_U_UINT)170, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((nodeBranch2->right->balanceFactor)), (((void *)0)), (_U_UINT)171, UNITY_DISPLAY_STYLE_INT);

}



void test_double_rotation_the_tree_by_using_avlAdd_function(void){



  Node* node1 = malloc(sizeof(Node));



 node1 = (Node*)createNode(2, 30);

  node1->left = (Node*)createNode(-1,20);

  node1->left->left = (Node*)createNode(0,10);

  node1->right = (Node*)createNode(-1,80);

  node1->right->left = (Node*)createNode(1,50);

  node1->right->right = (Node*)createNode(-1,100);





  Node* nodeBranch1 = node1->right->left;

  Node* nodeBranch2 = node1->right->right;





  nodeBranch1->left = (Node*)createNode(0,40);

  nodeBranch1->right = (Node*)createNode(1,60);

  nodeBranch1->right->right = (Node*)createNode(0,70);

  nodeBranch2->left = (Node*)createNode(0,90);

  int i;

  i = avlAdd(&node1, ((void *)0));

  nodeBranch1 = node1->right->left;

  nodeBranch2 = node1->right->right;

  Node* nodeBranch3 = node1->left->left;





  UnityAssertEqualNumber((_U_SINT)((50)), (_U_SINT)((node1->data)), (((void *)0)), (_U_UINT)201, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((node1->balanceFactor)), (((void *)0)), (_U_UINT)202, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((node1->left->data)), (((void *)0)), (_U_UINT)203, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((-1)), (_U_SINT)((node1->left->balanceFactor)), (((void *)0)), (_U_UINT)204, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((node1->left->left->data)), (((void *)0)), (_U_UINT)205, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((-1)), (_U_SINT)((node1->left->left->balanceFactor)), (((void *)0)), (_U_UINT)206, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((40)), (_U_SINT)((node1->left->right->data)), (((void *)0)), (_U_UINT)207, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((node1->left->right->balanceFactor)), (((void *)0)), (_U_UINT)208, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((80)), (_U_SINT)((node1->right->data)), (((void *)0)), (_U_UINT)209, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((node1->right->balanceFactor)), (((void *)0)), (_U_UINT)210, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((60)), (_U_SINT)((nodeBranch1->data)), (((void *)0)), (_U_UINT)211, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((nodeBranch1->balanceFactor)), (((void *)0)), (_U_UINT)212, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((100)), (_U_SINT)((nodeBranch2->data)), (((void *)0)), (_U_UINT)213, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((-1)), (_U_SINT)((nodeBranch2->balanceFactor)), (((void *)0)), (_U_UINT)214, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((70)), (_U_SINT)((nodeBranch1->right->data)), (((void *)0)), (_U_UINT)215, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((nodeBranch1->right->balanceFactor)), (((void *)0)), (_U_UINT)216, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((90)), (_U_SINT)((nodeBranch2->left->data)), (((void *)0)), (_U_UINT)217, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((nodeBranch2->left->balanceFactor)), (((void *)0)), (_U_UINT)218, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((10)), (_U_SINT)((nodeBranch3->left->data)), (((void *)0)), (_U_UINT)219, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((nodeBranch3->left->balanceFactor)), (((void *)0)), (_U_UINT)220, UNITY_DISPLAY_STYLE_INT);

}



void test_avlRemove(void){

  Node* x = &node10;

  Node* removedNode = avlRemove(&x, 10);



  if ((((x)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)227);;};

  UnityAssertEqualNumber((_U_SINT)((10)), (_U_SINT)((removedNode->data)), (((void *)0)), (_U_UINT)228, UNITY_DISPLAY_STYLE_INT);

}



void test_avlremove_smaller_node_from_tree(void){



  Node* node = malloc(sizeof(Node));



 node = (Node*)createNode(0, 30);

  node->left = (Node*)createNode(0,20);

  node->right = (Node*)createNode(0,40);



 Node *removedNode = avlRemove(&node, 20);



  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((node->balanceFactor)), (((void *)0)), (_U_UINT)241, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((node->data)), (((void *)0)), (_U_UINT)242, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((node->right->balanceFactor)), (((void *)0)), (_U_UINT)243, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((40)), (_U_SINT)((node->right->data)), (((void *)0)), (_U_UINT)244, UNITY_DISPLAY_STYLE_INT);

  if ((((node->left)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)245);;};

  UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)(((int)(removedNode->data))), (((void *)0)), (_U_UINT)246, UNITY_DISPLAY_STYLE_INT);

}



void test_avlremove_larger_node_from_tree(void){



  Node* node = malloc(sizeof(Node));



 node = (Node*)createNode(0, 30);

  node->left = (Node*)createNode(0,20);

  node->right = (Node*)createNode(0,40);



 Node *removedNode = avlRemove(&node, 40);



  UnityAssertEqualNumber((_U_SINT)((-1)), (_U_SINT)((node->balanceFactor)), (((void *)0)), (_U_UINT)259, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((node->data)), (((void *)0)), (_U_UINT)260, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((node->left->balanceFactor)), (((void *)0)), (_U_UINT)261, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((node->left->data)), (((void *)0)), (_U_UINT)262, UNITY_DISPLAY_STYLE_INT);

  if ((((node->right)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)263);;};

  UnityAssertEqualNumber((_U_SINT)((40)), (_U_SINT)(((int)(removedNode->data))), (((void *)0)), (_U_UINT)264, UNITY_DISPLAY_STYLE_INT);

}
