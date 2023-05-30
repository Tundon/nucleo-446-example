project(unit-tests C CXX ASM)

# Fetch and make Google Test available
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
)
FetchContent_MakeAvailable(googletest)

add_compile_definitions(GTEST_HAS_PTHREAD)

file(GLOB_RECURSE SOURCES "*.*")

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} gtest gtest_main pthread)
