add_library(
        equation_lib
        equation.cpp
)

add_executable(
        main
        main.cpp
)

target_link_libraries(
        main
        equation_lib
)