cmake_minimum_required(VERSION 3.12)

# Defines all using data structures
#set(DS_01  dataStructures/...)
#set(DS_02  dataStructures/...)
#set(DS_03  dataStructures/...)

# Define all homework files
set(SRCS    tasks/task-01.cpp
            tasks/task-02.cpp
            tasks/task-03.cpp)

# Define all tests
set(TESTS   unitTests/unitTest-task-01.cpp
            unitTests/unitTest-task-02.cpp
            unitTests/unitTest-task-03.cpp)

add_executable(bossFight2   ${SRCS}
                            ${DS_01} ${DS_02} ${DS_03}
                            ${TESTS})

add_executable(bossFight2-task-01 ${DS_01} tasks/task-01.cpp)
add_executable(bossFight2-task-02 ${DS_02} tasks/task-02.cpp)
add_executable(bossFight2-task-03 ${DS_03} tasks/task-03.cpp)

#target_link_libraries(bossFight2 gtest pthread)