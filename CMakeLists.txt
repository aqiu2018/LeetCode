project(LeetCode)

# CMake version >= 3.10 due to gtest_discover_tests()
# See https://cmake.org/cmake/help/git-stage/module/GoogleTest.html

# Project: https://github.com/Pokerpoke/LeetCode
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_BUILD_TYPE Debug)

enable_testing()
find_package(Threads REQUIRED)
find_package(GTest REQUIRED)
message(STATUS "GTest path: " ${GTEST_INCLUDE_DIR})

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${GTEST_INCLUDE_DIR})

add_subdirectory(include)

add_subdirectory(test)
add_subdirectory(src)