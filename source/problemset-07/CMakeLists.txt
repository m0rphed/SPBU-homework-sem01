cmake_minimum_required(VERSION 3.12)

# Define all homework files
set(TASK_71_SRCS    tasks/SetOnBinTree/task-71-userInterface.cpp
                    tasks/SetOnBinTree/Set.cpp)

# Define all tests
set(TESTS   unitTests/utest-task-71.cpp
            unitTests/utest-task-72.cpp)

add_executable(problemset-07 ${TASK_71_SRCS} ${TESTS})
target_link_libraries(problemset-07 gmock gtest gtest_main pthread)