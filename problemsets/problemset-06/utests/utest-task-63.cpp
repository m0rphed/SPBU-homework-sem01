#include "../tasks/ShuntingYard/task-63-shunting-yard-algorithm.h"

#include <gtest/gtest.h> // Google Test Framework

TEST(problemset06, task63)
{
	handleIO("(1 + 1) * 2");
	EXPECT_EQ(toPostfix("(1 + 1) * 2"), "1 1 + 2 *");
}
