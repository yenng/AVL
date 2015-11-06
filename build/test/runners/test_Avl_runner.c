/* AUTOGENERATED FILE. DO NOT EDIT. */

//=======Test Runner Used To Run Each Test Below=====
#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  if (TEST_PROTECT()) \
  { \
      setUp(); \
      TestFunc(); \
  } \
  if (TEST_PROTECT() && !TEST_IS_IGNORED) \
  { \
    tearDown(); \
  } \
  UnityConcludeTest(); \
}

//=======Automagically Detected Files To Include=====
#include "unity.h"
#include <setjmp.h>
#include <stdio.h>

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

//=======External Functions This Runner Calls=====
extern void setUp(void);
extern void tearDown(void);
extern void test_avlAdd(void);
extern void test_avlAdd_twice(void);
extern void test_avlAdd_node_to_tree_with_1_branch(void);
extern void test_single_rotation_with_avlAdd(void);
extern void test_single_rotation_with_avlAdd_and_add_node(void);
extern void test_add_a_node_and_double_rotation_the_tree_by_using_avlAdd_function(void);
extern void test_double_rotation_the_tree_by_using_avlAdd_function(void);
extern void test_avlRemove(void);
extern void test_avlremove_smaller_node_from_tree(void);
extern void test_avlremove_larger_node_from_tree(void);


//=======Test Reset Option=====
void resetTest(void);
void resetTest(void)
{
  tearDown();
  setUp();
}


//=======MAIN=====
int main(void)
{
  UnityBegin("test_Avl.c");
  RUN_TEST(test_avlAdd, 43);
  RUN_TEST(test_avlAdd_twice, 53);
  RUN_TEST(test_avlAdd_node_to_tree_with_1_branch, 67);
  RUN_TEST(test_single_rotation_with_avlAdd, 85);
  RUN_TEST(test_single_rotation_with_avlAdd_and_add_node, 103);
  RUN_TEST(test_add_a_node_and_double_rotation_the_tree_by_using_avlAdd_function, 123);
  RUN_TEST(test_double_rotation_the_tree_by_using_avlAdd_function, 174);
  RUN_TEST(test_avlRemove, 223);
  RUN_TEST(test_avlremove_smaller_node_from_tree, 231);
  RUN_TEST(test_avlremove_larger_node_from_tree, 249);

  return (UnityEnd());
}
