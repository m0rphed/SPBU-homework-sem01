#include "Dictionary.h"
#include <iostream>
#include <stdexcept>

using namespace std;

struct AVLTree::Node
{
    KeyType key;
    ValueType value;
    int height = 0;

    Node *leftChild = nullptr;
    Node *rightChild = nullptr;

    // Default constructor
    Node() = default;

    // Explicit constructor
    explicit Node(const KeyType &nodeKey, const ValueType &nodeValue, int nodeHeight = 0, Node *left = nullptr,
                  Node *right = nullptr);
};

AVLTree::Node::Node(const KeyType &nodeKey, const ValueType &nodeValue, int nodeHeight, AVLTree::Node *left,
                    AVLTree::Node *right)
{
    key = nodeKey;
    value = nodeValue;
    height = nodeHeight;
    leftChild = left;
    rightChild = right;
}

bool AVLTree::isEmpty()
{
    return root == nullptr;
}

int AVLTree::getHeight(AVLTree::Node *node)
{
    return node ? node->height : 0;
}

int AVLTree::getBalanceFactor(AVLTree::Node *node)
{
    return getHeight(node->rightChild) - getHeight(node->leftChild);
}

void AVLTree::updateHeight(AVLTree::Node *node)
{
    const int heightLeft = getHeight(node->leftChild);
    const int heightRight = getHeight(node->rightChild);
    node->height = ((heightLeft > heightRight) ? heightLeft : heightRight) + 1;
}

AVLTree::Node *AVLTree::rotateRight(AVLTree::Node *node)
{
    auto *pivot = node->leftChild;

    node->leftChild = pivot->rightChild;
    pivot->rightChild = node;

    updateHeight(node);
    updateHeight(pivot);
    return pivot;
}

AVLTree::Node *AVLTree::rotateLeft(AVLTree::Node *node)
{
    auto *pivot = node->rightChild;

    node->rightChild = pivot->leftChild;
    pivot->leftChild = node;

    updateHeight(node);
    updateHeight(pivot);
    return pivot;
}

AVLTree::Node *AVLTree::balanceSubtree(AVLTree::Node *node)
{
    updateHeight(node);

    if (getBalanceFactor(node) == 2)
    {
        if (getBalanceFactor(node->rightChild) < 0)
        {
            node->rightChild = rotateRight(node->rightChild);
        }

        return rotateLeft(node);
    }

    if (getBalanceFactor(node) == -2)
    {
        if (getBalanceFactor(node->leftChild) > 0)
        {
            node->leftChild = rotateLeft(node->leftChild);
        }

        return rotateRight(node);
    }

    return node;
}

void AVLTree::add(const KeyType &key, string value)
{
    if (isEmpty())
    {
        root = new Node(key, value);
        return;
    }

    root = addNode(root, key, value);
}

AVLTree::Node *AVLTree::addNode(AVLTree::Node *current, const KeyType &key, ValueType value)
{
    if (!current)
    {
        return new Node(key, value);
    }

    if (current->key == key)
    {
        current->value = value;
        return current;
    }

    if (current->key > key)
    {
        current->leftChild = addNode(current->leftChild, key, value);
    }
    else
    {
        current->rightChild = addNode(current->rightChild, key, value);
    }

    return balanceSubtree(current);
}

string AVLTree::findNode(const KeyType &key)
{
    if (isEmpty())
    {
        // return empty string
        return string();
    }

    auto *temp = root;

    // tree traversal
    while (true)
    {
        if (temp->key == key)
        {
            return temp->value;
        }

        if (temp->key > key)
        {
            if (!temp->leftChild)
            {
                // return empty string
                return string();
            }

            temp = temp->leftChild;
        }
        else
        {
            if (!temp->rightChild)
            {
                // return empty string
                return string();
            }

            temp = temp->rightChild;
        }
    }
}

bool AVLTree::deleteByKey(const KeyType &key)
{
//    if (!exists(key))
//    {
//        cerr << "\nNo value with such key in the dictionary" << endl;
//        throw runtime_error("ERROR: Key not found");
//    }

    // if key doesn't exist - DO NOTHING (because it is specified in the task description)
    if (!exists(key))
    {
        return false;
    }

    // Search recursively in AVL tree
    // then delete node with that key
    root = deleteFromSubtree(root, key);
    return true;
}

AVLTree::Node *AVLTree::deleteFromSubtree(AVLTree::Node *current, KeyType key)
{
    if (current->key > key)
    {
        current->leftChild = deleteFromSubtree(current->leftChild, key);
    }
    else if (current->key < key)
    {
        current->rightChild = deleteFromSubtree(current->rightChild, key);
    }
    else
    {
        if (!current->leftChild && !current->rightChild)
        {
            auto *temp = current;
            current = nullptr;
            delete temp;
            return current;
        }

        if (!current->leftChild && current->rightChild)
        {
            auto *temp = current;
            current = current->rightChild;
            delete temp;
            return current;
        }

        if (current->leftChild && !current->rightChild)
        {
            auto *temp = current;
            current = current->leftChild;
            delete temp;
            return current;
        }

        auto *temp = maxNode(current);
        current->key = temp->key;
        current->value = temp->value;
        deleteFromSubtree(current->leftChild, current->key);
        return current;
    }

    return balanceSubtree(current);
}

AVLTree::Node *AVLTree::maxNode(AVLTree::Node *current)
{
    auto *temp = current->leftChild;

    while (temp->rightChild)
    {
        temp = temp->rightChild;
    }

    return temp;
}

bool AVLTree::exists(const KeyType &key)
{
    if (isEmpty())
    {
        return false;
    }

    auto *temp = root;

    // tree traversal
    while (true)
    {
        if (temp->key == key)
        {
            return true;
        }

        if (temp->key > key)
        {
            if (!temp->leftChild)
            {
                return false;
            }

            temp = temp->leftChild;
        }
        else
        {
            if (!temp->rightChild)
            {
                return false;
            }

            temp = temp->rightChild;
        }
    }
}

void AVLTree::deleteSubtree(AVLTree::Node *nodeToDelete)
{
    if (nodeToDelete)
    {
        deleteSubtree(nodeToDelete->leftChild);
        deleteSubtree(nodeToDelete->rightChild);
        delete nodeToDelete;
    }
}

AVLTree::Node *AVLTree::getRoot()
{
    return root;
}

AVLTree::AVLTree(const KeyType &rootKey, const ValueType &rootValue)
{
    root = new Node(rootKey, rootValue);
}

AVLTree::~AVLTree()
{
    deleteSubtree(root);
}
