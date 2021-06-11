cmake_minimum_required(VERSION 3.5)

project(CPP LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Deque-STL-slow main_slow.cpp)
add_executable(Deque-STL-set main_set.cpp)
target_compile_definitions(Deque-STL-set PUBLIC LOCAL)
add_executable(Deque-STL-index main_index.cpp)
target_compile_definitions(Deque-STL-index PUBLIC LOCAL)


add_executable(Variadic main_variadic.cpp)
target_compile_definitions(Variadic PUBLIC LOCAL)

add_executable(BitArray main_bit_array.cpp)
target_compile_definitions(BitArray PUBLIC LOCAL)
