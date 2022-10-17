cmake_minimum_required(VERSION 3.14)
project(algorithms)

# options
option(BUILD_TESTS "Build tests")
set(BUILD_TESTS OFF)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

message("Main CMake")

if (BUILD_TESTS)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wpedantic -Wextra -Werror -fprofile-arcs -ftest-coverage -O0")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov")
endif ()
message("CMAKE_CXX_FLAGS =${CMAKE_CXX_FLAGS}")
message("CMAKE_EXE_LINKER_FLAGS =${CMAKE_EXE_LINKER_FLAGS}")

add_subdirectory(Bit)
add_subdirectory(Sort)
add_subdirectory(Search)
add_subdirectory(Arrays)
add_subdirectory(DynamicArray)
add_subdirectory(Stack)
add_subdirectory(Queue)

# sources
file(GLOB_RECURSE SOURCES
        main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Sort/**/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Bit/**/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Search/**/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Arrays/**/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/DynamicArray/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Stack/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Queue/*.cpp
        )
#message("SOURCES = ${SOURCES}")

# program
add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC
        ${PROJECT_BINARY_DIR}
        ${Sort_INCLUDE_DIRS}
        ${Bit_INCLUDE_DIRS}
        ${Search_INCLUDE_DIRS}
        ${Arrays_INCLUDE_DIRS}
        ${DynamicArray_INCLUDE_DIRS}
        ${Stack_INCLUDE_DIRS}
        ${Queue_INCLUDE_DIRS}
        )

# tests
enable_testing()
add_subdirectory(Tests)

# How to create build directory
# cmake -B ./cmake-build-debug -S. -D CMAKE_BUILD_TYPE=Debug

# How to build
# cmake --build cmake-build-debug/

# cov
#lcov -t "tests/tests_fib" -o coverage.info -c -d fib_lib/

# html result
#genhtml -o report coverage.info