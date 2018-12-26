#pragma once


// Solution for the case when the range of values is known.
// This is the first idea, that came in my mind
//   => I do not want to delete it, besides the solution is working, but for another case.
namespace sillySolution
{
	int findMostFrequent(int *array, int *frequencyValues, int size);
}


// More effective universal solution
namespace smartSolution
{
	int findMostFrequent(int *array, int size);
}
