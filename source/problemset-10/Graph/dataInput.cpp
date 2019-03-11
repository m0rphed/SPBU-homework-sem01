#include "dataInput.h"
#include "graph.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

DataInput *readDataInputFromFile(const char *fileName)
{

    auto *dataInput = new DataInput();
    ifstream input(fileName, ios::in);

    // Во входном файле: n – число городов и m – число дорог
    input >> dataInput->citiesCount;
    input >> dataInput->roadsCount;

    for (int i = 0; i < dataInput->roadsCount; ++i)
    {
        auto *r = new DataInputPerRoad();
        // Далее следуют сами дороги в формате: i j len, i и j – номера городов, len – длина дороги
        input >> r->cityFrom >> r->roadLength >> r->cityTo;
        dataInput->roads.push_back(*r);
    }

    // Далее задано число k – число столиц, далее – k чисел – номера столиц.
    input >> dataInput->countriesCount;
    for (int j = 0; j < dataInput->countriesCount; ++j)
    {
        int cityNumber;
        input >> cityNumber;
        dataInput->capitalsPerCountry.push_back(cityNumber);
    }

    return dataInput;
}