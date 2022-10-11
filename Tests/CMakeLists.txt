cmake_minimum_required(VERSION 3.14)
project(test)

message("Test CMake")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-fprofile-arcs -ftest-coverage -O0")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov" )

file(GLOB SOURCES *.cpp)

find_package(GTest REQUIRED)

# message("-------------------------NOW-----------")
# message("SORT_INC_DIRS = ${SORT_INC_DIRS}")
# message("------------------------------------")
# exec_program("pwd")


include_directories( ${Sort_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${SOURCES})

# target_include_directories(${PROJECT_NAME} PUBLIC ${FIB_LIB_INCLUDE_DIRS})

# include_directories( "/root/c-cpp-infrastructure-test/Sort/BubbleSort")

target_include_directories(${PROJECT_NAME} PUBLIC
                            ${Sort_INCLUDE_DIRS}
                           )

target_link_libraries(${PROJECT_NAME} GTest::gtest_main)