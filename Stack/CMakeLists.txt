cmake_minimum_required(VERSION 3.14)
project(Stack)

message("Stack CMake")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-Wall -Wextra -Wpedantic -Werror")
# set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-fprofile-arcs -ftest-coverage -fPIC -O0")

file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

# message("SOURCES = ${SOURCES}")
# message("HEADERS = ${HEADERS}")

set(Stack_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE)

message("Stack_INCLUDE_DIRS = ${Stack_INCLUDE_DIRS}")
