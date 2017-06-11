#ifndef BFS_H
#define BFS_H

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "Graph.h"

typedef struct Queue {
	size_t currentSize;
	size_t maxSize;
	size_t head;
	int* elems;
}Queue;


Queue* createQueue(int maxSize);

int pushQueue(Queue* queue, int elemToAdd);

int isEmptyQueue(Queue* queue);

int popQueue(Queue* queue);

int destructQueue(Queue* queue);

void BFS(Graph* graph, int startingNode);


#endif
