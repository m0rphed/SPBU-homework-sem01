#ifndef SPBU_HOMEWORK_ARRAYHELPERS_H
#define SPBU_HOMEWORK_ARRAYHELPERS_H


void fillArray(int myArray[], int size, int min = 0, int max = 1000, bool isRandom = true);
// Func. fills an array with values.
// values are random by default ( using randomizeArray() ).
// If isRandom = false, then the values will be a sequence of integers from 'min' to 'max'.


void copyArray(int arrayCopy[], int originalArray[], int size);
// Func. makes a copy of the ordinal array (the second argument).


void randomizeArray(int myArray[], int size, int min = 0, int max = 1000);
// Func. fills an array with random values
// in a range from 'min' to 'max'
// using srand() and rand() func. from stdlib.h.
// Can be used without fillArray().


int compareIncreasing(const void *first, const void *second);
// Func. compares 2 integers,
// returns 1 if the first argument is greater
// otherwise, it returns -1
// if something went completely wrong, it returns 0.


void findMinMax(int const *array, int size, int &min, int &max); // find smallest 'min' and highest 'max'


#endif //SPBU_HOMEWORK_ARRAYHELPERS_H