#pragma once

#include <fstream>
#include <iostream>
#include <string>

struct SyntaxTreeNode
{
	int data = 0;
	SyntaxTreeNode *left = nullptr;
	SyntaxTreeNode *right = nullptr;
	
	explicit SyntaxTreeNode(const int &value);
};


class SyntaxTree
{
	SyntaxTreeNode *root = nullptr;

public:
	
	explicit SyntaxTree(SyntaxTreeNode *newRoot)
	{
		root = newRoot;
	}
	
	bool isEmpty();
	
	void deleteTree();
	
	void printTree();
	
	int evalExpression();
};

SyntaxTreeNode *createNode(std::ifstream &input);

SyntaxTree *createTree(std::ifstream &input);

void deleteTraversal(SyntaxTreeNode *current);

int evalByNode(SyntaxTreeNode *current);

void printNode(SyntaxTreeNode *current);

