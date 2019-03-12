#pragma once

#include <string>

// Type of dictionary key can be easily redefined
typedef std::string KeyType;

// Type of dictionary value can be easily redefined
typedef std::string ValueType;

// AVL Tree implementation
class AVLTree
{
public:
    // Every node in AVL Tree is has type of struct Node
    struct Node;

    // Root getter method
    Node *getRoot();

    // Default constructor: creates AVL Tree with empty root
    AVLTree() = default;

    // Explicit constructor: creates AVL Tree with
    explicit AVLTree(const KeyType &rootKey, const ValueType &rootValue);

    // Adds new node in tree (if dictionary already has that key -> rewrites value)
    void add(const KeyType &key, ValueType value);

    // Returns value by given key
    ValueType findNode(const KeyType &key);

    // Checks if node with given key exists
    bool exists(const KeyType &key);

    // Deletes node with given key (if there is no such key -> does nothing)
    bool deleteByKey(const KeyType &key);

    // Destroys AVL tree
    ~AVLTree();

private:

    Node *root = nullptr;

    // Called in deleteByKey() method (it is recursive function)
    Node *deleteFromSubtree(Node *current, KeyType key);

    // Called in destructor (it is recursive function)
    void deleteSubtree(Node *nodeToDelete);

    // Called in add() method (it is recursive function)
    Node *addNode(Node *current, const KeyType &key, ValueType value);

    // Checks if tree is empty
    bool isEmpty();

    // Updates height for subtree (starting point is given node)
    void updateHeight(Node *node);

    // Returns height for subtree (starting point is given node)
    int getHeight(Node *node);

    // Returns balance factor (starting point is given node)
    int getBalanceFactor(Node *node);

    // Rotations:
    Node *rotateRight(Node *node); // right
    Node *rotateLeft(Node *node); // left

    // Rebalances whole subtree (starting point is given node)
    Node *balanceSubtree(Node *node);

    // Finds maximum of the left subtree
    Node *maxNode(Node *current);
};
