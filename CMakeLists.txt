cmake_minimum_required(VERSION 3.14)
project(algorithms VERSION 1.0)

option(USE_SOME_OPTION "Some option" ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov")

configure_file(algorithmsConfig.h.in algorithmsConfig.h)

add_subdirectory(Bit)
add_subdirectory(Sort)

message("Project CMake")
file(GLOB_RECURSE SOURCES
        main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Sort/**/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Bit/**/*.cpp
        )

message("SOURCES = ${SOURCES}")

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC
        ${PROJECT_BINARY_DIR}
        ${Sort_INCLUDE_DIRS}
        ${Bit_INCLUDE_DIRS}
        )

add_subdirectory(Tests)


# Do from project dir
# Create Build command
# cmake -B ./cmake-build-debug -S. -D CMAKE_BUILD_TYPE=Debug

# build command
# cmake --build cmake-build-debug/