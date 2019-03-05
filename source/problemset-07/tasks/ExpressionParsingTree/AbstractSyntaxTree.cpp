#include "AbstractSyntaxTree.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// Create node using input
SyntaxTreeNode *createNode(ifstream &input)
{
    // Get first operator ('+', '-', '*', '/', '(', ')')
    const char current = input.peek();
    auto *newNode = new SyntaxTreeNode();

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

// Delete all nodes while traversing them (recursive)
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

// Eval expression by nodes (recursive)
int evalByNode(SyntaxTreeNode *current)
{
    if (current->data == '*')
    {
        return evalByNode(current->left) * evalByNode(current->right);
    }
    else if (current->data == '/')
    {
        if(evalByNode(current->right) == 0)
        {
            throw runtime_error("Division by zero");
        }

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

// Print an operator from node (recursive)
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

SyntaxTreeNode::SyntaxTreeNode(const int &value)
{
    data = value;
}

bool SyntaxTree::isEmpty()
{
    return (root == nullptr);
}

int SyntaxTree::evalExpression()
{
    if (isEmpty())
    {
        return 0;
    }

    return evalByNode(root);
}

void SyntaxTree::printTree()
{
    if (isEmpty())
    {
        cout << "Tree is empty." << endl;
        return;
    }

    printNode(root);
}

SyntaxTree::SyntaxTree(const string &fileName)
{
    ifstream input(fileName, ios::in);

    if (!input.is_open())
    {
        cerr << "\nCould not open file: " << fileName << endl;
        throw runtime_error("Error opening file.");
    }

    root = createNode(input);
    input.close();
}

SyntaxTree::SyntaxTree(SyntaxTreeNode *newRoot)
{
    root = newRoot;
}

SyntaxTree::~SyntaxTree()
{
    if (!isEmpty())
    {
        deleteTraversal(root);
    }

    delete root;
}
