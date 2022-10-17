cmake_minimum_required(VERSION 3.14)
project(Stack)
message("Stack CMake")

set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-fprofile-arcs -ftest-coverage -fPIC -O0")

set(Stack_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE)
#message("Stack_INCLUDE_DIRS = ${Stack_INCLUDE_DIRS}")
