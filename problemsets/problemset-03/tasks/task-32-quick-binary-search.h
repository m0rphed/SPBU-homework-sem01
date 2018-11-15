#pragma once


int binarySearch(int *array, int length, int item);


// | qBinarySearch function:
// | do quickSort() for an array (which size = n):                      => O(n*log(n))
// | do binarySearch() for arrayOfNums (which contains k numbers):      => O(k*log(n))
// | expected time complexity:                                          => O(n*log(n) + k*log(n))
void qBinarySearch(int *array, int n, int *arrayOfNums, int k, bool *foundMatches);