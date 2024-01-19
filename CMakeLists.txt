cmake_minimum_required(VERSION 3.27)
project(project)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined")

add_compile_options(-DLOCAL)
add_executable(main main.cpp)
add_executable(gen gen.cpp)
add_executable(stupid stupid.cpp)
add_executable(stress stress.cpp)