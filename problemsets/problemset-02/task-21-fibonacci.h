#ifndef SPBU_HOMEWORK_TASK_01_FIBONACCI_H
#define SPBU_HOMEWORK_TASK_01_FIBONACCI_H


int matrixFib(int n);
// Function calculates Fibonacci numbers using power of the matrix {{1,1}, {1,0}}
// expected time complexity: O(log n)


void matrixMultiply(int firstMatrix[2][2], int secondMatrix[2][2]);
// Helper function that multiplies 2 matrices firstMatrix and secondMatrix of size 2*2, and
// puts the multiplication result back to firstMatrix[2][2].
// Function is used only by matrixFib()


void matrixPower(int first[2][2], int n);
// Helper function that Function calculates matrix[2][2] raise to the power n and puts the
// result in matrix[2][2].
// Function is used only by matrixFib()


long long recursiveFib(long long n); // Function calculates Fibonacci numbers using recursion


long long iterativeFib(int n); // Function calculates Fibonacci numbers using while loop


long long analyticFib(unsigned n); // Function calculates Fibonacci numbers using Binet's Formula


#endif //SPBU_HOMEWORK_TASK_01_FIBONACCI_H