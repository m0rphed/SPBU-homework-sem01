cmake_minimum_required(VERSION 3.12)

# Define all source files for task-4.1
set(TASKS_41_SRCS tasks/task-41-bitwiseOperations/task-41-bitwise-operations.cpp)

# Define all source files for task-4.2
set(TASKS_42_SRCS   tasks/task-42-searchInFile/quickSortAlgorithm.cpp
                    tasks/task-42-searchInFile/mostFrequentElement.cpp
                    tasks/task-42-searchInFile/handleInput.cpp)

## Define all source code from another problemset
#set(PSET03_SRCS  ../problemset-03/tasks/task-33-most-frequent-element.cpp)

# Define all testFixtures
set(TEST_FIXTURES   testFixtures/NumberFixture.h
                    testFixtures/NumberFixture.cpp)

# Define all tests
set(TESTS   utests/utest-task-41.cpp
            utests/utest-task-42.cpp
            utests/utest-task-43.cpp)

add_executable(problemset-04    ${TASKS_41_SRCS}
                                ${TASKS_42_SRCS}
                                ${TESTS}
                                ${TEST_FIXTURES})
target_link_libraries(problemset-04 gmock gtest gtest_main pthread)