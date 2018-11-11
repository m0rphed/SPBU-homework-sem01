cmake_minimum_required(VERSION 3.12)

# Define all source files
set(TASKS_SRCS  tasks/task-43-phonebook.cpp)

# Define all tests
set(TESTS   utests/utest-task-41.cpp
            utests/utest-task-42.cpp
            utests/utest-task-43.cpp)

add_executable(problemset-04 ${TASKS_SRCS} ${TESTS})
target_link_libraries(problemset-04 gmock gtest gtest_main pthread)