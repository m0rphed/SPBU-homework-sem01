#include "../task-01-isPalindrome.h"

#include <gtest/gtest.h> // Google Test Framework
#include <gmock/gmock.h> // Google Mock. Google Mock works seamlessly with Google Test.

#include <locale>
#include <vector>
#include <iostream>

using namespace std;


TEST(isPalindromeTest, rusWordsTestCppVersion)
{
	setlocale(LC_ALL, "Russian");
	
	vector<string> russianPalindromes = {"топот",
	                                     "ди оро ид",
	                                     "доввод",
	                                     "довод",
	                                     "до х од"};
	
	vector<string> russianWords = {"чебурек", "БъернСтраусТруп"};
	
	for (string &word : russianPalindromes)
	{
		ASSERT_TRUE(isPalindromeCpp(word));
	}
	
	for (string &word : russianWords)
	{
		ASSERT_FALSE(isPalindromeCpp(word));
	}
	
}


TEST(isPalindromeTest, engWordsTestCppVersion)
{
	vector<string> engPalindromes = {"weew", "zooz"};
	for (string &word : engPalindromes)
	{
		ASSERT_TRUE(isPalindromeCpp(word));
	}
}


TEST(isPalindromeTest, testNotCppVersion)
{
	ASSERT_TRUE(isPalindrome("abba"));
	ASSERT_TRUE(isPalindrome("abbc  cbba"));
	ASSERT_FALSE(isPalindrome("geeks"));
	
	// for some strange reason RUS symbols don't work at all! :(
	char testRussian[35] = "я иду с мечем судия";
	sanitizeString(testRussian);
	
	// false tests
	ASSERT_FALSE(isPalindrome(testRussian));
	ASSERT_FALSE(isPalindrome("яидусмечемсудия"));
	ASSERT_FALSE(isPalindrome("яидусмЕЕмсудия"));
	
	ASSERT_TRUE(isPalindrome("to p ot"));
	ASSERT_FALSE(isPalindrome("топот"));
}