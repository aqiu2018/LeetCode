if(EXISTS "/Users/aqiu/Documents/1_study/10_workspace/02_clion/LeetCode/cmake-build-debug/test/test_myLog[1]_tests.cmake")
  include("/Users/aqiu/Documents/1_study/10_workspace/02_clion/LeetCode/cmake-build-debug/test/test_myLog[1]_tests.cmake")
else()
  add_test(test_myLog_NOT_BUILT test_myLog_NOT_BUILT)
endif()