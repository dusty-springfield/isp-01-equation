add_executable(
        my_test
        my_test.cpp
)

target_link_libraries(
        my_test
        equation_lib
)

add_executable(
        g_test
        test.cpp
)

target_link_libraries(
        g_test
        equation_lib
        gtest
        gtest_main
)