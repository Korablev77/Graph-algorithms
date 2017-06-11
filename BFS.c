
#include "include/BFS.h"


Queue* createQueue(int maxSize) {
	assert((0 < maxSize) && "Couldn't create queue with negative size.");

	Queue* queue = (Queue*)calloc(1, sizeof(Queue));
	queue->currentSize = 0;
	queue->head = 0;
	queue->maxSize = maxSize;
	queue->elems = (int*)calloc(maxSize, sizeof(int));
	return queue;
}

int pushQueue(Queue* queue, int elemToAdd) {
	assert((NULL != queue) && "Couldn't push to null-queue.");

	if (queue->currentSize == queue->maxSize) {
		if (queue->head > 0) {
			printf("%s\n", "Shifting queue...");
			for (int i = 0; i < queue->currentSize; ++i) {
				queue->elems[i] = queue->elems[i+queue->head];
			}
			queue->head = 0;
		} else {
			fprintf(stderr, "%s\n", "Failed to push to queue: has reached maximum size.");
			return -1;
		}
	}

	queue->elems[queue->currentSize++] = elemToAdd;
	return 1;
}

int isEmptyQueue(Queue* queue) {
	assert((NULL != queue) && "Couldn't check for emptiness null-queue.");

	return (queue->currentSize - queue->head);
}

int popQueue(Queue* queue) {
	assert((NULL != queue) && "Couldn't pop from null-queue.");

	if (queue->currentSize == 0) {
		fprintf(stderr, "%s\n", "Couldn't pop from empty queue.");
		return -1;
	}

	int topElem = queue->elems[queue->head++];

	if (!isEmptyQueue(queue)) {
		queue->currentSize = 0;
		queue->head = 0;
	}
	return topElem;

}


int destructQueue(Queue* queue) {
	if (NULL == queue) {
		fprintf(stderr, "%s\n", "Attempt at destroing null-queue.");
		return -1;
	}

	free(queue->elems);
	queue->elems = NULL;
	queue->currentSize = 0;
	queue->maxSize = 0;
	queue->head = 0;
	free(queue);
	return 1;
}

void BFS(Graph* graph, int startingNode) {
	assert((NULL != graph) && "Couldn't BFS null-graph");

	printf("Starting BFS from %d node\n", startingNode);

	Queue* queue = createQueue(32);
	pushQueue(queue, startingNode);

	while (isEmptyQueue(queue)) {
		int currentNode = popQueue(queue);
		printf("Processing %d node\n", currentNode);
		graph->nodes[currentNode].color = GREY;
		for (int i = 0; i < graph->size; ++i) {
			if (i == currentNode) continue;
			if (graph->adjacencyMatrix->matrix[currentNode][i] == 1) {
				switch (graph->nodes[i].color) {
					case WHITE:
						pushQueue(queue, i);
						break;
					case GREY:
						fprintf(stderr, "%s\n", "Something went wrong! BFS shouldn't visit Grey node!");
						break;
					case BLACK:
						printf("%s Backedge is: %d --> %d\n", "Cycle detected!", currentNode, i);
						break;
					default:
						printf("%s\n", "Unknown node color!");
						break;
				}
			}
		}
		graph->nodes[currentNode].color = BLACK;
	}
	
	destructQueue(queue);
}







