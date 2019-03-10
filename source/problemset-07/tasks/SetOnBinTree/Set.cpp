#include "Set.h"
#include <iostream>

typedef int ValueType;
using namespace std;

BSTNode::BSTNode(const ValueType &value)
{
	data = value;
}


BSTNode::BSTNode(const ValueType &value, BSTNode *newLeft, BSTNode *newRight, BSTNode *newParent)
{
	data = value;
	left = newLeft;
	right = newRight;
	parent = newParent;
}


BSTNode *Set::getRootNode() const
{
	return root;
}


int Set::getSize() const
{
	return size;
}


bool Set::isEmpty() const
{
	return this->root == nullptr;
}


bool Set::contains(const ValueType &target) const
{
	if (this->isEmpty())
	{
		return false;
	}
	
	auto *rootCopy = this->root;
	
	while (rootCopy && (rootCopy->data != target))
	{
		if (target < rootCopy->data)
		{
			rootCopy = rootCopy->left;
		}
		else if (target > rootCopy->data)
		{
			rootCopy = rootCopy->right;
		}
	}
	
	return (rootCopy != nullptr);
}


bool Set::addValue(const ValueType &value)
{
	if (this->contains(value))
	{
		return false;
	}
	
	if (this->isEmpty())
	{
		this->root = new BSTNode(value);
		return true;
	}
	
	auto *newParent = this->root;
	bool isLeft = (value < newParent->data);
	
	while ((isLeft && newParent->left) || (!isLeft && newParent->right))
	{
		if (isLeft)
		{
			newParent = newParent->left;
		}
		else
		{
			newParent = newParent->right;
		}
		
		isLeft = (value < newParent->data);
	}
	
	if (isLeft)
	{
		newParent->left = new BSTNode(value, nullptr, nullptr, newParent);
	}
	else
	{
		newParent->right = new BSTNode(value, nullptr, nullptr, newParent);
	}
	
	return true;
}


void Set::removeTraversal(BSTNode *current, const ValueType &target)
{
	if (target < current->data)
	{
		removeTraversal(current->left, target);
	}
	else if (target > current->data)
	{
		removeTraversal(current->right, target);
	}
	else
	{
		if (!current->left && !current->right)
		{
			delete current;
			return;
		}
		else
		{
			vector<ValueType> valuePair = {};
			if (current->left)
			{
				valuePair.push_back((current->left)->data);
			}
			
			if (current->right)
			{
				valuePair.push_back((current->right)->data);
			}
			
			delete current;
			
			for (auto &value : valuePair)
			{
				this->addValue(value);
			}
		}
	}
}


bool Set::removeValue(const ValueType &target)
{
	if (this->isEmpty() || this->contains(target))
	{
		return false;
	}
	else
	{
		removeTraversal(this->root, target);
		return true;
	}
}


void BST::leftTraversal(BSTNode *current, vector<ValueType> &values)
{
	if (current->left)
	{
		leftTraversal(current->left, values);
	}
	
	values.push_back(current->data);
	
	if (current->right)
	{
		leftTraversal(current->right, values);
	}
}


void BST::rightTraversal(BSTNode *current, vector<ValueType> &values)
{
	if (current->right)
	{
		rightTraversal(current->right, values);
	}
	
	values.push_back(current->data);
	
	if (current->left)
	{
		rightTraversal(current->left, values);
	}
}


vector<ValueType> Set::ascendingOrder()
{
	vector<ValueType> values;
	
	if (this->isEmpty())
	{
		return values;
	}
	
	BST::leftTraversal(this->root, values);
	return values;
}


vector<ValueType> Set::descendingOrder()
{
	vector<ValueType> values;
	
	if (this->isEmpty())
	{
		return values;
	}
	
	BST::rightTraversal(this->root, values);
	return values;
}


void Set::print(vector<ValueType> &&setContainer)
{
	// case 1: container is empty
	if (setContainer.empty())
	{
		cout << "< Empty >" << endl;
		return;
	}
	
	// case 2: container is not empty
	cout << "[" << setContainer.size() << "]: {";
	
	for (auto &element : setContainer)
	{
		cout << element << ", ";
	}
	cout << "}" << endl;
}


void BST::destroy(BSTNode *&node)
{
	if (!node)
	{
		return;
	}
	else
	{
		destroy(node->left);
		destroy(node->right);
		delete node;
	}
}


void Set::clearSet()
{
	BST::destroy(this->root->left);
	BST::destroy(this->root->right);
	this->size = 0;
}


Set::~Set()
{
	BST::destroy(root);
}
