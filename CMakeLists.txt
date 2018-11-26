cmake_minimum_required(VERSION 2.6)
project(Logger)

set (CMAKE_CXX_STANDARD 11)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} Source Include)

ADD_LIBRARY(Logger Source/Logger.cpp)

# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests Test/LoggerTestSuite.cpp)
target_link_libraries (runTests ${GTEST_LIBRARIES} gtest_main pthread Logger)
