cmake_minimum_required(VERSION 3.14)
project(Tests)

message("Tests CMake")

set(CMAKE_CXX_STANDARD 11)

#if (BUILD_TESTS)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage -O0")
# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov")
#endif ()
message("CMAKE_CXX_FLAGS =${CMAKE_CXX_FLAGS}")
message("CMAKE_EXE_LINKER_FLAGS =${CMAKE_EXE_LINKER_FLAGS}")

file(GLOB SOURCES
        *.cpp
        ${Sort_INCLUDE_DIRS}/*.cpp
        ${Bit_INCLUDE_DIRS}/*.cpp
        ${Search_INCLUDE_DIRS}/*.cpp
        ${Arrays_INCLUDE_DIRS}/*.cpp
        )
#message("TEST SOURCES = ${SOURCES}")

find_package(GTest REQUIRED)
add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC
        ${Sort_INCLUDE_DIRS}
        ${Bit_INCLUDE_DIRS}
        ${Search_INCLUDE_DIRS}
        ${Arrays_INCLUDE_DIRS}
        )
target_link_libraries(${PROJECT_NAME} GTest::gtest_main)

gtest_discover_tests(${PROJECT_NAME})