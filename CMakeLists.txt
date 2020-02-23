project(LeetCode)

# CMake version >= 3.10 due to gtest_discover_tests()
# See https://cmake.org/cmake/help/git-stage/module/GoogleTest.html
cmake_minimum_required(VERSION 3.10)

if (POLICY CMP0048)
    cmake_policy(SET CMP0048 NEW)
endif()

set(CMAKE_C_COMPILER "C:/MinGW/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/MinGW/bin/g++.exe")
set(CMAKE_EXE_LINKER_FLAGS  "-static-libgcc -static-libstdc++")
set(CMAKE_CXX_FLAGS "-Wno-deprecated-declarations")

enable_testing()
find_package(Threads REQUIRED)

set(googleTestDir "E:/leetcode/googletest")
add_subdirectory(${googleTestDir} googletest.out)
include_directories(${googleTestDir}/googletest/include)
include_directories(${googleTestDir}/googlemock/include)
#find_package(GTest REQUIRED)
#include_directories(${CMAKE_SOURCE_DIR}/include)
#include_directories(${GTEST_INCLUDE_DIR})

include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(include)
add_subdirectory(test)
add_subdirectory(src)