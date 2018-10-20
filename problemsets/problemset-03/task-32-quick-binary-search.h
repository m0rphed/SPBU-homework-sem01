#ifndef SPBU_HOMEWORK_TASK_32_QUICK_BINARY_SEARCH_H
#define SPBU_HOMEWORK_TASK_32_QUICK_BINARY_SEARCH_H


int binarySearch(int *array, int length, int item);


// | qBinarySearch function:
// | do quickSort() for an array (which size = n):                      => O(n*log(n))
// | do binarySearch() for arrayOfNums (which contains k numbers):      => O(k*log(n))
// | expected time complexity:                                          => O(n*log(n) + k*log(n))
void qBinarySearch(int *array, const int n, int *arrayOfNums, const int k, int *foundMatches);


#endif //SPBU_HOMEWORK_TASK_32_QUICK_BINARY_SEARCH_H
