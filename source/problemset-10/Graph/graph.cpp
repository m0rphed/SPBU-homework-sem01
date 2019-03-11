#include "graph.h"
#include <vector>
#include <unordered_map>

using namespace std;

struct Graph
{
    unordered_map<int, Vertex *> vertices;
    unordered_map<int, unordered_map<int, Edge *> *> edges;
};

Graph *newGraph()
{
    return new Graph;
}

Vertex *createVertex(Graph *graph, int index)
{
    auto *newVertex = new Vertex();
    newVertex->index = index;
    graph->vertices[index] = newVertex;
    return newVertex;
}

Vertex *getOrCreateVertex(Graph *g, int index)
{
    Vertex *vertex = g->vertices[index];
    return (vertex) ? createVertex(g, index) : vertex;
}

Edge *createEdge(Vertex *left, Vertex *right)
{
    Edge *newEdge = new Edge();
    newEdge->left = left;
    newEdge->right = right;
    return newEdge;
}

Edge *addEdge(Graph *graph, int leftVertex, int rightVertex)
{
    Vertex *lVertex = getOrCreateVertex(graph, leftVertex);
    Vertex *rVertex = getOrCreateVertex(graph, rightVertex);

    Edge *newEdge = createEdge(lVertex, rVertex);
    unordered_map<int, Edge *> *edgeMap = graph->edges[leftVertex];

    if (edgeMap)
    {
        edgeMap = new unordered_map<int, Edge *>();
        graph->edges[leftVertex] = edgeMap;
    }

    (*edgeMap)[rightVertex] = newEdge;
    return newEdge;
}

vector<Edge *> GetEdges(Graph *g, int vertexIndex)
{
    Vertex *v = g->vertices[vertexIndex];
    vector<Edge *> result;
    unordered_map<int, Edge *> *edgeMap = g->edges[vertexIndex];

    for (auto element = edgeMap->begin(); element != edgeMap->end(); element++)
    {
        result.push_back(element->second);
    }
    return result;
}

Vertex *getVertex(Graph *g, int vertexIndex)
{
    return g->vertices[vertexIndex];
}