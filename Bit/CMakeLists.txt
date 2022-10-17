cmake_minimum_required(VERSION 3.14)
project(bit)
message("Bit CMake")

set(CMAKE_CXX_STANDARD 11)

set(Bit_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/BitOperation PARENT_SCOPE)
#message("Bit_INCLUDE_DIRS = ${Bit_INCLUDE_DIRS}")
