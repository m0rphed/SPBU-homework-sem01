#pragma once

#include "DoublyLinkedList.h"
#include "BinarySearchTree.h"

struct Set
{
	Set();
	
	~Set();
	
	bool add(const int &data);
	
	bool remove(const int &data);
	
	bool isExists(const int &data) const;
	
	bool isEmpty() const;
	
	bool ascendingOrder() const;
	
	bool descendingOrder() const;

private:
	TreeNode *head;
	
	void removeSetRecursion(TreeNode *node);
	
	void addNode(TreeNode *node, const int &data);
	
	void removeRecursion(TreeNode *&current, const int &data);
	
	void removeIfNoChildren(TreeNode *&current);
	
	int maximum(const TreeNode *current) const;
	
	void treeTraversal(DoublyLinkedList *list) const;
	
	void treeTraversalRecursive(const TreeNode *current, DoublyLinkedList *list) const;
};
