#pragma once

#include "../dataStructures/BinarySearchTree.h"
#include <fstream>
#include <string>

void writeToFile(std::ofstream &output, BinarySearchTree *myTree);

void *processData(std::string inputFile, std::string outputFile, BinarySearchTree *myTree);
