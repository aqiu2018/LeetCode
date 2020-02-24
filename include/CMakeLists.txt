aux_source_directory(. LEETCODE)
set(CMAKE_BUILD_TYPE Debug)
add_library(leetcode ${LEETCODE})

message(STATUS "leetcode library: " ${LEETCODE})