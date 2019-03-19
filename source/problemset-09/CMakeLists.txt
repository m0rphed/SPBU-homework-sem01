cmake_minimum_required(VERSION 3.12)

# Define all homework files
set(TASKS_SRCS ...)

# Define all tests
#set(TESTS ...)

#add_executable(problemset-09    ${TASKS_SRCS}
#                                ${TESTS})
#
#target_link_libraries(problemset-09 gmock gtest gtest_main pthread)

# Define all source files here
set(BracketCounter_sources  LetsMakeItQuick/BracketCounterSourceFiles/LastInFirstOut.cpp
                            LetsMakeItQuick/BracketCounterSourceFiles/task-62-counting-brackets.cpp)


# Define all tests
set(TESTS LetsMakeItQuick/BracketCounterSourceFiles/utest-task-62.cpp)

add_executable(Task62WithTests  ${BracketCounter_sources}
                                ${TESTS})

add_executable(Task62WithMain   ${BracketCounter_sources}
                                LetsMakeItQuick/BracketCounterSourceFiles/test.cpp)

target_link_libraries(Task62WithTests gmock gtest gtest_main pthread)
