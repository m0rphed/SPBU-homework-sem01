cmake_minimum_required(VERSION 3.12)

# Define all homework files
set(TASKS_SRCS  Queue.cpp
                testwork-task01-requests.cpp)

# Define all tests
set(TESTS unitTest-process-calendar.cpp)

add_executable(testwork-2-5 ${TASKS_SRCS}
                            ${TESTS})

target_link_libraries(testwork-2-5 gtest gtest_main pthread)
