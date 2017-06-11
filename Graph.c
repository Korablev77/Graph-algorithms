#include "include/Graph.h"


Graph* createGraph(int size) {
	assert((0 < size) && "Couldn't create graph with negative number of nodes.");

	AdjacencyMatrix* adjMatrix = (AdjacencyMatrix*)calloc(1, sizeof(AdjacencyMatrix));
	if (NULL == adjMatrix) {
		fprintf(stderr, "%s\n", "Couldn't create graph: calloc failed.");
		return NULL;
	}
	//adjMatrix->size = size;
	adjMatrix->matrix = (int**)calloc(size, sizeof(int*));
	if (NULL == adjMatrix->matrix) {
		fprintf(stderr, "%s\n", "Couldn't create graph: calloc failed.");
		free(adjMatrix);
		return NULL;
	}

	for (int i = 0; i < size; ++i) {
		adjMatrix->matrix[i] = (int*)calloc(size, sizeof(int));
	}

	Graph* graph = (Graph*)calloc(1, sizeof(Graph));
	if (NULL == graph) {
		fprintf(stderr, "%s\n", "Couldn't create graph: calloc failed.");
		for (int i = 0; i < size; ++i) {
			free(adjMatrix->matrix[i]);
		}
		free(adjMatrix);
		return NULL;
	}
	graph->size = size;
	graph->adjacencyMatrix = adjMatrix;
	graph->nodes = (Node*)calloc(size, sizeof(Node));

	return graph;
}


void initGraph(Graph* graph) {
	assert((NULL != graph) && "Couldn't init pointer to null-graph");
	srand(time(NULL));
	for (int i = 0; i < graph->size; ++i) {
		graph->nodes[i].color = WHITE;
		for (int j = 0; j < graph->size; ++j) {
			if (i != j) graph->adjacencyMatrix->matrix[i][j] = rand() & 1;
			else graph->adjacencyMatrix->matrix[i][j] = 1;
		}
	}
}

void printGraph(Graph* graph) {
	assert((NULL != graph) && "Couldn't print null-graph");

	printf("%s\n", "Adjacency Matrix of graph is:");
	for (int i = 0; i < graph->size; ++i) {
		for (int j = 0; j < graph->size; ++j) {
			printf("%d ", graph->adjacencyMatrix->matrix[i][j]);
		}
		printf("\n");
	}
}

int destructGraph(Graph* graph) {
	if (NULL == graph) {
		fprintf(stderr, "%s\n", "Attempt at destroing null-graph.");
		return -1;
	}

	for (int i = 0; i < graph->size; ++i) {
		free(graph->adjacencyMatrix->matrix[i]);
	}
	free(graph->adjacencyMatrix->matrix);
	free(graph->adjacencyMatrix);
	graph->size = 0;
	free(graph->nodes);
	free(graph);
	graph = NULL;
	return 1;
}

