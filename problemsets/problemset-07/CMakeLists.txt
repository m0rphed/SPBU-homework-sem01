cmake_minimum_required(VERSION 3.12)

# Define all source files
set(TASK71_SRCS tasks/AbstractDataType-Set/BinarySearchTree.cpp
                tasks/AbstractDataType-Set/Set.cpp
                tasks/AbstractDataType-Set/DoublyLinkedList.cpp
                tasks/AbstractDataType-Set/task-71-set.cpp)

# Define all tests
set(TESTS   utests/utest-task-71.cpp
            utests/utest-task-72.cpp)

add_executable(problemset-07 ${TASK71_SRCS} ${TESTS})
target_link_libraries(problemset-07 gmock gtest pthread)