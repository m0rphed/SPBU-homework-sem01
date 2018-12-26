#include "../task-01-isPalindrome.h"

#include <gtest/gtest.h> // Google Test Framework

// #include <locale>
#include <iostream>
#include <vector>

using namespace std;


// For some strange reason Russian language is not working :(
TEST(isPalindromeTest, testEngString)
{
	// just some words
	vector<string> words = {"I hate TDD", "чебурек", "БъернСтраусТруп", "Cheetah", "CodeMonkey"};
	
	// palindromes examples
	vector<string> palindromes = {"deified",
	                              "hadedah",
	                              "murdrum",
	                              "tattarrattat",
	                              "peeweep",
	                              "racecar",
	                              "reifier",
	                              "repaper",
	                              "reviver",
	                              "rotator"};
	
	for (string &word : palindromes)
	{
		EXPECT_TRUE(isPalindrome(word));
	}
	
	for (string &word : words)
	{
		ASSERT_FALSE(isPalindrome(word));
	}
	
}


TEST(isPalindromeTest, testEnglishCharlists)
{
	char palindromes[4][15] = {"to p ot", "abba", "abbc  cbba", "igeegi"};
	char words[4][15] = {"Jesus", "Hel p", "Me", "Please!"};
	
	for (auto &test : palindromes)
	{
		ASSERT_TRUE(isPalindrome(test));
	}
	
	for (auto &test : words)
	{
		ASSERT_FALSE(isPalindrome(test));
	}
}
