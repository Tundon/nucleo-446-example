project(unit-tests LANGUAGES C CXX)

# Specify the CMake version
cmake_minimum_required(VERSION 3.0)

# Set the CMake generator to MinGW
set(CMAKE_GENERATOR "MinGW Makefiles")

# Set the path to the MinGW toolchain
# set(CMAKE_C_COMPILER "C:/ProgramData/chocolatey/bin/gcc.exe")
# set(CMAKE_CXX_COMPILER "C:/ProgramData/chocolatey/bin/g++.exe")

# Set the flags for the compiler
# set(CMAKE_CXX_FLAGS "-std=c++11 -Wall")

# Specify the search paths for MinGW libraries
# set(CMAKE_FIND_ROOT_PATH "C:/ProgramData/chocolatey/lib/mingw")

# Fetch and make Google Test available
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_compile_definitions(GTEST_HAS_PTHREAD)

file(GLOB_RECURSE SOURCES "*.*")

add_executable(${PROJECT_NAME}.exe ${SOURCES})
target_link_libraries(${PROJECT_NAME}.exe gtest gtest_main pthread)
# include(GoogleTest)
# gtest_discover_tests(${PROJECT_NAME}.exe)
