cmake_minimum_required(VERSION 3.12)

# Define all homework files
set(TASKS_SRCS  tasks/LastInFirstOut.cpp
                tasks/ReversePolishNotation/task-61-postfix-notation.cpp
                tasks/BracketCounter/task-62-counting-brackets.cpp
                tasks/ShuntingYard/task-63-shunting-yard-algorithm.cpp)

# Define all tests
set(TESTS   utests/utest-task-61.cpp
            utests/utest-task-62.cpp
            utests/utest-task-63.cpp
            utests/utest-task-64.cpp)

add_executable(problemset-06 ${TASKS_SRCS} ${TESTS})
target_link_libraries(problemset-06 gmock gtest gtest_main pthread)