#include "task-91-count-word-frequency.h"
#include <fstream>
#include <iostream>
#include <stdexcept>

using namespace std;

vector<pair<KeyType, int>> countFrequencyOfWords(HashTable *wordsFrequencies, const int &baseSize, const string &fileName)
{
	ifstream file(fileName, ios::in);

	if (!file.is_open())
	{
		cerr << "Problem opening file: " << fileName << endl;
		throw runtime_error("ERROR: file not found");
	}

	double amount = 0;

	while (!file.eof())
	{
		string word;
		file >> word;

		file.ignore(1);
		wordsFrequencies->addKey(word);

		++amount;
	}

	file.close();

	setlocale(LC_ALL, "Russian");

	cout << "\nРезультат:" << endl;
	wordsFrequencies->printKeysWithAmount();
	cout << endl;

	const double k = amount / baseSize;
	cout << "Максимальная длина списка: " << wordsFrequencies->getMaxAmount() << endl;
	cout << "Средняя длина списка: " << wordsFrequencies->getAverageAmount() << endl;
	cout << "Коэффициент заполнения хеш-таблицы: " << k << endl;

	// return vector representation
	vector<pair<KeyType, int>> vectorOfKeys = wordsFrequencies->getVectorRepresentation();

	// Constructor will be called
	delete wordsFrequencies;

	return vectorOfKeys;
}
