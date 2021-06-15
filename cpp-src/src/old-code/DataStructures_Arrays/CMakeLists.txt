cmake_minimum_required(VERSION 3.5)

project(PROBLEM_SOLVING LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(array_manipulation main_array_manipulation.cpp)
target_compile_definitions(array_manipulation PUBLIC LOCAL)
