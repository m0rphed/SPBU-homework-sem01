#include "AbstractSyntaxTree.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

SyntaxTreeNode *createNode(ifstream &input)
{
	const char current = input.peek();
	auto *newNode = new SyntaxTreeNode;
	
	if (current == '(')
	{
		input.get();
		newNode->data = input.get();
		input.get();
		newNode->left = createNode(input);
		input.get();
		newNode->right = createNode(input);
		input.get();
	}
	else if ((isdigit(current)) || (current == '-'))
	{
		input >> newNode->data;
	}
	
	return newNode;
}


bool SyntaxTree::isEmpty()
{
	return (this->root == nullptr);
}


void deleteTraversal(SyntaxTreeNode *current)
{
	if (current->left != nullptr)
	{
		deleteTraversal(current->left);
	}
	
	if (current->right != nullptr)
	{
		deleteTraversal(current->right);
	}
	
	delete current;
}


void SyntaxTree::deleteTree()
{
	if (!this->isEmpty())
	{
		deleteTraversal(this->root);
	}
	delete root;
	this->root = nullptr;
}


int evalByNode(SyntaxTreeNode *current)
{
	if (current->data == '*')
	{
		return evalByNode(current->left) * evalByNode(current->right);
	}
	else if (current->data == '/')
	{
		return evalByNode(current->left) / evalByNode(current->right);
	}
	else if (current->data == '+')
	{
		return evalByNode(current->left) + evalByNode(current->right);
	}
	else if (current->data == '-')
	{
		return evalByNode(current->left) - evalByNode(current->right);
	}
	
	return current->data;
}


void printNode(SyntaxTreeNode *current)
{
	if (current->data == '*')
	{
		cout << "(* ";
	}
	else if (current->data == '/')
	{
		cout << "(/ ";
	}
	else if (current->data == '+')
	{
		cout << "(+ ";
	}
	else if (current->data == '-')
	{
		cout << "(- ";
	}
	else
	{
		cout << current->data;
		return;
	}
	
	printNode(current->left);
	cout << ' ';
	printNode(current->right);
	cout << ')';
}


SyntaxTree *createTree(std::ifstream &input)
{
	auto *newRoot = createNode(input);
	auto *newTree = new SyntaxTree(newRoot);
	return newTree;
}


int SyntaxTree::evalExpression()
{
	if (isEmpty())
	{
		return 0;
	}
	
	return evalByNode(this->root);
}


void SyntaxTree::printTree()
{
	if (this->isEmpty())
	{
		cout << "Tree is empty." << endl;
		return;
	}
	
	printNode(this->root);
}


SyntaxTreeNode::SyntaxTreeNode(const int &value)
{
	data = value;
}
