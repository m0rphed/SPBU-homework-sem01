#pragma once

#include <iostream>
#include <utility>
#include <string>

typedef std::string TreeValueType;

struct TreeNode
{
	TreeValueType data;
	TreeNode *left;
	TreeNode *right;
	
	// Constructor for all related nodes
	explicit TreeNode(const TreeValueType &value);
	
	// Destructor for all related nodes
	~TreeNode();
};

class BinarySearchTree
{
	TreeNode *root = nullptr;

public:
	std::pair<bool, TreeNode *> search(const TreeValueType &value);
	
	void insert(const TreeValueType &value);
	
	void preOrder();
	
	void inOrder();
	
	void postOrder();
	
	TreeNode *getMin();
	
	TreeNode *getMax();
	
	~BinarySearchTree();
};

void simpleTest(TreeValueType *elements, const int &length);

void binarySearchTreeInterface();