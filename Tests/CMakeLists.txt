cmake_minimum_required(VERSION 3.14)
project(Tests)

set(CMAKE_CXX_STANDARD 11)

# sources
file(GLOB SOURCES
        *.cpp
        ${Sort_INCLUDE_DIRS}/*.cpp
        ${Bit_INCLUDE_DIRS}/*.cpp
        ${Search_INCLUDE_DIRS}/*/*.cpp
        ${Different_INCLUDE_DIRS}/*/*.cpp
        ${Arrays_INCLUDE_DIRS}/*.cpp
        )
message("TEST SOURCES = ${SOURCES}")


# executable
find_package(GTest REQUIRED)
add_executable(${PROJECT_NAME} ${SOURCES} ${Common_INCLUDES})
target_include_directories(${PROJECT_NAME} PUBLIC
        ${Sort_INCLUDE_DIRS}
        ${Bit_INCLUDE_DIRS}
        ${Search_INCLUDE_DIRS}/BinarySearch
        ${Search_INCLUDE_DIRS}/LinearSearch
        ${Arrays_INCLUDE_DIRS}
        ${Different_INCLUDE_DIRS}/KStatSearchDC
        ${Common_INCLUDE_DIRS}
        )
message(${Different_INCLUDE_DIRS}/KStatSearchDC)
target_link_libraries(${PROJECT_NAME} GTest::gtest_main)

gtest_discover_tests(${PROJECT_NAME})