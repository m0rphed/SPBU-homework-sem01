#include "../tasks/WordFrequency/task-91-count-word-frequency.h" // actual problem solution
#include <gtest/gtest.h> // Google Test Framework

#include <map>

using namespace std;

TEST(task91, wordFrequencyTest)
{
	auto *table = new HashTable(standardBaseSize);
	vector<pair<KeyType, int>> result = countFrequencyOfWords(table, standardBaseSize, "data.txt");

	map<KeyType, int> aliceQuoteExpectedFrequency = {
			{"had", 1},
			{"would.", 1},
			{"and", 1},
			{"of", 1,},
			{ "You", 1 },
			{ "nonsense.", 1 },
			{ "is", 3 },
			{ "wouldn't", 3 },
			{ "it", 6 },
			{ "contrary-wise;", 1 },
			{ "Nothing", 1 },
			{ "because", 1 },
			{ "my", 1 },
			{ "isn't.", 1 },
			{ "what", 4 },
			{ "be,", 2 },
			{ "world", 1 },
			{ "would", 3 },
			{ "I", 1 },
			{ "If", 1 },
			{ "And", 1 },
			{ "see?", 1 },
			{ "own,", 1 },
			{ "everything", 2 },
			{ "a", 1 },
			{ "be", 3 },
	};

	for (const auto &element : result)
	{
		ASSERT_EQ(aliceQuoteExpectedFrequency[element.first], element.second);
	}
}
