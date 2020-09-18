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

#[[find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(DOXYGEN_INPUT ${CMAKE_SOURCE_DIR})
    CONFIGURE_FILE(${CMAKE_SOURCE_DIR}/doxygen.conf.in ${CMAKE_CURRENT_BINARY_DIR}/doxygen.conf)
    ADD_CUSTOM_TARGET(doc COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/doxygen.conf)
ELSE(DOXYGEN_FOUND)
    MESSAGE(STATUS "WARNING: Doxygen not found - Reference manual will not be created")
ENDIF(DOXYGEN_FOUND)]]

find_package(Doxygen)
if (DOXYGEN_FOUND)
    set(DOXYGEN_USE_MATHJAX YES)
    doxygen_add_docs(docs ${PROJECT_SOURCE_DIR}/src)
else ()
    message("Doxygen need to be installed to generate the documentation")
endif ()
