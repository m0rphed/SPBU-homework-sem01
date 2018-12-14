cmake_minimum_required(VERSION 3.12)


set(DS dataStructures/LinkedList.cpp dataStructures/LinkedList.h) # Defines all using data structures

# Define all source files
set(TASKS_SRCS  bossFight-task01.cpp
                bossFight-task02.cpp
                bossFight-task03.cpp)

## Define all tests
#set(TESTS   unitTests/unitTest-task01.cpp
#            unitTests/unitTest-task02.cpp
#            unitTests/unitTest-task03.cpp)

#add_executable(bossFight    ${DS}
#                            ${TASKS_SRCS}
#                            ${TESTS})
add_executable(bossFight-task01-manaul-test ${DS} ${TASKS_SRCS} bossFight-task01.cpp)
#target_link_libraries(bossFight gtest gtest_main pthread)