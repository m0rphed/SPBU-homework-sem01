cmake_minimum_required(VERSION 3.12)
project(spbu-homework)

add_definitions(-std=gnu++0x)

# Set C++11 standart
set(CMAKE_CXX_STANDARD 11)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

## Locate solutions for problemsets-01
#add_subdirectory(problemsets/problemset-01)
#
## Locate solutions for problemsets-02
#add_subdirectory(problemsets/problemset-02)
#
## Locate solutions for problemsets-03
#add_subdirectory(problemsets/problemset-03)
#
## Locate solutions for problemsets-04
#add_subdirectory(problemsets/problemset-04)
#
## Locate solutions for problemsets-05
#add_subdirectory(problemsets/problemset-05)
#
## Locate solutions for problemsets-06
#add_subdirectory(problemsets/problemset-06)
#
## Locate solutions for problemsets-07
#add_subdirectory(problemsets/problemset-07)

set(SOURCE_FILES init_gtest.cpp)
add_executable(spbuHomeWork ${SOURCE_FILES})

# Link current run-configuration with what we want to test and the GTest and pthread library
target_link_libraries(spbuHomeWork ${GTEST_LIBRARIES} gtest_main pthread)

