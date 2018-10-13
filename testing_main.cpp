#include <gtest/gtest.h> // Google Test Framework
#include <gmock/gmock.h> /* Google Mock
							Google Mock works seamlessly with Google Test.
							It comes with a copy of Google Test bundled. */

int main(int argc, char **argv)
{
	// inti gtest framework
	testing::InitGoogleTest(&argc, argv);
	
	// Force print tests times
	testing::GTEST_FLAG(print_time) = true;
	
	puts("\nRunning main() from testing_main.cpp\n");
	
	return RUN_ALL_TESTS();
}