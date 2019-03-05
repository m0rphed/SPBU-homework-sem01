cmake_minimum_required(VERSION 3.12)

# Define all homework files for task-4.1
set(TASKS_41_SRCS   tasks/task-41-bitwiseOperations/bitwiseOperations.cpp)

# Define all homework files for task-4.2
set(TASKS_42_SRCS   tasks/task-42-searchInFile/quickSortAlgorithm.cpp
                    tasks/task-42-searchInFile/mostFrequentElement.cpp
                    tasks/task-42-searchInFile/handleInput.cpp)

# Define all homework files for task-4.2
set(TASKS_43_SRCS   tasks/task-43-phonebook/task-43-phonebook.cpp)

# Define all tests
set(TESTS   utests/utest-task-41.cpp
            utests/utest-task-42.cpp
            utests/utest-task-43.cpp)

add_executable(problemset-04-1  ${TASKS_41_SRCS}
                                utests/utest-task-41.cpp)

add_executable(problemset-04-2  ${TASKS_42_SRCS}
                                utests/utest-task-42.cpp)

add_executable(problemset-04-3  ${TASKS_43_SRCS}
                                utests/utest-task-43.cpp)

add_executable(problemset-04    ${TASKS_41_SRCS}
                                ${TASKS_42_SRCS}
                                ${TASKS_43_SRCS}
                                ${TESTS})

target_link_libraries(problemset-04 gmock gtest gtest_main pthread)
target_link_libraries(problemset-04-3 gmock gtest pthread)