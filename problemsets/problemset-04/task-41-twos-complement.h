#ifndef SPBU_HOMEWORK_TASK_41_SUM_BIN_DEC_H
#define SPBU_HOMEWORK_TASK_41_SUM_BIN_DEC_H


struct Number
{
	int value = 0;
	unsigned int mask = 0;
};


void getNumberFromConsole(int &value);

unsigned int getBitMask(int number);

void printBinary(Number *n);

void initializeNumber(Number *n, int decimalValue);


#endif //SPBU_HOMEWORK_TASK_41_SUM_BIN_DEC_H
