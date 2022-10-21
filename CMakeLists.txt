cmake_minimum_required(VERSION 3.14)
project(algorithms)

# options
option(DEBUG "Debug")
set(DEBUG ON)
option(RELEASE "Release")
set(RELEASE OFF)
option(SANITIZER "Sanitizer")
set(SANITIZER ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# compiler and linker setup
if (DEBUG)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -DDEBUG")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wpedantic -Wextra -Werror")

    if (SANITIZER)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address,undefined,leak -fno-sanitize-recover=all -fsanitize-undefined-trap-on-error")
    endif ()

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov")
elseif (RELEASE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g0 -DNDEBUG")
endif ()
message("CMAKE_CXX_FLAGS =${CMAKE_CXX_FLAGS}")
message("CMAKE_EXE_LINKER_FLAGS =${CMAKE_EXE_LINKER_FLAGS}")

# headers
set(Bit_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/Bit/BitOperation)
set(Sort_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/Sort/BubbleSort
        ${CMAKE_CURRENT_SOURCE_DIR}/Sort/MergeSort)
set(Search_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/Search)
set(Arrays_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/Arrays/Intersection)
set(DynamicArray_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/DynamicArray)
set(Stack_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/Stack)
set(Heap_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/Heap)
set(Queue_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/Queue)
set(Common_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})

# sources
file(GLOB_RECURSE SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Sort/*/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Bit/*/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Search/*/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Arrays/*/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/DynamicArray/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Stack/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Heap/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Queue/*.cpp
        )
#message("SOURCES = ${SOURCES}")

# executable
add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC
        ${PROJECT_BINARY_DIR}
        ${Sort_INCLUDE_DIRS}
        ${Bit_INCLUDE_DIRS}
        ${Search_INCLUDE_DIRS}/BinarySearch
        ${Search_INCLUDE_DIRS}/LinearSearch
        ${Arrays_INCLUDE_DIRS}
        ${DynamicArray_INCLUDE_DIRS}
        ${Stack_INCLUDE_DIRS}
        ${Heap_INCLUDE_DIRS}
        ${Queue_INCLUDE_DIRS}
        ${Common_INCLUDE_DIRS}
        )

# tests
enable_testing()
add_subdirectory(Tests)