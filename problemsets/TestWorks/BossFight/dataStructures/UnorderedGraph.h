#pragma once
#include<vector>
#include <unordered_map>

struct Vertex
{
	int index = 0;
	bool belongs = false;
};


struct Graph
{
	int vertexAmount = 0;
	std::vector<std::vector<int>> edges;
	std::unordered_map<int, Vertex> vertices;
	
	Graph *newGraph();
	
	void addVertex(Graph *graph, const int vertex);
	
	void addEdge(Graph *graph, int vertexA, int vertexB, int newLength);
	
	std::vector<int> adjacent(Graph *graph, int vertex);
	
	bool isAdjacent(Graph *graph, int vertexA, int vertexB);
	
	bool belongs(Graph *graph, int vertex);
	
	void assign(Graph *graph, int vertex);
	
	int edgeLength(Graph *graph, int vertexA, int vertexB);
	
	void deleteGraph(Graph *&graph);
};
