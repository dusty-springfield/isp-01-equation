cmake_minimum_required(VERSION 3.14)
project(equation)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(gtest/googletest-master)

include_directories(gtest/googletest-master/googletest/include)
include_directories(gtest/googletest-master/googlemock/include)

add_executable(equation test/equation_test.cpp test/equation_my_test.cpp src/equation.cpp)
target_link_libraries(equation gtest gtest_main)