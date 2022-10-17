cmake_minimum_required(VERSION 3.14)
project(search)
message("Search CMake")

set(CMAKE_CXX_STANDARD 11)

set(Search_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/BinarySearch PARENT_SCOPE)
#message("Search_INCLUDE_DIRS = ${Search_INCLUDE_DIRS}")
