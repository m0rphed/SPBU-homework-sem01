cmake_minimum_required(VERSION 3.12)

# Define all source files
set(TASKS_SRCS  testwork-2-4-matrix-sort.cpp)

# Define all tests
set(TESTS       unitTest-matrix-sort.cpp)

add_executable(testwork-2-4 ${TASKS_SRCS} ${TESTS})
target_link_libraries(testwork-2-4 gtest gtest_main pthread)