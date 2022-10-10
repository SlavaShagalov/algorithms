cmake_minimum_required(VERSION 3.0.0)
project(algorithms VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(algorithmsConfig.h.in algorithmsConfig.h)

add_executable(${PROJECT_NAME} main.cpp)

# old
# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov" )
# target_include_directories(${PROJECT_NAME} PUBLIC ${FIB_LIB_INCLUDE_DIRS})
# target_link_libraries(${PROJECT_NAME} PRIVATE ${FIB_LIB_LIBRARIES})
# add_subdirectory(utils)
# add_subdirectory(tests)

target_include_directories(${PROJECT_NAME} PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
