#include "../tasks/ShuntingYard/task-63-shunting-yard-algorithm.h"

#include <gtest/gtest.h> // Google Test Framework

TEST(problemset06, task63)
{
	const auto input = "(1 + 1) * 2";
	handleIO(input);
	EXPECT_EQ(toPostfix(input), "1 1 + 2 *");
}


TEST(problemset06, task63LongerExpression)
{
	const auto input = "1 + 2 + 3 * 4 * 5 + 6 + 7";
	handleIO(input);
	EXPECT_EQ(toPostfix(input), "1 2 + 3 4 * 5 * + 6 + 7 +");
}