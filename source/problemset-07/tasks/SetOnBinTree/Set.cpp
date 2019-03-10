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
    return root == nullptr;
}

bool Set::contains(const ValueType &target) const
{
    if (isEmpty())
    {
        return false;
    }

    return (getElementByValue(target) != nullptr);
}

bool Set::addValue(const ValueType &value)
{
    if (isEmpty())
    {
        root = new BSTNode(value);
        return true;
    }

    if (contains(value))
    {
        return false;
    }

    auto *newParent = root;
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

void safeDeleteChild(BSTNode *node)
{
    if (node->parent->left == node)
    {
        node->parent->left = nullptr;
    }
    else
    {
        node->parent->right = nullptr;
    }

    delete node;
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
            safeDeleteChild(current);
            return;
        }
        else
        {
            vector<ValueType> values = {};
            if (current->left)
            {
                values.push_back((current->left)->data);
            }

            if (current->right)
            {
                values.push_back((current->right)->data);
            }

            safeDeleteChild(current);

            for (auto &value : values)
            {
                addValue(value);
            }
        }
    }
}

bool Set::removeValue(const ValueType &target)
{
    if (isEmpty() || !contains(target))
    {
        return false;
    }
    else
    {
        removeTraversal(root, target);
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

    if (isEmpty())
    {
        return values;
    }

    BST::leftTraversal(root, values);
    return values;
}

vector<ValueType> Set::descendingOrder()
{
    vector<ValueType> values;

    if (isEmpty())
    {
        return values;
    }

    BST::rightTraversal(root, values);
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

    destroy(node->left);
    destroy(node->right);
    delete node;
}

void Set::clearSet()
{
    BST::destroy(root->left);
    BST::destroy(root->right);
    size = 0;
}

Set::~Set()
{
    BST::destroy(root);
}

BSTNode *Set::getElementByValue(const ValueType &value) const
{
    auto *current = root;

    while (current && (current->data != value))
    {
        if (value < current->data)
        {
            current = current->left;
        }
        else if (value > current->data)
        {
            current = current->right;
        }
    }

    return current;
}
