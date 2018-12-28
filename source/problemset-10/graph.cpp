#include <vector>
#include <unordered_map>
#include "graph.h"

struct Graph
{
	std::unordered_map<int, Vertex *> vertices;
	std::unordered_map<int, std::unordered_map<int, Edge *> *> edges;
};


Graph *newGraph()
{
	return new Graph;
}

Vertex *createVertex(Graph *g, int index)
{
	Vertex *v = new Vertex();
	v->index = index;
	g->vertices[index] = v;
	return v;
}

Vertex *getOrCreateVertex(Graph *g, int index)
{
	Vertex *v = g->vertices[index];
	return (v == NULL) ? createVertex(g, index) : v;
}

Edge *createEdge(Vertex *left, Vertex *right)
{
	Edge *e = new Edge();
	e->left = left;
	e->right = right;
	return e;
}

Edge *addEdge(Graph *g, int leftVertex, int rightVertex)
{
	Vertex *lVertex = getOrCreateVertex(g, leftVertex);
	Vertex *rVertex = getOrCreateVertex(g, rightVertex);
	Edge *e = createEdge(lVertex, rVertex);
	std::unordered_map<int, Edge *> *edgeMap = g->edges[leftVertex];
	if (edgeMap == NULL)
	{
		edgeMap = new std::unordered_map<int, Edge *>();
		g->edges[leftVertex] = edgeMap;
	}
	(*edgeMap)[rightVertex] = e;
	return e;
}

std::vector<Edge *> GetEdges(Graph *g, int vertexIndex)
{
	Vertex *v = g->vertices[vertexIndex];
	std::vector<Edge *> result;
	std::unordered_map<int, Edge *> *edgeMap = g->edges[vertexIndex];
	
	for (auto i = edgeMap->begin(); i != edgeMap->end(); i++)
	{
		result.push_back(i->second);
	}
	return result;
}

Vertex *getVertex(Graph *g, int vertexIndex)
{
	return g->vertices[vertexIndex];
}