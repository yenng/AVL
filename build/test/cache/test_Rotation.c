#include "Node.h"
#include "Rotation.h"
#include "unity.h"




void setUp(void)

{

}



void tearDown(void)

{

}



void test_right_rotate_node_tree_with_2_branches(void)

{



 Node* node1 = malloc(sizeof(Node));

 node1 = (Node*)createNode(2, 70);

  node1->left = (Node*)createNode(1,50);

  node1->left->right = (Node*)createNode(1,60);



  node1 = rightRotation(node1);



  UnityAssertEqualNumber((_U_SINT)((50)), (_U_SINT)((node1->data)), (((void *)0)), (_U_UINT)25, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((70)), (_U_SINT)((node1->right->data)), (((void *)0)), (_U_UINT)26, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((60)), (_U_SINT)((node1->right->left->data)), (((void *)0)), (_U_UINT)27, UNITY_DISPLAY_STYLE_INT);

}



void test_left_rotate_node_tree_with_2_branches(void)

{



 Node* node1 = malloc(sizeof(Node));

 node1 = (Node*)createNode(2, 50);

  node1->right = (Node*)createNode(1,70);

  node1->right->left = (Node*)createNode(1,60);



  node1 = leftRotation(node1);



  UnityAssertEqualNumber((_U_SINT)((70)), (_U_SINT)((node1->data)), (((void *)0)), (_U_UINT)40, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((50)), (_U_SINT)((node1->left->data)), (((void *)0)), (_U_UINT)41, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((60)), (_U_SINT)((node1->left->right->data)), (((void *)0)), (_U_UINT)42, UNITY_DISPLAY_STYLE_INT);

}



void test_double_rotation_the_tree(void){



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



  rightLeftRotation(&node1);

  nodeBranch1 = node1->right->left;

  nodeBranch2 = node1->right->right;

  Node* nodeBranch3 = node1->left->left;





  UnityAssertEqualNumber((_U_SINT)((50)), (_U_SINT)((node1->data)), (((void *)0)), (_U_UINT)72, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((node1->left->data)), (((void *)0)), (_U_UINT)73, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((node1->left->left->data)), (((void *)0)), (_U_UINT)74, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((40)), (_U_SINT)((node1->left->right->data)), (((void *)0)), (_U_UINT)75, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((80)), (_U_SINT)((node1->right->data)), (((void *)0)), (_U_UINT)76, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((60)), (_U_SINT)((nodeBranch1->data)), (((void *)0)), (_U_UINT)77, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((100)), (_U_SINT)((nodeBranch2->data)), (((void *)0)), (_U_UINT)78, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((70)), (_U_SINT)((nodeBranch1->right->data)), (((void *)0)), (_U_UINT)79, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((90)), (_U_SINT)((nodeBranch2->left->data)), (((void *)0)), (_U_UINT)80, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((10)), (_U_SINT)((nodeBranch3->left->data)), (((void *)0)), (_U_UINT)81, UNITY_DISPLAY_STYLE_INT);

}
