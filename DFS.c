
#include "include/DFS.h"



Stack* createStack(int maxSize) {
	assert((0 < maxSize) && "Couldn't create stack with negative size.");
	Stack* stack = (Stack*)calloc(1, sizeof(Stack));
	stack->currentSize = 0;
	stack->maxSize = maxSize;
	stack->elems = (int*)calloc(maxSize, sizeof(int));

	return stack;
}

int pushStack(Stack* stack, int elemToAdd) {
	assert((NULL != stack) && "Couldn't push to null-stack.");

	if (stack->currentSize == stack->maxSize) {
		fprintf(stderr, "%s\n", "Failed to push to stack: has reached maximum size.");
		return -1;
	}

	stack->elems[stack->currentSize++] = elemToAdd;
	return 1;
}

int isEmptyStack(Stack* stack) {
	assert((NULL != stack) && "Couldn't check for emptiness null-stack.");

	return (stack->currentSize > 0);
}

int popStack(Stack* stack) {
	assert((NULL != stack) && "Couldn't pop from null-stack.");
	if (isEmptyStack(stack)) 
		stack->currentSize--;
		return stack->elems[stack->currentSize];


	fprintf(stderr, "%s\n", "Couldn't pop from empty stack.");
	return -1;
}

int destructStack(Stack* stack) {
	if (NULL == stack) {
		fprintf(stderr, "%s\n", "Attempt at destroing null-stack.");
		return -1;
	}

	free(stack->elems);
	stack->currentSize = 0;
	stack->maxSize = 0;
	free(stack);
	return 1;
}


void DFS(Graph* graph, int currentNode) {
	assert((NULL != graph) && "Couldn't DFS null-graph");

	printf("Processing %d node\n", currentNode);

	graph->nodes[currentNode].color = GREY;

	for (int i = 0; i < graph->size; ++i) {
		if (i == currentNode) continue;
		if (graph->adjacencyMatrix->matrix[currentNode][i] == 1) {
			switch (graph->nodes[i].color) {
				case WHITE:
					DFS(graph, i);
					break;
				case GREY: 
					printf("%s Backedge is: %d --> %d\n", "Cycle detected!", currentNode, i);
					break;
				case BLACK:
					printf("Node %d has been already processed. Crossedge is %d --> %d\n",  i, i, currentNode);
					break;
				default:
					printf("%s\n", "Unknown node color!");
					break;
			}
		}
	}

	graph->nodes[currentNode].color = BLACK;
}

void stackDFS(Graph* graph, int startingNode) {
	assert((NULL != graph) && "Couldn't DFS null-graph");

	printf("Starting DFS from %d node\n", startingNode);

	Stack* stack = createStack(32);
	pushStack(stack, startingNode);

	while (isEmptyStack(stack)) {
		int currentNode = popStack(stack);
		printf("Processing %d node\n", currentNode);
		graph->nodes[currentNode].color = GREY;
		for (int i = 0; i < graph->size; ++i) {
			if (i == currentNode) continue;
			if (graph->adjacencyMatrix->matrix[currentNode][i] == 1) {
				switch (graph->nodes[i].color) {
					case WHITE: 
						pushStack(stack, i);
						break;
					case GREY:
						printf("%s Backedge is: %d --> %d\n", "Cycle detected!", currentNode, i);
						break;
					case BLACK:
						printf("%s %d %s\n", "Node", i ,"has been already processed.");
						break;
					default:
						printf("%s\n", "Unknown node color!");
						break;
				}
			}
			graph->nodes[currentNode].color = BLACK;	

		}
	}
	destructStack(stack);
}









