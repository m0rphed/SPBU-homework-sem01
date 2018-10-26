cmake_minimum_required(VERSION 3.12)
project(spbu-homework)

add_definitions(-std=gnu++0x)

# Set C++11 standart
set(CMAKE_CXX_STANDARD 11)

## Locate GTest
#find_package(GTest REQUIRED)
#include_directories(${GTEST_INCLUDE_DIRS})

# Locate solutions for problemsets
#include_directories(problemsets)
#
#set(    SOURCE_FILES
#        problemsets/testwork-second-try/task01.cpp)

#        problemsets/problemset-02/arrayHelpers.cpp
#        problemsets/problemset-02/task-21-fibonacci.cpp
#        problemsets/problemset-02/task-22-power.cpp
#        problemsets/problemset-02/task-23-counting-bubbles.cpp
#        problemsets/problemset-02/task-24-sort-rand-array.cpp
#        unit-tests/utest-task-21.cpp
#        unit-tests/utest-task-22.cpp
#        unit-tests/utest-task-23.cpp
#        unit-tests/utest-task-24.cpp
#        unit-tests/utest-task-31.cpp
#        unit-tests/utest-task-41.cpp
#        problemsets/problemset-03/task-31-quicksort.cpp)

#add_executable(spbuHomeWork ${SOURCE_FILES})

# Link current run-configuration with what we want to test and the GTest and pthread library
# (spbuHomeWork ${GTEST_LIBRARIES} gtest_main pthread)
# target_link_libraries(spbuHomeWork)
add_executable(task02 problemsets/testwork-second-try/task02.cpp)
add_executable(task01 problemsets/testwork-second-try/task01.cpp)
add_executable(task03 problemsets/testwork-second-try/task03.cpp)