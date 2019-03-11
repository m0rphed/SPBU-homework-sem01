cmake_minimum_required(VERSION 3.12)

# Define all homework files
set(TASKS_SRCS  Graph/task-10-graph-of-roads.cpp
                Graph/graph.cpp
                Graph/dataInput.cpp
                Graph/dataOutput.cpp)

# Define all tests
set(TESTS   unitTests/utest-task-10.cpp)

add_executable(problemset-10    ${TASKS_SRCS}
                                ${TESTS})

target_link_libraries(problemset-10 gmock gtest pthread)