add_library(
        equation_lib
        equation.cpp
        )

add_executable(
       app
        main.cpp
)

target_link_libraries(
        app
        equation_lib
)