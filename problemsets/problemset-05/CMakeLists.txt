cmake_minimum_required(VERSION 3.12)

# Define all source files
set(TASKS_SRCS  tasks/LinkedList/task-51-linked-list.cpp
                tasks/JosephusProblem/task-52-circular-linked-list.cpp)

# Define all test fixture
set(TEST_FIXTURES   testFixtures/LinkedListFixture.cpp
                    testFixtures/CircularListFixture.cpp)

# Define all tests
set(TESTS   utests/utest-task-51.cpp
            utests/utest-task-52.cpp)

add_executable(problemset-05    ${TASKS_SRCS}
                                ${TESTS}
                                ${TEST_FIXTURES})

target_link_libraries(problemset-05 gmock gtest gtest_main pthread)