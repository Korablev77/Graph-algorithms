
#include <stdio.h>
#include <stdlib.h>

#include "include/Graph.h"
#include "include/DFS.h"
#include "include/BFS.h"

#ifndef PASSED
#define PASSED 777
#endif
#ifndef FAILED
#define FAILED -666
#endif

unsigned TEST_STATUS;

//#ifndef TEST
#define TEST(testName) void testName ## Test() ; \
  void testName() { \
    printf("Running test: %s\n", #testName); \
      TEST_STATUS = PASSED; \
      testName ## Test(); \
      if (PASSED == TEST_STATUS) { \
      	fprintf(stderr, "%s\n", "Test passed."); \
      } else { \
      	fprintf(stderr, "%s\n", "Test failed!"); \
      } \
  } \
  void testName ## Test()
//#endif

#ifndef ASSERT_EQUAL
#define ASSERT_EQUAL(first, second) do { \
  if (first != second) { \
    fprintf(stderr, "Required equal failed: %s != %s <---> %d != %d\n TEST: %s, At line: %d", \
    #first, #second, first, second, __FUNCTION__, __LINE__); \
    TEST_STATUS = FAILED; \
  } \
}while (0)
#endif




TEST(StackAll) {
	Stack* stack = createStack(32);
	pushStack(stack, 0);
	pushStack(stack, 3);
	pushStack(stack, 4);
	ASSERT_EQUAL(4, popStack(stack));
	ASSERT_EQUAL(3, popStack(stack));
	pushStack(stack, 5);
	ASSERT_EQUAL(5, popStack(stack));
	ASSERT_EQUAL(1, destructStack(stack));
}

TEST(QueueAll) {

	Queue* queue = createQueue(3);
	pushQueue(queue,1);
	pushQueue(queue,2);
	pushQueue(queue,3);
	ASSERT_EQUAL(1, popQueue(queue));
	ASSERT_EQUAL(2, popQueue(queue));
	pushQueue(queue, 4);
	ASSERT_EQUAL(3, popQueue(queue));
	ASSERT_EQUAL(1, destructQueue(queue));
}

TEST(DFS_) {
	Graph* graph = createGraph(5);
	initGraph(graph);
	printGraph(graph);
	DFS(graph, 0);
	destructGraph(graph);
}

TEST(BFS_) {
	Graph* graph = createGraph(5);
	initGraph(graph);
	printGraph(graph);
	BFS(graph, 0);
	destructGraph(graph);
}




int runTests() {

    StackAll();
    QueueAll();
    DFS_();
    BFS_();
 	return 0;
}


#define TEST_MODE

int main() {
  #ifdef TEST_MODE
	fprintf(stderr, "%s\n", "Running all tests...");
    return runTests();
  #endif

    return 0;
}



/*int main(int argc, char const *argv[])
{


	Graph* graph = createGraph(5);
	initGraph(graph);
	printGraph(graph);
	stackDFS(graph, 0);
	destructGraph(graph);
	return 0;
}*/
