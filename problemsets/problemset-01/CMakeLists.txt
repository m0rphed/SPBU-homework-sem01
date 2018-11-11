cmake_minimum_required(VERSION 3.12)

# Define all source files
set(TASKS_SRCS tasks/task-11-polynomial.cpp)

# Define all tests
set(TESTS utests/utest-task-11.cpp)

add_executable(problemset-01 ${TASKS_SRCS} ${TESTS})
target_link_libraries(problemset-01 gtest gtest_main pthread)
