cmake_minimum_required(VERSION 3.10)

project(lab03 VERSION 1.0.0)

add_subdirectory(formatter_lib)
add_subdirectory(formatter_ex_lib)

add_executable(hello_world hello_world.cpp)

target_link_libraries(hello_world
    formatter_ex
)
