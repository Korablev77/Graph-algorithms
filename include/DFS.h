#ifndef DFS_H
#define DFS_H

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "Graph.h"


typedef struct Stack {
	size_t currentSize;
	size_t maxSize;
	int* elems;
}Stack;

Stack* createStack(int maxSize);

int pushStack(Stack* stack, int elemToAdd);

int isEmptyStack(Stack* stack);

int popStack(Stack* stack);

int destructStack(Stack* stack);

void DFS(Graph* graph, int currentNode);

void stackDFS(Graph* graph, int startingNode);


#endif
