#include <gtest/gtest.h> // Google Test Framework
#include "../tasks/ExpressionParsingTree/AbstractSyntaxTree.h"
#include "../tasks/ExpressionParsingTree/task-72-parsing-tree.h"

TEST(task72, simpleTest)
{
    const std::string fileName = "data.txt";
    auto *tree = new SyntaxTree(fileName);

    std::cout << "\nExpression tree:" << std::endl;
    tree->printTree();

    std::cout << "\nResult: " << tree->evalExpression() << std::endl;

    //ASSERT_THROW(tree->evalExpression(), std::invalid_argument);

    ASSERT_EQ(4, tree->evalExpression());

    delete tree;
}
