cmake_minimum_required(VERSION 3.0.0)
project(algorithms VERSION 1.0)

option(USE_SOME_OPTION "Some option" ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov" )

configure_file(algorithmsConfig.h.in algorithmsConfig.h)

file(GLOB SOURCES main.cpp 
                    Sort/*/*.cpp)
file(GLOB INCLUDE_DIRS "Sort/BubbleSort")

# add_subdirectory(Sort)
# message("SOURCES = ${SOURCES}")

include_directories("Sort/BubbleSort")

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC
                           ${PROJECT_BINARY_DIR}
                           ${INCLUDE_DIRS}
                           )