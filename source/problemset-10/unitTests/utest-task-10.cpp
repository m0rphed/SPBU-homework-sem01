#include <gtest/gtest.h> // Google Test Framework
#include "../task-10-graph-of-roads.h"

TEST(problemset10, task10)
{
	SUCCEED();
}


TEST(problemset10, task10_1)
{
	DataInput *di = readDataInputFromFile("DataInput.txt");
	DataOutput *dOut = new DataOutput();
	buildWorld(di, dOut);
	
	FAIL();
}

TEST(problemset10, task10_2)
{
	SUCCEED();
}
