#include <vector>
#include <iostream>
#include <algorithm> // for swap()

using namespace std;


int combSort(vector<double> &array)
{
	int counter = 0; // counts the number of "swaps" algorithm
	double factor = 1.247; // factor is equal to (1 / (1-е^(-φ)))
	double step = array.size() - 1;
	
	while (step >= 1)
	{
		for (int i = 0; i + step < array.size(); ++i)
		{
			if (array[i] > array[i + step])
			{
				swap(array[i], array[i + step]);
				counter++;
			}
		}
		step /= factor;
	}
	
	// Bubble Sort included
	for (int i = 0; i < array.size() - 1; i++)
	{
		bool swapped = false;
		for (int j = 0; j < array.size() - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(array[j], array[j + 1]);
				swapped = true;
				++counter;
			}
		}
		
		if (!swapped)
			break;
	}
	return counter;
}


// Test in main() are beautiful
int main()
{
	vector<double> testArray;
	const unsigned long sizeOfArr = 10;
	double temp = .0;
	
	// Input testArray
	for (int i = 0; i < sizeOfArr; ++i)
	{
		cin >> temp;
		testArray.push_back(temp);
	}
	
	int swap_counter = combSort(testArray);
	
	cout << "Sorted array" << endl;
	
	for (auto item : testArray)
	{
		cout << item << " ";
	}
	
	cout << endl << "Number of 'swaps' " << swap_counter;
	return 0;
}
