#pragma once

#include <vector>

struct Graph;

struct Vertex
{
    int index;
    bool allocated;
};

struct Edge
{
    Vertex *left;
    Vertex *right;
    int roadLength;
};

Graph *newGraph();

Edge *addEdge(Graph *graph, int leftVertex, int rightVertex);

Vertex *getVertex(Graph *g, int vertexIndex);

