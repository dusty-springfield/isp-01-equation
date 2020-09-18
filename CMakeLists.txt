cmake_minimum_required(VERSION 3.14)

project(isp-01-equation)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_FLAGS "-Wall -Wextra -Wfloat-equal")

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(gtest/googletest-master)

link_directories(src)
link_directories(test)

include_directories(gtest/googletest-master/googletest/include)
include_directories(gtest/googletest-master/googlemock/include)

find_package(Doxygen)
if (DOXYGEN_FOUND)
    doxygen_add_docs(docs ${PROJECT_SOURCE_DIR}/src)
else ()
    message("Doxygen need to be installed to generate the documentation")
endif ()
