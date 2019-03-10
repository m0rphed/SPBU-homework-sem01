#pragma once

#include <vector>
#include "../../../testworks/testwork-02-try-01/dataStructures.h"

typedef int ValueType;

struct BSTNode
{
	ValueType data = 0;
	BSTNode *left = nullptr;
	BSTNode *right = nullptr;
	BSTNode *parent = nullptr;
	
	explicit BSTNode(const ValueType &value);
	
	BSTNode(const ValueType &value, BSTNode *newLeft, BSTNode *newRight, BSTNode *newParent);
};


class Set
{
	BSTNode *root = nullptr;
	int size = 0;

public:
	int getSize() const;
	
	// Get a pointer to the root
	BSTNode *getRootNode() const;
	
	// Check the set for emptiness
	bool isEmpty() const;
	
	// Check existence of value in the set
	bool contains(const ValueType &target) const;
	
	// Add a new value to the set
	bool addValue(const ValueType &value);
	
	void removeTraversal(BSTNode *current, const ValueType &target);
	
	// Remove a value from the set
	bool removeValue(const ValueType &target);
	
	// Get vector of elements in ascending order
	std::vector<ValueType> ascendingOrder();
	
	// Get vector of elements in descending order
	std::vector<ValueType> descendingOrder();
	
	// Print elements
	void print(std::vector<ValueType> &&setContainer);
	
	// Clear set (makes set empty, but does not delete it)
	void clearSet();
	
	// Destructor of set
	~Set();
};


namespace BST
{
	void leftTraversal(BSTNode *current, std::vector<ValueType> &values);
	
	void rightTraversal(BSTNode *current, std::vector<ValueType> &values);
	
	// Delete the set completely
	void destroy(BSTNode *&node);
}
