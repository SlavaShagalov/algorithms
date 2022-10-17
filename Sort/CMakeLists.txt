cmake_minimum_required(VERSION 3.14)
project(sort)
message("Sort CMake")

set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-fprofile-arcs -ftest-coverage -fPIC -O0")

set(Sort_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/BubbleSort PARENT_SCOPE)
#message("Sort_INCLUDE_DIRS = ${Sort_INCLUDE_DIRS}")
