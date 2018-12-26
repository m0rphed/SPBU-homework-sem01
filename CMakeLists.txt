cmake_minimum_required(VERSION 3.12)
project(spbu-homework)

# Set C++11 standart
set(CMAKE_CXX_STANDARD 11)

enable_testing()

# Let's CONFIGURE GTEST
# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
if (result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif ()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
if (result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif ()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
        ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
endif ()

# Locate solutions for homework-01
add_subdirectory(source/problemset-01)

# Locate solutions for homework-02
add_subdirectory(source/problemset-02)

# Locate solutions for homework-03
add_subdirectory(source/problemset-03)

# Locate solutions for homework-04
add_subdirectory(source/problemset-04)

# Locate solutions for homework-05
add_subdirectory(source/problemset-05)

# Locate solutions for homework-06
add_subdirectory(source/problemset-06)

# Locate solutions for homework-07
add_subdirectory(source/problemset-07)

# Locate solutions for homework-08
add_subdirectory(source/problemset-08)

# Locate solutions for homework-09
add_subdirectory(source/problemset-09)

# Locate solutions for homework-10
add_subdirectory(source/problemset-10)

# Locate solutions for homework-11
add_subdirectory(source/problemset-11)

# Locate solutions for testwork-01: second try
add_subdirectory(source/testworks/testwork-01-try-02)

# Locate solutions for testwork-01: third try
add_subdirectory(source/testworks/testwork-01-last)

# Locate solutions for testwork-02: last try
add_subdirectory(source/testworks/testwork-02-last)

# Locate solutions for testwork-02: first try
add_subdirectory(source/testworks/testwork-02-try-01)

# Locate solutions for testwork-02: third try
add_subdirectory(source/testworks/testwork-02-try-03)

# BOSS FIGHT <=> ЗАЧЁТ: 1ая попытка
add_subdirectory(source/testworks/bossFight-01)

# BOSS FIGHT <=> ЗАЧЁТ: 2ая попытка
add_subdirectory(source/testworks/bossFight-02)

set(SOURCE_FILES init_gtest.cpp)
add_executable(spbuHomeWork ${SOURCE_FILES})

# Link current run-configuration with what we want to test and the GTest and pthread library
target_link_libraries(spbuHomeWork gmock gtest_main pthread)
#add_executable(bossFight-task01 homework/testworks/bossFight-01/bossFight-task01.cpp)