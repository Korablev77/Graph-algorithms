#ifndef GRAPH_H
#define GRAPH_H

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <time.h>

typedef enum Color {
	WHITE,
	BLACK, 
	GREY
}Color;

typedef struct Node {
	//int isExisting;
	Color color;
}Node;

typedef struct AdjacencyMatrix {
	int** matrix;
}AdjacencyMatrix;

typedef struct Graph {
	AdjacencyMatrix* adjacencyMatrix;
	Node* nodes;
	size_t size;
}Graph;


Graph* createGraph(int size);

void initGraph(Graph* graph);

void printGraph(Graph* graph);

int destructGraph(Graph* graph);


#endif
