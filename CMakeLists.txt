cmake_minimum_required(VERSION 3.13)
project(algorithms)
set(CMAKE_CXX_STANDARD 14)


include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(SRC src/main.cpp)
set(TEST_SRC test/example.cpp)
enable_testing()

add_executable(testbin ${TEST_SRC})
target_link_libraries(testbin gtest_main)
include(GoogleTest)
gtest_discover_tests(testbin)


add_executable(app ${SRC})

add_custom_command(TARGET testbin POST_BUILD
    COMMAND ./testbin)