cmake_minimum_required(VERSION 3.12)

# Define all homework files
set(TASK_71_SRCS    tasks/SetOnBinTree/task-71-userInterface.cpp
                    tasks/SetOnBinTree/Set.cpp)

set(TASK_72_SRCS    tasks/ExpressionParsingTree/AbstractSyntaxTree.cpp
                    tasks/ExpressionParsingTree/task-72-parsing-tree.cpp)

# Define all tests
set(TESTS   unitTests/utest-task-71.cpp
            unitTests/utest-task-72.cpp)

add_executable(problemset-07 ${TASK_71_SRCS} ${TASK_72_SRCS} ${TESTS})
add_executable(taks72 ${TASK_72_SRCS} unitTests/utest-task-72.cpp)

target_link_libraries(problemset-07 gmock gtest gtest_main pthread)
target_link_libraries(taks72 gmock gtest gtest_main pthread)