cmake_minimum_required(VERSION 3.14)
project(Queue)
message("Queue CMake")

set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-fprofile-arcs -ftest-coverage -fPIC -O0")

set(Queue_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE)
#message("Queue_INCLUDE_DIRS = ${Queue_INCLUDE_DIRS}")
