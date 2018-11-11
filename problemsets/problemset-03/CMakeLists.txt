cmake_minimum_required(VERSION 3.12)

# Define helper functions
set(HELPERS ../HelperFunctions/arrayHelpers.cpp)

# Define all source files
set(TASKS_SRCS  tasks/task-31-quicksort.cpp
                tasks/task-33-most-frequent-element.cpp)

# Define all tests
set(TESTS   utests/utest-task-31.cpp
            utests/utest-task-32.cpp
            utests/utest-task-33.cpp)

add_executable(problemset-03 ${HELPERS} ${TASKS_SRCS} ${TESTS})
target_link_libraries(problemset-03 gmock gtest gtest_main pthread)