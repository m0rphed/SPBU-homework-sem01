cmake_minimum_required(VERSION 3.12)

# Define all source files here
set(TaskSrcs-9.1 tasks/WordFrequency/LinkedList.cpp
                    tasks/WordFrequency/HashTable.cpp
                    tasks/WordFrequency/task-91-count-word-frequency.cpp)

# Define all tests here
set(Tests-9.1
        unitTests/utest-task-91.cpp)

add_executable(task-9.1     ${TaskSrcs-9.1}
                            ${Tests-9.1})

target_link_libraries(task-9.1 gmock gtest gtest_main pthread)