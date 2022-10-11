cmake_minimum_required(VERSION 3.14)
project(sort)

message("Sort CMake")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-Wall -Wextra -Wpedantic -Werror")
# set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-fprofile-arcs -ftest-coverage -fPIC -O0")

file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*/*.cpp)
file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*/*.hpp ${CMAKE_CURRENT_SOURCE_DIR}/*/*.h)

message("SOURCES = ${SOURCES}")
message("HEADERS = ${HEADERS}")

set(Sort_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/BubbleSort/)
set(Sort_INCLUDE_DIRS ${Sort_INCLUDE_DIRS} PARENT_SCOPE)

message("Sort_INCLUDE_DIRS = ${Sort_INCLUDE_DIRS}")
