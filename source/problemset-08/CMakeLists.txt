cmake_minimum_required(VERSION 3.12)

# Define all source files
set(TaskSrcs    tasks/DictionaryOnAVLtree/Dictionary.cpp
                tasks/DictionaryOnAVLtree/userInterface.cpp)

# Define all unit tests
set(UnitTests   utests/utest-task-81.cpp)

add_executable(task-8-1 ${TaskSrcs} ${UnitTests})
target_link_libraries(task-8-1 gmock gtest gtest_main pthread)