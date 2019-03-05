#pragma once

#include <fstream>
#include <iostream>
#include <string>

struct SyntaxTreeNode
{
    int data = 0;
    SyntaxTreeNode *left = nullptr;
    SyntaxTreeNode *right = nullptr;

    SyntaxTreeNode() = default;

    explicit SyntaxTreeNode(const int &value);
};

class SyntaxTree
{
private:
    SyntaxTreeNode *root = nullptr;

public:
    explicit SyntaxTree(const std::string &fileName);

    explicit SyntaxTree(SyntaxTreeNode *newRoot);

    bool isEmpty();

    void printTree();

    int evalExpression();

    ~SyntaxTree();
};
