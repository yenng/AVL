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



void test_create_a_large_tree_by_using_avlAdd(void){

  Node* tree = &node30;

  int i = avlAdd(&tree,&node20);

  i = avlAdd(&tree,&node50);

  i = avlAdd(&tree,&node10);

  i = avlAdd(&tree,&node40);

  i = avlAdd(&tree,&node80);

  i = avlAdd(&tree,&node60);

  i = avlAdd(&tree,&node100);



  UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((tree->data)), (((void *)0)), (_U_UINT)77, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((tree->balanceFactor)), (((void *)0)), (_U_UINT)78, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((tree->left->data)), (((void *)0)), (_U_UINT)79, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((-1)), (_U_SINT)((tree->left->balanceFactor)), (((void *)0)), (_U_UINT)80, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((10)), (_U_SINT)((tree->left->left->data)), (((void *)0)), (_U_UINT)81, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((tree->left->left->balanceFactor)), (((void *)0)), (_U_UINT)82, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((50)), (_U_SINT)((tree->right->data)), (((void *)0)), (_U_UINT)83, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((tree->right->balanceFactor)), (((void *)0)), (_U_UINT)84, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((80)), (_U_SINT)((tree->right->right->data)), (((void *)0)), (_U_UINT)85, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((tree->right->right->balanceFactor)), (((void *)0)), (_U_UINT)86, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((40)), (_U_SINT)((tree->right->left->data)), (((void *)0)), (_U_UINT)87, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((tree->right->left->balanceFactor)), (((void *)0)), (_U_UINT)88, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((100)), (_U_SINT)((tree->right->right->right->data)), (((void *)0)), (_U_UINT)89, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((tree->right->right->right->balanceFactor)), (((void *)0)), (_U_UINT)90, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((60)), (_U_SINT)((tree->right->right->left->data)), (((void *)0)), (_U_UINT)91, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((tree->right->right->left->balanceFactor)), (((void *)0)), (_U_UINT)92, UNITY_DISPLAY_STYLE_INT);





}

void test_avlAdd_node_to_tree_with_1_branch(void){



  Node* node = malloc(sizeof(Node));



 node = (Node*)createNode(-1, 30);

  node->left = (Node*)createNode(0,20);



 int i;

  i = avlAdd(&node, &node40);



  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((node->balanceFactor)), (((void *)0)), (_U_UINT)106, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((node->data)), (((void *)0)), (_U_UINT)107, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((node->left->balanceFactor)), (((void *)0)), (_U_UINT)108, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((node->left->data)), (((void *)0)), (_U_UINT)109, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((node->right->balanceFactor)), (((void *)0)), (_U_UINT)110, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((40)), (_U_SINT)((node->right->data)), (((void *)0)), (_U_UINT)111, UNITY_DISPLAY_STYLE_INT);

}



void test_single_rotation_with_avlAdd(void){



  Node* node = malloc(sizeof(Node));



 node = (Node*)createNode(2, 30);

  node->right = (Node*)createNode(1,40);

  node->right->right = (Node*)createNode(0,50);



  int i = avlAdd(&node, ((void *)0));



  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((node->balanceFactor)), (((void *)0)), (_U_UINT)124, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((40)), (_U_SINT)((node->data)), (((void *)0)), (_U_UINT)125, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((node->left->balanceFactor)), (((void *)0)), (_U_UINT)126, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((node->left->data)), (((void *)0)), (_U_UINT)127, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((node->right->balanceFactor)), (((void *)0)), (_U_UINT)128, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((50)), (_U_SINT)((node->right->data)), (((void *)0)), (_U_UINT)129, UNITY_DISPLAY_STYLE_INT);

}



void test_single_rotation_with_avlAdd_and_add_node(void){



  Node* node = malloc(sizeof(Node));



 node = (Node*)createNode(2, 30);

  node->right = (Node*)createNode(1,40);

  node->right->right = (Node*)createNode(0,50);



  int i = avlAdd(&node, &node20);



  UnityAssertEqualNumber((_U_SINT)((-1)), (_U_SINT)((node->balanceFactor)), (((void *)0)), (_U_UINT)142, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((40)), (_U_SINT)((node->data)), (((void *)0)), (_U_UINT)143, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((-1)), (_U_SINT)((node->left->balanceFactor)), (((void *)0)), (_U_UINT)144, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((node->left->data)), (((void *)0)), (_U_UINT)145, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((node->left->left->balanceFactor)), (((void *)0)), (_U_UINT)146, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((node->left->left->data)), (((void *)0)), (_U_UINT)147, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((node->right->balanceFactor)), (((void *)0)), (_U_UINT)148, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((50)), (_U_SINT)((node->right->data)), (((void *)0)), (_U_UINT)149, UNITY_DISPLAY_STYLE_INT);

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





  UnityAssertEqualNumber((_U_SINT)((50)), (_U_SINT)((node1->data)), (((void *)0)), (_U_UINT)179, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((node1->balanceFactor)), (((void *)0)), (_U_UINT)180, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((node1->left->data)), (((void *)0)), (_U_UINT)181, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((-1)), (_U_SINT)((node1->left->balanceFactor)), (((void *)0)), (_U_UINT)182, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((node1->left->left->data)), (((void *)0)), (_U_UINT)183, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((-1)), (_U_SINT)((node1->left->left->balanceFactor)), (((void *)0)), (_U_UINT)184, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((40)), (_U_SINT)((node1->left->right->data)), (((void *)0)), (_U_UINT)185, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((node1->left->right->balanceFactor)), (((void *)0)), (_U_UINT)186, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((80)), (_U_SINT)((node1->right->data)), (((void *)0)), (_U_UINT)187, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((node1->right->balanceFactor)), (((void *)0)), (_U_UINT)188, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((60)), (_U_SINT)((nodeBranch1->data)), (((void *)0)), (_U_UINT)189, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((nodeBranch1->balanceFactor)), (((void *)0)), (_U_UINT)190, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((100)), (_U_SINT)((nodeBranch2->data)), (((void *)0)), (_U_UINT)191, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((nodeBranch2->balanceFactor)), (((void *)0)), (_U_UINT)192, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((70)), (_U_SINT)((nodeBranch1->right->data)), (((void *)0)), (_U_UINT)193, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((nodeBranch1->right->balanceFactor)), (((void *)0)), (_U_UINT)194, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((90)), (_U_SINT)((nodeBranch2->left->data)), (((void *)0)), (_U_UINT)195, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((nodeBranch2->left->balanceFactor)), (((void *)0)), (_U_UINT)196, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((10)), (_U_SINT)((nodeBranch3->left->data)), (((void *)0)), (_U_UINT)197, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((nodeBranch3->left->balanceFactor)), (((void *)0)), (_U_UINT)198, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((110)), (_U_SINT)((nodeBranch2->right->data)), (((void *)0)), (_U_UINT)199, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((nodeBranch2->right->balanceFactor)), (((void *)0)), (_U_UINT)200, UNITY_DISPLAY_STYLE_INT);

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





  UnityAssertEqualNumber((_U_SINT)((50)), (_U_SINT)((node1->data)), (((void *)0)), (_U_UINT)230, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((node1->balanceFactor)), (((void *)0)), (_U_UINT)231, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((node1->left->data)), (((void *)0)), (_U_UINT)232, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((-1)), (_U_SINT)((node1->left->balanceFactor)), (((void *)0)), (_U_UINT)233, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((node1->left->left->data)), (((void *)0)), (_U_UINT)234, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((-1)), (_U_SINT)((node1->left->left->balanceFactor)), (((void *)0)), (_U_UINT)235, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((40)), (_U_SINT)((node1->left->right->data)), (((void *)0)), (_U_UINT)236, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((node1->left->right->balanceFactor)), (((void *)0)), (_U_UINT)237, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((80)), (_U_SINT)((node1->right->data)), (((void *)0)), (_U_UINT)238, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((node1->right->balanceFactor)), (((void *)0)), (_U_UINT)239, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((60)), (_U_SINT)((nodeBranch1->data)), (((void *)0)), (_U_UINT)240, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((nodeBranch1->balanceFactor)), (((void *)0)), (_U_UINT)241, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((100)), (_U_SINT)((nodeBranch2->data)), (((void *)0)), (_U_UINT)242, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((-1)), (_U_SINT)((nodeBranch2->balanceFactor)), (((void *)0)), (_U_UINT)243, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((70)), (_U_SINT)((nodeBranch1->right->data)), (((void *)0)), (_U_UINT)244, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((nodeBranch1->right->balanceFactor)), (((void *)0)), (_U_UINT)245, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((90)), (_U_SINT)((nodeBranch2->left->data)), (((void *)0)), (_U_UINT)246, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((nodeBranch2->left->balanceFactor)), (((void *)0)), (_U_UINT)247, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((10)), (_U_SINT)((nodeBranch3->left->data)), (((void *)0)), (_U_UINT)248, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((nodeBranch3->left->balanceFactor)), (((void *)0)), (_U_UINT)249, UNITY_DISPLAY_STYLE_INT);

}
