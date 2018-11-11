cmake_minimum_required(VERSION 3.12)

# Define helper functions
set(HELPERS ../HelperFunctions/arrayHelpers.cpp)

# Define all source files
set(TASKS_SRCS  tasks/task-21-fibonacci.cpp
                tasks/task-22-power.cpp
                tasks/task-23-counting-bubbles.cpp
                tasks/task-24-sort-rand-array.cpp)

# Define all tests
set(TESTS   utests/utest-task-21.cpp
            utests/utest-task-22.cpp
            utests/utest-task-23.cpp
            utests/utest-task-24.cpp)

add_executable(problemset-02 ${HELPERS} ${TASKS_SRCS} ${TESTS})
target_link_libraries(problemset-02 gmock gtest gtest_main pthread)
