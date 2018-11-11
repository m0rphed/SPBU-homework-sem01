cmake_minimum_required(VERSION 3.12)

# Define all source files
#set(TASKS_SRCS  tasks/...)

# Define all tests
set(TESTS   utests/utest-task-71.cpp
            utests/utest-task-72.cpp)

add_executable(problemset-07 ${TASKS_SRCS} ${TESTS})
target_link_libraries(problemset-07 gmock gtest gtest_main pthread)