project(unit-tests LANGUAGES C CXX)

# Specify the CMake version
cmake_minimum_required(VERSION 3.0)

# Set the CMake generator to MinGW
# set(CMAKE_GENERATOR "MinGW Makefiles")

# Fetch and make Google Test available
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_compile_definitions(GTEST_HAS_PTHREAD)

file(GLOB_RECURSE SOURCES "*.*")

add_executable(${PROJECT_NAME}.exe ${SOURCES})
target_link_libraries(${PROJECT_NAME}.exe gtest gtest_main pthread)
