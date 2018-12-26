cmake_minimum_required(VERSION 3.12)

# Define all homework files
set(TASKS_SRCS task-01-isPalindrome.cpp)

# Define all tests
set(TESTS utests/utest-task-01-isPalindrome.cpp)

add_executable(testwork-third-try ${TASKS_SRCS} ${TESTS})
target_link_libraries(testwork-third-try gtest gtest_main pthread)