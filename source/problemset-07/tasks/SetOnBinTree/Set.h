#pragma once

#include <vector>

typedef int ValueType;

struct BSTNode
{
    ValueType data = 0;
    BSTNode *left = nullptr;
    BSTNode *right = nullptr;
    BSTNode *parent = nullptr;

    // Default constructor
    BSTNode() = default;

    // Constructor sets a value
    explicit BSTNode(const ValueType &value);

    // Constructor sets all fields
    BSTNode(const ValueType &value, BSTNode *newLeft, BSTNode *newRight, BSTNode *newParent);
};


class Set
{
    BSTNode *root = nullptr;
    int size = 0;

public:
    // Default set constructor
    Set() = default;

    // Get size of the set
    int getSize() const;

    // Get a pointer to the root
    BSTNode *getRootNode() const;

    // Get a element by value
    BSTNode *getElementByValue(const ValueType &value) const;

    // Check the set for emptiness
    bool isEmpty() const;

    // Check existence of value in the set
    bool contains(const ValueType &target) const;

    // Add a new value to the set
    bool addValue(const ValueType &value);

    // Traverse tree and remove every element
    void removeTraversal(BSTNode *current, const ValueType &target);

    // Remove a value from the set
    bool removeValue(const ValueType &target);

    // Get vector of elements in ascending order
    std::vector<ValueType> ascendingOrder();

    // Get vector of elements in descending order
    std::vector<ValueType> descendingOrder();

    // Print all elements from container
    void print(std::vector<ValueType> &&setContainer);

    // Clear set (makes set empty, but does not delete it)
    void clearSet();

    // Set destructor
    ~Set();
};

// Спуск по дереву делается и тут,
// и в contains,
// и даже в removeTraversal,
// так что сие есть копипаст.

// Я бы сделал функцию, возвращающую по значению узел,
// и использовал бы её во всех местах.
// Или даже более умную, возвращающую узел и его родителя,
// чтобы её можно было использовать и тогда,
// когда значения в дереве нет.

namespace BST
{
    void leftTraversal(BSTNode *current, std::vector<ValueType> &values);

    void rightTraversal(BSTNode *current, std::vector<ValueType> &values);

    // Delete the set completely
    void destroy(BSTNode *&node);
}
