#include "Set.h"
#include "BinarySearchTree.h"
#include "DoublyLinkedList.h"
#include <iostream>

Set::Set()
{
	head = nullptr;
}


Set::~Set()
{
	if (!isEmpty())
	{
		removeSetRecursion(head);
	}
}


void Set::removeSetRecursion(TreeNode *node)
{
	if (isEmpty())
	{
		return;
	}
	if (node->left != nullptr)
	{
		removeSetRecursion(node->left);
	}
	if (node->right != nullptr)
	{
		removeSetRecursion(node->right);
	}
	delete node;
}


bool Set::add(const int &data)
{
	if (isEmpty())
	{
		head = new TreeNode(data);
	}
	else
	{
		if (isExists(data))
		{
			return false;
		}
		addNode(head, data);
	}
	return true;
}


void Set::addNode(TreeNode *node, const int &data)
{
	if (node->data > data && node->left != nullptr)
	{
		addNode(node->left, data);
	}
	else if (node->data < data && node->right != nullptr)
	{
		addNode(node->right, data);
	}
	else
	{
		if (node->data > data)
		{
			node->left = new TreeNode(data);
		}
		else
		{
			node->right = new TreeNode(data);
		}
	}
}


bool Set::remove(const int &data)
{
	if (!isExists(data))
	{
		return false;
	}
	removeRecursion(head, data);
	return true;
}


void Set::removeRecursion(TreeNode *&current, const int &data)
{
	if (current->data > data)
	{
		removeRecursion(current->left, data);
	}
	else if (current->data < data)
	{
		removeRecursion(current->right, data);
	}
	else
	{
		if (current->left == nullptr || current->right == nullptr)
		{
			removeIfNoChildren(current);
			return;
		}
		else
		{
			current->data = maximum(current->left);
			removeRecursion(current->left, current->data);
		}
	}
}


int Set::maximum(const TreeNode *current) const
{
	auto *copyOfNode = current;
	
	while (copyOfNode->right)
	{
		copyOfNode = copyOfNode->right;
	}
	
	return copyOfNode->data;
}


void Set::removeIfNoChildren(TreeNode *&current)
{
	auto *copyOfNode = current;
	
	if (!current->left && !current->right)
	{
		current = nullptr;
	}
	else if (!current->left && current->right)
	{
		current = current->right;
	}
	else
	{
		current = current->left;
	}
	
	delete copyOfNode;
}


bool Set::isExists(const int &data) const
{
	if (this->isEmpty())
	{
		return false;
	}
	
	auto *temp = head;
	
	while (true)
	{
		if (temp->data > data)
		{
			if (temp->left == nullptr)
			{
				return false;
			}
			temp = temp->left;
		}
		else if (temp->data < data)
		{
			if (temp->right == nullptr)
			{
				return false;
			}
			temp = temp->right;
		}
		else
		{
			return true;
		}
	}
}


bool Set::isEmpty() const
{
	return head == nullptr;
}


void Set::treeTraversal(DoublyLinkedList *list) const
{
	if (!isEmpty())
	{
		treeTraversalRecursive(head, list);
	}
}


void Set::treeTraversalRecursive(const TreeNode *current, DoublyLinkedList *list) const
{
	list->addToEnd(current->data);
	
	if (current->left)
	{
		treeTraversalRecursive(current->left, list);
	}

	if (current->right)
	{
		treeTraversalRecursive(current->right, list);
	}
}


bool Set::ascendingOrder() const
{
	auto *list = new DoublyLinkedList();
	treeTraversal(list);
	
	if (list->getLength() == 0)
	{
		std::cout << "< Empty >" << std::endl;
		return false;
	}
	
	list->print();
	return true;
}


bool Set::descendingOrder() const
{
	auto *list = new DoublyLinkedList();
	treeTraversal(list);
	
	if (list->getLength() == 0)
	{
		std::cout << "< Empty >" << std::endl;
		return false;
	}
	
	list->printReverse();
	return true;
}