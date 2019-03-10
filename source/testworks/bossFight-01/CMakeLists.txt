cmake_minimum_required(VERSION 3.12)

# Defines all using data structures
set(DS  dataStructures/BinarySearchTree.cpp
        dataStructures/PriorityQueue.cpp)

#set(TASKS_SRCS  bossFight-task01.cpp
#                bossFight-task02.cpp
#                bossFight-task03.cpp)

# Define all tests
set(TESTS
        unitTests/unitTest-task03.cpp)

#add_executable(bossFight    ${DS}
#                            ${TASKS_SRCS}
#                            ${TESTS})

add_executable(bossFight-task01 ${DS} tasks/bossFight-task01.cpp)
add_executable(bossFight-task02 ${DS} tasks/bossFight-task02.cpp)

target_link_libraries(bossFight-task01 gmock gtest gtest_main pthread)
target_link_libraries(bossFight-task02 gmock gtest gtest_main pthread)
