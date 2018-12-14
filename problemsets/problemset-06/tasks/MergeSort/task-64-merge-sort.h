#pragma once

namespace mergeSort
{
	
	void printArray(int *array, int n);
	
	void merge(int *array, int low, int mid, int high);
	
	void mergeSort(int *array, int low, int high);
}