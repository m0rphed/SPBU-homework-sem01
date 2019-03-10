#include "task-10-graph-of-roads.h"
#include <gtest/gtest.h> // Google Test Framework


struct CountryData
{
    std::vector<Vertex *> AllocatesCities;
};


bool allocateNearestCity(Graph *g, CountryData *c)
{
}


void buildWorld(DataInput *dInput, DataOutput *dOutput)
{

    Graph *g = newGraph();
    std::vector<CountryData *> countries;

    // Registers two way road with length
    for (int i = 0; i < dInput->roads.size(); ++i)
    {
        DataInputPerRoad road = dInput->roads[i];
        Edge *eForward = addEdge(g, road.cityTo, road.cityFrom);
        eForward->roadLength = road.roadLength;
        Edge *eBackward = addEdge(g, road.cityFrom, road.cityTo);
        eBackward->roadLength = road.roadLength;
    }

    // Appends capitals for each country
    for (int i = 0; i < dInput->capitalsPerCountry.size(); ++i)
    {
        auto *aCountry = new CountryData();
        Vertex *v = getVertex(g, dInput->capitalsPerCountry[i]);
        aCountry->AllocatesCities.push_back(v);
        countries.push_back(aCountry);

    }

    bool allocatedAnyCity = false;
    do
    {
        for (int j = 0; j < countries.size(); j++)
        {
            if (allocateNearestCity(g, countries[j]))
            {
                allocatedAnyCity = true;
            }
        }
    } while (allocatedAnyCity);
}


// Sample of input:
//
//
// 9       - number of cities
// 11      - number or roads
// 1 2 2
// 1 3 1
// 1 9 15
// 3 4 18
// 3 7 8
// 4 5 4
// 5 6 43
// 6 7 21
// 7 8 10
// 7 9 30
// 8 9 9
// 3       - number of countries (each country has 1 capital)
// 2 1 4   - each capital (1 per country)
//
//
// Plan:
//
// - create graph
// - create list of countries
// - mark capitals as allocated
// - every time
// - find adjacent nodes for all existing (not allocated)
// - select and allocate the node


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}