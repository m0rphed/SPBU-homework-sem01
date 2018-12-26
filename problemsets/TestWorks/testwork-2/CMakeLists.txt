cmake_minimum_required(VERSION 3.12)

set(DS dataStructures.cpp) # Defines all using data structures

# Define all source files
set(TASKS_SRCS  task01.cpp
                task02.cpp)

# Define all tests
set(TESTS   unitTests/unitTest-task01.cpp
            unitTests/unitTest-task02.cpp)

add_executable(testwork-2   ${DS}
                            ${TASKS_SRCS}
                            ${TESTS})

target_link_libraries(testwork-2 gtest gtest_main pthread)