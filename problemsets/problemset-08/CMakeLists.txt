cmake_minimum_required(VERSION 3.12)

# Define all source files
#set(TASKS_SRCS  tasks/...)

# Define all tests
set(TESTS   utests/utest-task-81.cpp)

add_executable(problemset-08 ${TASKS_SRCS} ${TESTS})
target_link_libraries(problemset-08 gmock gtest gtest_main pthread)