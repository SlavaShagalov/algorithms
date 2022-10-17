cmake_minimum_required(VERSION 3.14)
project(arrays)
message("Arrays CMake")

set(CMAKE_CXX_STANDARD 11)

# set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-fprofile-arcs -ftest-coverage -fPIC -O0")

set(Arrays_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/Intersection PARENT_SCOPE)
#message("Arrays_INCLUDE_DIRS = ${Arrays_INCLUDE_DIRS}")
