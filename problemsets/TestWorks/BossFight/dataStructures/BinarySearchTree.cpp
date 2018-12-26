#include "BinarySearchTree.h"
#include <string>

using namespace std;
typedef string TreeValueType;

TreeNode *insertTo(const TreeValueType &value, TreeNode *subTree)
{
	if (!subTree)
	{
		subTree = new TreeNode(value);
	}
	else if (value <= subTree->data)
	{
		subTree->left = insertTo(value, subTree->left);
	}
	else
	{
		subTree->right = insertTo(value, subTree->right);
	}
	
	return subTree;
}


void preOrderTraversal(TreeNode *currentNode)
{
	if (!currentNode)
	{
		return;
	}
	
	cout << currentNode->data << endl;
	
	preOrderTraversal(currentNode->left);
	preOrderTraversal(currentNode->right);
	
}


void inOrderTraversal(TreeNode *currentNode)
{
	if (!currentNode)
	{
		return;
	}
	
	inOrderTraversal(currentNode->left);
	
	cout << currentNode->data << endl;
	
	inOrderTraversal(currentNode->right);
}


void postOrderTraversal(TreeNode *currentNode)
{
	if (!currentNode)
	{
		return;
	}
	
	postOrderTraversal(currentNode->left);
	postOrderTraversal(currentNode->right);
	
	cout << currentNode->data << endl;
}


void destroyNode(TreeNode *node)
{
	if (!node)
	{
		return;
	}
	else
	{
		destroyNode(node->left);
		destroyNode(node->right);
	}
}


TreeNode::TreeNode(const TreeValueType &value) : data(value), left(nullptr), right(nullptr)
{
}


TreeNode::~TreeNode()
{
	destroyNode(this);
}


TreeNode *findMin(TreeNode *subTree)
{
	if (!subTree)
	{
		return nullptr;
	}
	else if (!subTree->left)
	{
		return subTree;
	}
	else
	{
		return findMin(subTree->left);
	}
}


TreeNode *findMax(TreeNode *subTree)
{
	if (!subTree)
	{
		return nullptr;
	}
	else if (!subTree->right)
	{
		return subTree;
	}
	else
	{
		return findMax(subTree->right);
	}
}


BinarySearchTree::~BinarySearchTree()
{
	destroyNode(this->root);
}


void BinarySearchTree::postOrder()
{
	postOrderTraversal(root);
}


void BinarySearchTree::inOrder()
{
	inOrderTraversal(root);
}


void BinarySearchTree::preOrder()
{
	preOrderTraversal(root);
}


void BinarySearchTree::insert(const TreeValueType &value)
{
	root = insertTo(value, root);
}


pair<bool, TreeNode *> BinarySearchTree::search(const TreeValueType &value)
{
	auto *currentNode = root;
	
	while (currentNode != nullptr)
	{
		if (value == currentNode->data)
		{
			return make_pair(true, currentNode);
		}
		
		if (value < currentNode->data)
		{
			currentNode = currentNode->left;
		}
		else
		{
			currentNode = currentNode->right;
		}
	}
	
	return make_pair(false, nullptr);
}


TreeNode *BinarySearchTree::getMin()
{
	return findMin(root);
}


TreeNode *BinarySearchTree::getMax()
{
	return findMax(root);
}


void binarySearchTreeInterface()
{
	int operation = 0;
	TreeValueType value;
	auto *tree = new BinarySearchTree();
	
	cout << "0) Exit" << endl;
	cout << "1) Search in tree" << endl;
	cout << "2) Insert to tree" << endl;
	
	cout << "3) Do pre-order traversal" << endl;
	cout << "4) Do in-order traversal" << endl;
	cout << "5) Do post-order traversal" << endl;
	cout << "6) Check if tree is BST" << endl;
	
	cout << "6) Find MIN element in tree" << endl;
	cout << "7) Find MAX element in tree" << endl;
	
	do
	{
		cout << "Enter choice: " << endl;
		cin >> operation;
		switch (operation)
		{
			case 1:
			{
				cout << "Enter value to be searched:" << endl;
				cin >> value;
				
				pair<bool, TreeNode *> found = tree->search(value);
				if (!found.first)
				{
					cout << "No such value in the tree" << endl;
				}
				else
				{
					cout << "Found node with value: " << found.second->data << endl;
					if (found.second->left)
					{
						cout << "Left-child value: " << found.second->left->data << endl;
					}
					if (found.second->right)
					{
						cout << "Right-child value: " << found.second->right->data << endl;
					}
				}
				break;
			}
			case 2:
			{
				cout << "Enter value to be inserted:" << endl;
				cin >> value;
				tree->insert(value);
				break;
			}
			case 3:
			{
				cout << "Pre-order traversal:" << endl;
				tree->preOrder();
				cout << endl;
				break;
			}
			case 4:
			{
				cout << "In-order traversal:" << endl;
				tree->inOrder();
				cout << endl;
				break;
			}
			case 5:
			{
				cout << "Post-order traversal:" << endl;
				tree->postOrder();
				cout << endl;
				break;
			}
			case 6:
			{
				cout << "Found MIN: " << (tree->getMin())->data << endl;
				break;
			}
			case 7:
			{
				cout << "Found MAX: " << (tree->getMax())->data << endl;
				break;
			}
			case 0:
			{
				cout << "Exit" << endl;
				break;
			}
			default:
			{
				cout << "Invalid Choice" << endl;
			}
		}
	} while (operation != 0);
	
	delete tree;
}
