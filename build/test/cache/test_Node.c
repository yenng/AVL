#include "Node.h"
#include "unity.h"




void setUp(void)

{

}



void tearDown(void)

{

}



void test_module_create_node(void)

{



  Node* node1 = malloc(sizeof(Node));



 node1 = (Node*)createNode(1, 60);



  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((node1->balanceFactor)), (((void *)0)), (_U_UINT)21, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((60)), (_U_SINT)((node1->data)), (((void *)0)), (_U_UINT)22, UNITY_DISPLAY_STYLE_INT);

}



void test_create_node_tree_with_2_branches(void)

{



 Node* node1 = malloc(sizeof(Node));



 node1 = (Node*)createNode(2, 60);

  node1->left = (Node*)createNode(1,50);

  node1->right = (Node*)createNode(1,70);



  UnityAssertEqualNumber((_U_SINT)((60)), (_U_SINT)((node1->data)), (((void *)0)), (_U_UINT)34, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((50)), (_U_SINT)((node1->left->data)), (((void *)0)), (_U_UINT)35, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((70)), (_U_SINT)((node1->right->data)), (((void *)0)), (_U_UINT)36, UNITY_DISPLAY_STYLE_INT);

}



void test_create_tree_for_double_rotation(void){



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



  UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((node1->data)), (((void *)0)), (_U_UINT)60, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((node1->left->data)), (((void *)0)), (_U_UINT)61, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((10)), (_U_SINT)((node1->left->left->data)), (((void *)0)), (_U_UINT)62, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((80)), (_U_SINT)((node1->right->data)), (((void *)0)), (_U_UINT)63, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((50)), (_U_SINT)((nodeBranch1->data)), (((void *)0)), (_U_UINT)64, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((100)), (_U_SINT)((nodeBranch2->data)), (((void *)0)), (_U_UINT)65, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((40)), (_U_SINT)((nodeBranch1->left->data)), (((void *)0)), (_U_UINT)66, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((60)), (_U_SINT)((nodeBranch1->right->data)), (((void *)0)), (_U_UINT)67, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((70)), (_U_SINT)((nodeBranch1->right->right->data)), (((void *)0)), (_U_UINT)68, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((90)), (_U_SINT)((nodeBranch2->left->data)), (((void *)0)), (_U_UINT)69, UNITY_DISPLAY_STYLE_INT);

}
